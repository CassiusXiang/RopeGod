#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QMessageBox>
#include <QButtonGroup>
#include <QTcpSocket>
#include <QHostAddress>
#include <QRegExp>
#include <QtCharts>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QTimer timer_1;
    QTimer timer_plot;

private:
    Ui::MainWindow *ui;
    void serialportscan();
    QSerialPort *serial;
    void SerialReciveMsg();
    void SerialSendMsg(double current_voltage, double current_max_current);
    void ControlAngle(uint8_t id, uint16_t angle);
    void GetPressure(uint8_t id);
    void charpointupdate();
    bool comflag;
    bool idsetflag;
    int pressure[12];
    QByteArray serialBuffer;
    void setcanid();
    int pressureMotion[4];

    // Chart
    void charinit();

    int xrange;
    int time_tick;

    // finger
    QChartView *MyChartViewFinger1;
    QChart MyChartFinger1;
    QSplineSeries *pressure1;
    QSplineSeries *pressure2;
    QSplineSeries *pressure3;
    QSplineSeries *pressure4;
    QSplineSeries *pressure5;
    QSplineSeries *pressure6;
    QSplineSeries *pressure7;
    QSplineSeries *pressure8;
    QSplineSeries *pressure9;
    QSplineSeries *pressure10;
    QSplineSeries *pressure11;
    QSplineSeries *pressure12;

    QValueAxis pressure1X;
    QValueAxis pressure1Y;
    QValueAxis pressure2Y;
    QValueAxis pressure3Y;
    QValueAxis pressure4Y;
    QValueAxis pressure5Y;
    QValueAxis pressure6Y;
    QValueAxis pressure7Y;
    QValueAxis pressure8Y;
    QValueAxis pressure9Y;
    QValueAxis pressure10Y;
    QValueAxis pressure11Y;
    QValueAxis pressure12Y;

    uint16_t servo_angle[8];




private slots:
    bool serialopen();
    void reset();

    void setid();

    void onSliderMoved(int value);
};

#endif // MAINWINDOW_H
