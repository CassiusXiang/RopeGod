#include "WzSerialPort.h"
#include "mrh5.h"
#include <thread>
#include <chrono>
#include <iostream>
#include <cstring>

const char *SERIAL_PORT = "COM4";
const char *SERIAL_PORT_DEBUG = "COM9";

int main()
{
    // 初始化串口结构体
    WzSerialPort w;
    WzSerialPort wDebug;
    if (w.open(SERIAL_PORT, 115200, 0, 8, 1))
    {
    }
    else
    {
        std::cout << "open serial Failed!" << std::endl;
    }
    // if (wDebug.open(SERIAL_PORT_DEBUG, 115200, 0, 8, 1))
    // {
    // }
    // else
    // {
    //     std::cout << "open serial Failed!" << std::endl;
    // }
    mrh5 mr1(w, 32, 33); // 32->主控板CANID 33-> 传感器CANID

    while (true)
    {
        mr1.core_mrh5();
        std::cout << mr1.get_pressure(0) << "|"; // g
        std::cout << mr1.get_pressure(1) << "|";
        std::cout << mr1.get_pressure(2) << "|";
        std::cout << mr1.get_pressure(3) << "|";
        std::cout << mr1.get_pressure(4) << "|";
        std::cout << mr1.get_pressure(5) << "|" << std::endl;
        mr1.set_servo_position(2, 10); // 2->食指
        // char buf[16];
        // memset(buf, 0, 16);
        // w.receive(buf, 16);
        // wDebug.send(buf, 16);
        // std::this_thread::sleep_for(std::chrono::milliseconds(100)); // 运行周期: 100Hz
    }
}