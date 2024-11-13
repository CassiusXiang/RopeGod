/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <qchartview.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGroupBox *groupBox;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label;
    QSlider *finger1;
    QCheckBox *checkBox_1;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_2;
    QSlider *finger2;
    QCheckBox *checkBox_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QSlider *finger3;
    QCheckBox *checkBox_3;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_4;
    QSlider *finger4;
    QCheckBox *checkBox_4;
    QHBoxLayout *horizontalLayout;
    QLabel *label_5;
    QSlider *finger5;
    QCheckBox *checkBox_5;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_6;
    QSlider *sizhi;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_7;
    QSlider *damuzhi;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_9;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_8;
    QComboBox *comboBox;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QGroupBox *groupBox_3;
    QtCharts::QChartView *chart;
    QLabel *display;
    QGroupBox *groupBox_4;
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout_13;
    QHBoxLayout *horizontalLayout_14;
    QLabel *label_12;
    QSpinBox *spinBox;
    QLabel *label_13;
    QSpinBox *spinBox_2;
    QLabel *label_9;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1426, 846);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 391, 251));
        QFont font;
        font.setPointSize(12);
        groupBox->setFont(font);
        layoutWidget = new QWidget(groupBox);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 20, 371, 164));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font);

        horizontalLayout_5->addWidget(label);

        finger1 = new QSlider(layoutWidget);
        finger1->setObjectName(QString::fromUtf8("finger1"));
        finger1->setOrientation(Qt::Horizontal);

        horizontalLayout_5->addWidget(finger1);

        checkBox_1 = new QCheckBox(layoutWidget);
        checkBox_1->setObjectName(QString::fromUtf8("checkBox_1"));

        horizontalLayout_5->addWidget(checkBox_1);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);

        horizontalLayout_4->addWidget(label_2);

        finger2 = new QSlider(layoutWidget);
        finger2->setObjectName(QString::fromUtf8("finger2"));
        finger2->setOrientation(Qt::Horizontal);

        horizontalLayout_4->addWidget(finger2);

        checkBox_2 = new QCheckBox(layoutWidget);
        checkBox_2->setObjectName(QString::fromUtf8("checkBox_2"));

        horizontalLayout_4->addWidget(checkBox_2);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font);

        horizontalLayout_3->addWidget(label_3);

        finger3 = new QSlider(layoutWidget);
        finger3->setObjectName(QString::fromUtf8("finger3"));
        finger3->setOrientation(Qt::Horizontal);

        horizontalLayout_3->addWidget(finger3);

        checkBox_3 = new QCheckBox(layoutWidget);
        checkBox_3->setObjectName(QString::fromUtf8("checkBox_3"));

        horizontalLayout_3->addWidget(checkBox_3);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font);

        horizontalLayout_2->addWidget(label_4);

        finger4 = new QSlider(layoutWidget);
        finger4->setObjectName(QString::fromUtf8("finger4"));
        finger4->setOrientation(Qt::Horizontal);

        horizontalLayout_2->addWidget(finger4);

        checkBox_4 = new QCheckBox(layoutWidget);
        checkBox_4->setObjectName(QString::fromUtf8("checkBox_4"));

        horizontalLayout_2->addWidget(checkBox_4);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font);

        horizontalLayout->addWidget(label_5);

        finger5 = new QSlider(layoutWidget);
        finger5->setObjectName(QString::fromUtf8("finger5"));
        finger5->setOrientation(Qt::Horizontal);

        horizontalLayout->addWidget(finger5);

        checkBox_5 = new QCheckBox(layoutWidget);
        checkBox_5->setObjectName(QString::fromUtf8("checkBox_5"));

        horizontalLayout->addWidget(checkBox_5);


        verticalLayout->addLayout(horizontalLayout);

        layoutWidget1 = new QWidget(groupBox);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 190, 371, 56));
        verticalLayout_2 = new QVBoxLayout(layoutWidget1);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_6 = new QLabel(layoutWidget1);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setFont(font);

        horizontalLayout_7->addWidget(label_6);

        sizhi = new QSlider(layoutWidget1);
        sizhi->setObjectName(QString::fromUtf8("sizhi"));
        sizhi->setOrientation(Qt::Horizontal);

        horizontalLayout_7->addWidget(sizhi);


        verticalLayout_2->addLayout(horizontalLayout_7);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_7 = new QLabel(layoutWidget1);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setFont(font);

        horizontalLayout_6->addWidget(label_7);

        damuzhi = new QSlider(layoutWidget1);
        damuzhi->setObjectName(QString::fromUtf8("damuzhi"));
        damuzhi->setOrientation(Qt::Horizontal);

        horizontalLayout_6->addWidget(damuzhi);


        verticalLayout_2->addLayout(horizontalLayout_6);

        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 270, 391, 67));
        groupBox_2->setFont(font);
        gridLayout = new QGridLayout(groupBox_2);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        label_8 = new QLabel(groupBox_2);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        horizontalLayout_8->addWidget(label_8);

        comboBox = new QComboBox(groupBox_2);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        horizontalLayout_8->addWidget(comboBox);


        horizontalLayout_9->addLayout(horizontalLayout_8);

        pushButton = new QPushButton(groupBox_2);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout_9->addWidget(pushButton);

        pushButton_2 = new QPushButton(groupBox_2);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        horizontalLayout_9->addWidget(pushButton_2);


        gridLayout->addLayout(horizontalLayout_9, 0, 0, 1, 1);

        groupBox_3 = new QGroupBox(centralWidget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(410, 10, 1001, 771));
        groupBox_3->setFont(font);
        chart = new QtCharts::QChartView(groupBox_3);
        chart->setObjectName(QString::fromUtf8("chart"));
        chart->setGeometry(QRect(10, 20, 981, 741));
        chart->setMinimumSize(QSize(0, 281));
        display = new QLabel(centralWidget);
        display->setObjectName(QString::fromUtf8("display"));
        display->setGeometry(QRect(40, 420, 321, 361));
        display->setPixmap(QPixmap(QString::fromUtf8("release/fig/demo.png")));
        display->setScaledContents(true);
        groupBox_4 = new QGroupBox(centralWidget);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setGeometry(QRect(10, 340, 391, 67));
        groupBox_4->setFont(font);
        gridLayout_2 = new QGridLayout(groupBox_4);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setSpacing(6);
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setSpacing(6);
        horizontalLayout_14->setObjectName(QString::fromUtf8("horizontalLayout_14"));
        label_12 = new QLabel(groupBox_4);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        horizontalLayout_14->addWidget(label_12);

        spinBox = new QSpinBox(groupBox_4);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));

        horizontalLayout_14->addWidget(spinBox);

        label_13 = new QLabel(groupBox_4);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        horizontalLayout_14->addWidget(label_13);

        spinBox_2 = new QSpinBox(groupBox_4);
        spinBox_2->setObjectName(QString::fromUtf8("spinBox_2"));

        horizontalLayout_14->addWidget(spinBox_2);


        horizontalLayout_13->addLayout(horizontalLayout_14);


        gridLayout_2->addLayout(horizontalLayout_13, 0, 0, 1, 1);

        label_9 = new QLabel(centralWidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(370, 760, 31, 16));
        QFont font1;
        font1.setPointSize(10);
        label_9->setFont(font1);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1426, 23));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        groupBox->setTitle(QApplication::translate("MainWindow", "\347\201\265\345\267\247\346\211\213\346\216\247\345\210\266", nullptr));
        label->setText(QApplication::translate("MainWindow", "\346\211\213\346\214\2071", nullptr));
        checkBox_1->setText(QString());
        label_2->setText(QApplication::translate("MainWindow", "\346\211\213\346\214\2072", nullptr));
        checkBox_2->setText(QString());
        label_3->setText(QApplication::translate("MainWindow", "\346\211\213\346\214\2073", nullptr));
        checkBox_3->setText(QString());
        label_4->setText(QApplication::translate("MainWindow", "\346\211\213\346\214\2074", nullptr));
        checkBox_4->setText(QString());
        label_5->setText(QApplication::translate("MainWindow", "\346\211\213\346\214\2075", nullptr));
        checkBox_5->setText(QString());
        label_6->setText(QApplication::translate("MainWindow", "\345\233\233\346\214\207\344\276\247\346\221\206", nullptr));
        label_7->setText(QApplication::translate("MainWindow", "\345\244\247\346\213\207\346\214\207\344\276\247\346\221\206", nullptr));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "\346\216\247\345\210\266\345\231\250\350\277\236\346\216\245", nullptr));
        label_8->setText(QApplication::translate("MainWindow", "\344\270\262\345\217\243\345\217\267", nullptr));
        pushButton->setText(QApplication::translate("MainWindow", "\350\277\236\346\216\245", nullptr));
        pushButton_2->setText(QApplication::translate("MainWindow", "\345\244\215\344\275\215", nullptr));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "\346\211\213\346\214\207\345\216\213\345\212\233\346\225\260\346\215\256", nullptr));
        display->setText(QString());
        groupBox_4->setTitle(QApplication::translate("MainWindow", "\347\201\265\345\267\247\346\211\213ID", nullptr));
        label_12->setText(QApplication::translate("MainWindow", "\345\205\263\350\212\202\346\216\247\345\210\266ID", nullptr));
        label_13->setText(QApplication::translate("MainWindow", "\344\274\240\346\204\237\345\231\250ID", nullptr));
        label_9->setText(QApplication::translate("MainWindow", "v2.1", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
