#ifndef MRH5_H
#define MRH5_H

#include "WzSerialPort.h" // 引入 WZSerialPort 的定义
#include <string>
#include <iostream>

class mrh5
{
private:
    bool chirality; // 手性: 0 右手，1 左手
    int id;
    int controlId;
    int pressureId;
    int pressure[12];

    char buf[32];

    WzSerialPort serial; // 串口对象

public:
    /**
     * @parma
     * serial: 连接到CAN-USB的串口号
     * controlId: 控制板ID
     * pressureId：压力采样板ID
     */
    mrh5(WzSerialPort &serial, int controlId, int pressureId);

    // 析构函数
    ~mrh5();
    /**
     * @parma
     * index: 获取压力传感器的序号
     *
     * @return: 压力数据，单位为 g
     */
    int get_pressure(int index);

    /**
     * @parma
     * index: 控制舵机的序号，0号舵机对应四指摆动，1号舵机对应大拇指侧摆，2-6分别对应大拇指、食指、中指、无名指、小拇指
     * angle: 舵机角度，0度对应手指伸直，180度对应最大弯曲
     */
    void set_servo_position(int index, float angle);

    /**
     * @discribe
     * 用于获取传感器数据，需要在循环中反复调用，决定采样频率（最高200Hz）
     */
    void core_mrh5();
};

#endif // MRH5_H
