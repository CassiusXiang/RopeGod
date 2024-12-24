#include "mrh5.h"

int mapValue(float input, float input_min, float input_max, int output_min, int output_max)
{
    // 处理输入值超出范围的情况
    if (input < input_min)
    {
        input = input_min;
    }
    else if (input > input_max)
    {
        input = input_max;
    }

    // 线性映射
    return static_cast<int>((input - input_min) / (input_max - input_min) * (output_max - output_min) + output_min);
}

// 构造函数
mrh5::mrh5(WzSerialPort &serial, int controlId, int pressureId) : serial(serial), chirality(false), controlId(controlId), pressureId(pressureId) // 默认手性为右手
{
    for (int i = 0; i < 12; i++)
    {
        pressure[i] = 0;
    }
}

// 析构函数
mrh5::~mrh5()
{
}

void mrh5::set_servo_position(int index, float angle)
{
    char sendBuf[16];
    int angleValue = mapValue(angle, 0.0f, 180.0f, 0, 2000);

    sendBuf[0] = 0xAA;
    sendBuf[3] = 0x08;
    sendBuf[6] = controlId >> 8;
    sendBuf[7] = controlId & 0xFF;
    sendBuf[8] = 0x01;
    sendBuf[9] = index;
    sendBuf[10] = angleValue >> 8;
    sendBuf[11] = angleValue & 0xFF;
    serial.send(sendBuf, 16);
}

int mrh5::get_pressure(int index)
{
    return pressure[index];
}

void mrh5::core_mrh5()
{
    // 从串口接收数据
    int bytesReceived = serial.receive(buf, 32); // 假设这个函数返回接收到的字节数
    unsigned char uBuf[32];

    for (size_t i = 0; i < sizeof(buf); ++i)
    {
        uBuf[i] = static_cast<unsigned char>(buf[i]); // 类型转换
    }

    // 当缓冲区中的数据长度达到16字节时进行解析
    while (bytesReceived >= 16)
    {
        // 查找特定标识符0xAA
        size_t i = 0;
        bool found = false;
        for (i = 0; i < 16; ++i)
        {
            if (uBuf[i] == 0xAA)
            {
                found = true;
                // std::cout << "ok" << std::endl;
                break; // 找到标识符后退出循环
            }
        }

        if (found && (i + 16 <= bytesReceived))
        {
            int msgPressureId = 2047 - ((uBuf[i + 6] << 8) + uBuf[i + 7]); // 提取压力ID
            // std::cout << static_cast<int>(uBuf[i + 8]) << std::endl;
            // std::cout << uBuf << std::endl;
            if (msgPressureId == pressureId)
            {
                pressure[uBuf[i + 8]] = (uBuf[i + 9] << 8) + uBuf[i + 10]; // 存储压力值
                pressure[uBuf[i + 8]] = 4000000 / (pressure[uBuf[i + 8]] + 1) - 1000;
                if (pressure[uBuf[i + 8]] < 0)
                    pressure[uBuf[i + 8]] = 0;
            }

            // 移动指针，继续查找下一个数据包
            // 将未处理的数据移动到前面
            memmove(uBuf, uBuf + i + 16, bytesReceived - (i + 16)); // 将后面的数据前移
            bytesReceived -= (i + 16);                              // 更新接收到的字节数
        }
        else
        {
            break; // 没有找到完整数据包，退出循环
        }
    }
}
