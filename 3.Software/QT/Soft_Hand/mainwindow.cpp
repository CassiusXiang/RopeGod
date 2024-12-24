#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("灵巧手控制台");
//    QImage demoHand("./fig/demo.png");
//    QPixmap pixmap = QPixmap::fromImage(demoHand);
//    ui->display->setPixmap(pixmap);

    serialportscan();
    comflag = 0;
    idsetflag = 0;
    for(int i = 0; i < 8; i++){
        servo_angle[i] = 500;
    }
    for(int i = 0; i < 12; i++){
        pressure[i] = 0;
    }
    for(int i = 0; i < 4; i++){
        pressureMotion[i] = 0;
    }
//    uint8_t pressure_it = 1;
    time_tick = 0;
    xrange = 400;
    uint8_t its = 0;
    uint8_t itp = 0;
    charinit();

    QPushButton *button3 = ui->pushButton_3;
    QPushButton *button4 = ui->pushButton_4;
    QPushButton *button5 = ui->pushButton_5;
    QPushButton *button12 = ui->pushButton_12;
    QPushButton *button7 = ui->pushButton_7;

    QProgressBar *bar3 = ui->progressBar_3;
    QProgressBar *bar4 = ui->progressBar_10;

    // 创建按钮组并设置互斥
    QButtonGroup *buttonGroup = new QButtonGroup(this);
    buttonGroup->setExclusive(true);

    // 设置按钮为可切换状态（checkable）
    button3->setCheckable(true);
    button4->setCheckable(true);
    button5->setCheckable(true);
    button12->setCheckable(true);
    button7->setCheckable(true);

    // 添加按钮到组
    buttonGroup->addButton(button3);
    buttonGroup->addButton(button4);
    buttonGroup->addButton(button5);
    buttonGroup->addButton(button12);
    buttonGroup->addButton(button7);

    // 设置按钮的样式表（QSS）
    // 未按下时是默认颜色，按下时背景变为绿色
    QString buttonStyle = R"(
        QPushButton {
            background-color: white;
            border: 1px solid gray;
            border-radius: 4px;
            padding: 4px;
        }
        QPushButton:checked {
            background-color: #CCFFCC; /* 淡绿色 */
            color: black;
        }
    )";
    button3->setStyleSheet(buttonStyle);
    button4->setStyleSheet(buttonStyle);
    button5->setStyleSheet(buttonStyle);
    button12->setStyleSheet(buttonStyle);
    button7->setStyleSheet(buttonStyle);


    ui->finger1->setRange(0, 2000);
    ui->finger1->setValue(0);
    ui->finger2->setRange(0, 2000);
    ui->finger2->setValue(0);
    ui->finger3->setRange(0, 2000);
    ui->finger3->setValue(0);
    ui->finger4->setRange(0, 2000);
    ui->finger4->setValue(0);
    ui->finger5->setRange(0, 2000);
    ui->finger5->setValue(0);

    ui->damuzhi->setRange(600, 1600);
    ui->damuzhi->setValue(800);
    ui->sizhi->setRange(900, 1260);
    ui->sizhi->setValue(1000);

    ui->spinBox->setValue(20);
    ui->spinBox_2->setValue(20);
    ui->spinBox->setRange(20, 65535);
    ui->spinBox_2->setRange(20, 65535);

    ui->finger2catch->setRange(0, 1000);
    ui->finger2catch_2->setRange(0, 1000);
    ui->finger2catch_3->setRange(0, 2000);
    ui->finger2catch_10->setRange(0, 1000);
    ui->finger2catch_11->setRange(0, 1000);

    bar3->setValue(0);
    bar4->setValue(0);




    connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::serialopen);
    connect(ui->pushButton_2, &QPushButton::clicked, this, &MainWindow::reset);
//    connect(ui->pushButton_3, &QPushButton::clicked, this, &MainWindow::setcanid);
    connect(ui->pushButton_6, &QPushButton::clicked, this, &MainWindow::setid);
    connect(&timer_1, &QTimer::timeout, [&](){
        // When timer timeout
        servo_angle[0] = static_cast<uint16_t>(ui->sizhi->value());
        servo_angle[1] = static_cast<uint16_t>(ui->damuzhi->value());
        servo_angle[2] = static_cast<uint16_t>(ui->finger1->value());
        servo_angle[3] = static_cast<uint16_t>(ui->finger2->value());
        servo_angle[4] = static_cast<uint16_t>(ui->finger3->value());
        servo_angle[5] = static_cast<uint16_t>(ui->finger4->value());
        servo_angle[6] = static_cast<uint16_t>(ui->finger5->value());

//        for(uint8_t i = 0; i < 7; i++){
        if(idsetflag){
            setcanid();
            idsetflag = 0;
        }
        else{
            ControlAngle(its, servo_angle[its]);
        }
//        }
//        for(uint8_t i = 0; i < 6; i++){
//            GetPressure(itp);
//        }
            its = (its + 1)%7;
            itp = (itp + 1)%6;
    });

    connect(&timer_plot, &QTimer::timeout, [&](){
        // When timer timeout
        charpointupdate();

        ui->lcdNumber_11->display(ui->finger1->value());
        ui->lcdNumber_12->display(ui->finger2->value());
        ui->lcdNumber_13->display(ui->finger3->value());
        ui->lcdNumber_14->display(ui->finger4->value());
        ui->lcdNumber_15->display(ui->finger5->value());
        ui->lcdNumber_16->display(ui->damuzhi->value());
        ui->lcdNumber_17->display(ui->sizhi->value());


        pressureMotion[0] = pressure[0] + pressure[1];
        pressureMotion[1] = pressure[1] + pressure[2];
        pressureMotion[2] = pressure[0] + pressure[1] + pressure[2] + pressure[3] + pressure[4];
        pressureMotion[3] = pressure[0] + pressure[1] + pressure[2] + pressure[3] + pressure[4];

        ui->lcdNumber->display(pressureMotion[0]);
        ui->lcdNumber_2->display(pressureMotion[1]);
        ui->lcdNumber_3->display(pressureMotion[2]);





        if(ui->pushButton_3->isChecked()){
            ui->damuzhi->setValue(1093);
            int target = ui->finger2catch->value();
            ui->finger1->setValue(static_cast<int>(target*0.618));
            ui->finger2->setValue(static_cast<int>(target*1.481));
        } else if(ui->pushButton_4->isChecked()){
            int target2 = ui->finger2catch_2->value();
            ui->finger2->setValue(359);
            ui->finger3->setValue(353);
            ui->sizhi->setValue(800 + static_cast<int>(target2*0.46));
        } else if(ui->pushButton_5->isChecked()){
            int target3 = ui->finger2catch_3->value();
            int successp = pressureMotion[2]/6;
            ui->finger1->setValue(target3);
            ui->finger2->setValue(target3);
            ui->finger3->setValue(target3);
            ui->finger4->setValue(target3);
            ui->finger5->setValue(target3);
            if(successp > 100){
                successp = 100;
            }
            ui->progressBar_3->setValue(successp);
        } else if(ui->pushButton_12->isChecked()){
            int target4 = ui->finger2catch_10->value();
            int target5 = ui->finger2catch_11->value();
            ui->sizhi->setValue(1116);
            ui->damuzhi->setValue(1330);
            ui->finger1->setValue(static_cast<int>(target4*0.800));
            ui->finger2->setValue(static_cast<int>(target5*2));
            ui->finger3->setValue(static_cast<int>(target4*0.324));
            ui->finger4->setValue(static_cast<int>(target4*1.982));
            ui->finger5->setValue(static_cast<int>(target4*1.982));
        }

    });

    // Connect sliderMoved signals to update other sliders when synced
    connect(ui->finger1, &QSlider::sliderMoved, this, &MainWindow::onSliderMoved);
    connect(ui->finger2, &QSlider::sliderMoved, this, &MainWindow::onSliderMoved);
    connect(ui->finger3, &QSlider::sliderMoved, this, &MainWindow::onSliderMoved);
    connect(ui->finger4, &QSlider::sliderMoved, this, &MainWindow::onSliderMoved);
    connect(ui->finger5, &QSlider::sliderMoved, this, &MainWindow::onSliderMoved);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::serialportscan(){
    foreach(const QSerialPortInfo &info, QSerialPortInfo::availablePorts()){
        QSerialPort ser;
        ser.setPort(info);
        if(ser.open(QIODevice::ReadWrite)){
            ui->comboBox->addItem(ser.portName());
            ser.close();
        }
    }
}

bool MainWindow::serialopen(){ // Yellow:GND. Black:RX. Red:TX
    serial = new QSerialPort;
    serial->setPortName(ui->comboBox->currentText());
    serial->setBaudRate(QSerialPort::Baud115200);
    serial->setDataBits(QSerialPort::Data8);
    serial->setParity(QSerialPort::NoParity);
    serial->setStopBits(QSerialPort::OneStop);
    serial->setFlowControl(QSerialPort::NoFlowControl);
    serial->open(QIODevice::ReadWrite);
    if(serial->isOpen()){
//        QMessageBox::about(this, tr("串口连接"), tr("连接成功"));
        ui->pushButton->setText("已连接");
        comflag = 1;
        connect(serial, &QSerialPort::readyRead, this, &MainWindow::SerialReciveMsg);
//        ControlAngle(1, 500);
        return true;
    }
    else {
        return false;
    }
}

void MainWindow::SerialReciveMsg(){
    QByteArray buf = serial->readAll();
    serialBuffer.append(buf);

    while (serialBuffer.size() >= 16) { // 当缓冲区中至少有一个完整的数据帧
        // 查找帧的起始位置（0xAA）
        int startIndex = serialBuffer.indexOf(static_cast<char>(0xAA));
        if (startIndex == -1) {
            // 如果没有找到起始标识，清空缓冲区
            serialBuffer.clear();
//            qDebug() << "Error: No start byte (0xAA) found. Buffer cleared.";
            return;
        }

        // 如果起始标识不是在第一个位置，移除之前的数据
        if (startIndex > 0) {
            serialBuffer.remove(0, startIndex);
//            qDebug() << "Info: Discarding" << startIndex << "bytes before start byte (0xAA).";
        }

        // 检查缓冲区中是否有足够的数据帧
        if (serialBuffer.size() < 16) {
            // 数据不完整，等待下次接收
            return;
        }

        // 检查第16字节是否为结束标识0x00
        if (static_cast<uint8_t>(serialBuffer.at(15)) != 0x00) {
//            qDebug() << "Error: Frame does not end with 0x00. Discarding first byte.";
            serialBuffer.remove(0, 1); // 移除第一个字节，重新寻找起始字节
            continue;
        }

        // 提取一个完整的数据帧
        QByteArray frame = serialBuffer.left(16);
        serialBuffer.remove(0, 16); // 移除已处理的帧

        // 解析数据帧
        QVector<uint8_t> hexValues;
        for (int i = 0; i < frame.size(); ++i) {
            hexValues.append(static_cast<uint8_t>(frame.at(i)));
        }

        // 打印接收到的数据帧（十六进制）
        QString hexString;
        for (uint8_t val : hexValues) {
            hexString.append(QString::number(val, 16).rightJustified(2, '0').toUpper() + " ");
        }
//        qDebug() << "Received hex values:" << hexString.trimmed();

        // 解析 ID 和压力值
        uint16_t reciveId = static_cast<uint16_t>((hexValues[6] << 8) + hexValues[7]);
        uint16_t compareId = 2047 - static_cast<uint16_t>(ui->spinBox_2->value()); // 压力消息帧的 ID

        // 校验帧头、帧类型和 ID
        if (hexValues[0] == 0xAA && hexValues[3] == 0x08 && reciveId == compareId) {
            uint8_t pressureId = hexValues[8];
            if (pressureId >= 12) { // 确保 pressureId 不超过数组范围
//                qDebug() << "Error: Invalid pressureId" << pressureId;
                continue;
            }
            uint16_t pressureValue = static_cast<uint16_t>((hexValues[9] << 8) + hexValues[10]);
            pressure[pressureId] = 4000000/(pressureValue + 1) - 1000;
//            pressure[pressureId] = pressureValue;
//            qDebug() << "Pressure ID:" << pressureId << "Value:" << pressureValue;
        }
        else {
//            qDebug() << "Error: Invalid frame format or ID mismatch.";
        }
    }
}

void MainWindow::ControlAngle(uint8_t id, uint16_t angle){
    uint8_t data[16];
    uint16_t boardId = static_cast<uint16_t>(ui->spinBox->value());
    if(comflag){
        data[0] = 0xAA;
        data[1] = 0x00;
        data[2] = 0x00;
        data[3] = 0x08;

        data[4] = 0x00;
        data[5] = 0x00;
        data[6] = (boardId >> 8);
        data[7] = boardId & 0xFF;

        data[8] = 0x01;
        data[9] = id & 0xFF;
        data[10] = (angle >> 8);
        data[11] = angle & 0xFF;

        data[12] = 0x00;
        data[13] = 0x00;
        data[14] = 0x00;
        data[15] = 0x00;
//        QByteArray byteArray(reinterpret_cast<const char*>(data), sizeof(data));
//        qDebug() << "Data array (hex):" << byteArray.toHex(' ');
        serial->write(reinterpret_cast<char*>(data), sizeof(data));
    }
}

void MainWindow::GetPressure(uint8_t id){
    uint8_t data[16];
    uint16_t boardId = static_cast<uint16_t>(ui->spinBox_2->value());
//    uint16_t pressureId = 65535 - boardId;
    if(comflag){
        data[0] = 0xAA;
        data[1] = 0x00;
        data[2] = 0x00;
        data[3] = 0x08;

        data[4] = 0x00;
        data[5] = 0x00;
        data[6] = (boardId >> 8);
        data[7] = boardId & 0xFF;

        data[8] = 0x01;
        data[9] = id & 0xFF;
        data[10] = 0x00;
        data[11] = 0x00;

        data[12] = 0x00;
        data[13] = 0x00;
        data[14] = 0x00;
        data[15] = 0x00;
        serial->write(reinterpret_cast<char*>(data), sizeof(data));
    }
}

void MainWindow::charinit(){
    MyChartViewFinger1 = ui->chart;
    MyChartViewFinger1->setChart(&MyChartFinger1);
    pressure1 = new QSplineSeries(this);
    pressure2 = new QSplineSeries(this);
    pressure3 = new QSplineSeries(this);
    pressure4 = new QSplineSeries(this);
    pressure5 = new QSplineSeries(this);
    pressure6 = new QSplineSeries(this);
    pressure7 = new QSplineSeries(this);
    pressure8 = new QSplineSeries(this);
    pressure9 = new QSplineSeries(this);
    pressure10 = new QSplineSeries(this);
    pressure11 = new QSplineSeries(this);
    pressure12 = new QSplineSeries(this);

    MyChartFinger1.addSeries(pressure1);
    MyChartFinger1.addSeries(pressure2);
    MyChartFinger1.addSeries(pressure3);
    MyChartFinger1.addSeries(pressure4);
    MyChartFinger1.addSeries(pressure5);
    MyChartFinger1.addSeries(pressure6);
    MyChartFinger1.addSeries(pressure7);
    MyChartFinger1.addSeries(pressure8);
    MyChartFinger1.addSeries(pressure9);
    MyChartFinger1.addSeries(pressure10);
    MyChartFinger1.addSeries(pressure11);

    pressure1->setName("拇指压力");
    pressure2->setName("食指压力");
    pressure3->setName("中指压力");
    pressure4->setName("无名指压力");
    pressure5->setName("小指压力");
    pressure6->setName("掌心压力");
//    pressure7->setName("拇指肚压力");
//    pressure8->setName("食指肚压力");
//    pressure9->setName("中指肚压力");
//    pressure10->setName("无名指肚压力");
//    pressure11->setName("小指肚压力");

    MyChartFinger1.addAxis(&pressure1X, Qt::AlignBottom);
    MyChartFinger1.addAxis(&pressure1Y, Qt::AlignLeft);

    pressure1Y.setTitleText("压力/g");
    pressure1Y.setRange(0, 500);
    pressure1X.setRange(0, xrange);

    pressure1->attachAxis(&pressure1X);
    pressure1->attachAxis(&pressure1Y);
    pressure2->attachAxis(&pressure1X);
    pressure2->attachAxis(&pressure1Y);
    pressure3->attachAxis(&pressure1X);
    pressure3->attachAxis(&pressure1Y);
    pressure4->attachAxis(&pressure1X);
    pressure4->attachAxis(&pressure1Y);
    pressure5->attachAxis(&pressure1X);
    pressure5->attachAxis(&pressure1Y);
    pressure6->attachAxis(&pressure1X);
    pressure6->attachAxis(&pressure1Y);
    pressure7->attachAxis(&pressure1X);
    pressure7->attachAxis(&pressure1Y);
    pressure8->attachAxis(&pressure1X);
    pressure8->attachAxis(&pressure1Y);
    pressure9->attachAxis(&pressure1X);
    pressure9->attachAxis(&pressure1Y);
    pressure10->attachAxis(&pressure1X);
    pressure10->attachAxis(&pressure1Y);
    pressure11->attachAxis(&pressure1X);
    pressure11->attachAxis(&pressure1Y);

    pressure1->setColor(Qt::red);
    pressure7->setColor(Qt::red);
    pressure2->setColor(Qt::darkGreen);
    pressure8->setColor(Qt::darkGreen);
    pressure3->setColor(Qt::blue);
    pressure9->setColor(Qt::blue);
    pressure4->setColor(Qt::darkBlue);
    pressure10->setColor(Qt::darkBlue);
    pressure5->setColor(Qt::cyan);
    pressure11->setColor(Qt::cyan);
    pressure6->setColor(Qt::magenta);
}

void MainWindow::charpointupdate(){
    // 添加新数据点
    pressure1->append(time_tick, pressure[0]);
    pressure2->append(time_tick, pressure[1]);
    pressure3->append(time_tick, pressure[2]);
    pressure4->append(time_tick, pressure[3]);
    pressure5->append(time_tick, pressure[4]);
    pressure6->append(time_tick, pressure[5]);
    pressure7->append(time_tick, pressure[6]);
    pressure8->append(time_tick, pressure[7]);
    pressure9->append(time_tick, pressure[8]);
    pressure10->append(time_tick, pressure[9]);
    pressure11->append(time_tick, pressure[10]);

    // 检查并更新 x 轴范围
    if(time_tick > xrange) {
        pressure1X.setRange(time_tick - xrange, time_tick);

        // 定义一个 lambda 函数来清理旧数据
        auto removeOldData = [this](QSplineSeries* series) {
            int removeCount = 0;
            while (removeCount < series->count() && series->at(removeCount).x() < (time_tick - xrange)) {
                ++removeCount;
            }
            if (removeCount > 0) {
                series->removePoints(0, removeCount);
            }
        };

        // 清理每个压力系列的旧数据
        removeOldData(pressure1);
        removeOldData(pressure2);
        removeOldData(pressure3);
        removeOldData(pressure4);
        removeOldData(pressure5);
        removeOldData(pressure6);
        removeOldData(pressure7);
        removeOldData(pressure8);
        removeOldData(pressure9);
        removeOldData(pressure10);
        removeOldData(pressure11);
    }

    // 增加时间刻度
//    time_tick = (time_tick + 1) % 50000;
    ++time_tick;
    if(time_tick % 10000 == 0 && comflag == 1){
        serial->close();
        comflag = 0;
        serialopen();
        qDebug() << "reset success";
    }
}


void MainWindow::reset(){
    ui->finger1->setValue(0);
    ui->finger2->setValue(0);
    ui->finger3->setValue(0);
    ui->finger4->setValue(0);
    ui->finger5->setValue(0);
    ui->damuzhi->setValue(800);
    ui->sizhi->setValue(1000);
}

void MainWindow::onSliderMoved(int value) {
    QSlider* senderSlider = qobject_cast<QSlider*>(sender());
    if (senderSlider == nullptr) return;
    if (    (senderSlider == ui->finger1 && ui->checkBox_1->isChecked()) ||
            (senderSlider == ui->finger2 && ui->checkBox_2->isChecked()) ||
            (senderSlider == ui->finger3 && ui->checkBox_3->isChecked()) ||
            (senderSlider == ui->finger4 && ui->checkBox_4->isChecked()) ||
            (senderSlider == ui->finger5 && ui->checkBox_5->isChecked())
            ) {
        if (ui->checkBox_1->isChecked()) {
            ui->finger1->setValue(value);
        }
        if (ui->checkBox_2->isChecked()) {
            ui->finger2->setValue(value);
        }
        if (ui->checkBox_3->isChecked()) {
            ui->finger3->setValue(value);
        }
        if (ui->checkBox_4->isChecked()) {
            ui->finger4->setValue(value);
        }
        if (ui->checkBox_5->isChecked()) {
            ui->finger5->setValue(value);
        }
    }

}

void MainWindow::setcanid(){
    uint8_t data[16];
    uint16_t pressureBoardId = static_cast<uint16_t>(ui->spinBox_3->value());
    uint16_t ctrlBoardId = static_cast<uint16_t>(ui->spinBox_4->value());
//    uint16_t pressureId = 65535 - boardId;
    if(comflag){
        qDebug() << "id setting";
        data[0] = 0xAA;
        data[1] = 0x00;
        data[2] = 0x00;
        data[3] = 0x08;

        data[4] = 0x00;
        data[5] = 0x00;
        data[6] = 0x00;
        data[7] = 0xFF;

        data[8] = 0x00;
        data[9] = (pressureBoardId >> 8);
        data[10] = pressureBoardId & 0xFF;
        data[11] = 0x00;

        data[12] = 0x00;
        data[13] = 0x00;
        data[14] = 0x00;
        data[15] = 0x00;
        serial->write(reinterpret_cast<char*>(data), sizeof(data));

        data[0] = 0xAA;
        data[1] = 0x00;
        data[2] = 0x00;
        data[3] = 0x08;

        data[4] = 0x00;
        data[5] = 0x00;
        data[6] = 0x00;
        data[7] = 0x00;

        data[8] = 0x00;
        data[9] = (ctrlBoardId >> 8);
        data[10] = ctrlBoardId & 0xFF;
        data[11] = 0x00;

        data[12] = 0x00;
        data[13] = 0x00;
        data[14] = 0x00;
        data[15] = 0x00;
        serial->write(reinterpret_cast<char*>(data), sizeof(data));
    }
}

void MainWindow::setid(){
    idsetflag = 1;
}
