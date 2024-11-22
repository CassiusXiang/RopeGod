/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <QtCharts/QChartView>

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
    QPushButton *pushButton;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_8;
    QComboBox *comboBox;
    QGroupBox *groupBox_3;
    QtCharts::QChartView *chart;
    QPushButton *pushButton_2;
    QLabel *display;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1121, 759);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName("centralWidget");
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(10, 10, 391, 251));
        layoutWidget = new QWidget(groupBox);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(10, 20, 371, 164));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        label = new QLabel(layoutWidget);
        label->setObjectName("label");

        horizontalLayout_5->addWidget(label);

        finger1 = new QSlider(layoutWidget);
        finger1->setObjectName("finger1");
        finger1->setOrientation(Qt::Horizontal);

        horizontalLayout_5->addWidget(finger1);

        checkBox_1 = new QCheckBox(layoutWidget);
        checkBox_1->setObjectName("checkBox_1");

        horizontalLayout_5->addWidget(checkBox_1);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName("label_2");

        horizontalLayout_4->addWidget(label_2);

        finger2 = new QSlider(layoutWidget);
        finger2->setObjectName("finger2");
        finger2->setOrientation(Qt::Horizontal);

        horizontalLayout_4->addWidget(finger2);

        checkBox_2 = new QCheckBox(layoutWidget);
        checkBox_2->setObjectName("checkBox_2");

        horizontalLayout_4->addWidget(checkBox_2);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName("label_3");

        horizontalLayout_3->addWidget(label_3);

        finger3 = new QSlider(layoutWidget);
        finger3->setObjectName("finger3");
        finger3->setOrientation(Qt::Horizontal);

        horizontalLayout_3->addWidget(finger3);

        checkBox_3 = new QCheckBox(layoutWidget);
        checkBox_3->setObjectName("checkBox_3");

        horizontalLayout_3->addWidget(checkBox_3);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName("label_4");

        horizontalLayout_2->addWidget(label_4);

        finger4 = new QSlider(layoutWidget);
        finger4->setObjectName("finger4");
        finger4->setOrientation(Qt::Horizontal);

        horizontalLayout_2->addWidget(finger4);

        checkBox_4 = new QCheckBox(layoutWidget);
        checkBox_4->setObjectName("checkBox_4");

        horizontalLayout_2->addWidget(checkBox_4);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName("horizontalLayout");
        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName("label_5");

        horizontalLayout->addWidget(label_5);

        finger5 = new QSlider(layoutWidget);
        finger5->setObjectName("finger5");
        finger5->setOrientation(Qt::Horizontal);

        horizontalLayout->addWidget(finger5);

        checkBox_5 = new QCheckBox(layoutWidget);
        checkBox_5->setObjectName("checkBox_5");

        horizontalLayout->addWidget(checkBox_5);


        verticalLayout->addLayout(horizontalLayout);

        layoutWidget1 = new QWidget(groupBox);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(10, 190, 371, 56));
        verticalLayout_2 = new QVBoxLayout(layoutWidget1);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        label_6 = new QLabel(layoutWidget1);
        label_6->setObjectName("label_6");

        horizontalLayout_7->addWidget(label_6);

        sizhi = new QSlider(layoutWidget1);
        sizhi->setObjectName("sizhi");
        sizhi->setOrientation(Qt::Horizontal);

        horizontalLayout_7->addWidget(sizhi);


        verticalLayout_2->addLayout(horizontalLayout_7);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        label_7 = new QLabel(layoutWidget1);
        label_7->setObjectName("label_7");

        horizontalLayout_6->addWidget(label_7);

        damuzhi = new QSlider(layoutWidget1);
        damuzhi->setObjectName("damuzhi");
        damuzhi->setOrientation(Qt::Horizontal);

        horizontalLayout_6->addWidget(damuzhi);


        verticalLayout_2->addLayout(horizontalLayout_6);

        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setGeometry(QRect(10, 270, 251, 61));
        pushButton = new QPushButton(groupBox_2);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(160, 20, 75, 23));
        layoutWidget2 = new QWidget(groupBox_2);
        layoutWidget2->setObjectName("layoutWidget2");
        layoutWidget2->setGeometry(QRect(10, 20, 141, 22));
        horizontalLayout_8 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_8->setObjectName("horizontalLayout_8");
        horizontalLayout_8->setContentsMargins(0, 0, 0, 0);
        label_8 = new QLabel(layoutWidget2);
        label_8->setObjectName("label_8");

        horizontalLayout_8->addWidget(label_8);

        comboBox = new QComboBox(layoutWidget2);
        comboBox->setObjectName("comboBox");

        horizontalLayout_8->addWidget(comboBox);

        groupBox_3 = new QGroupBox(centralWidget);
        groupBox_3->setObjectName("groupBox_3");
        groupBox_3->setGeometry(QRect(410, 10, 701, 691));
        chart = new QtCharts::QChartView(groupBox_3);
        chart->setObjectName("chart");
        chart->setGeometry(QRect(10, 20, 681, 661));
        chart->setMinimumSize(QSize(0, 281));
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(270, 290, 121, 23));
        display = new QLabel(centralWidget);
        display->setObjectName("display");
        display->setGeometry(QRect(50, 340, 321, 361));
        display->setPixmap(QPixmap(QString::fromUtf8("release/fig/demo.png")));
        display->setScaledContents(true);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 1121, 23));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName("mainToolBar");
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName("statusBar");
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "\347\201\265\345\267\247\346\211\213\346\216\247\345\210\266", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\346\211\213\346\214\2071", nullptr));
        checkBox_1->setText(QString());
        label_2->setText(QCoreApplication::translate("MainWindow", "\346\211\213\346\214\2072", nullptr));
        checkBox_2->setText(QString());
        label_3->setText(QCoreApplication::translate("MainWindow", "\346\211\213\346\214\2073", nullptr));
        checkBox_3->setText(QString());
        label_4->setText(QCoreApplication::translate("MainWindow", "\346\211\213\346\214\2074", nullptr));
        checkBox_4->setText(QString());
        label_5->setText(QCoreApplication::translate("MainWindow", "\346\211\213\346\214\2075", nullptr));
        checkBox_5->setText(QString());
        label_6->setText(QCoreApplication::translate("MainWindow", "\345\233\233\346\214\207\344\276\247\346\221\206", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "\345\244\247\346\213\207\346\214\207\344\276\247\346\221\206", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "\346\216\247\345\210\266\345\231\250\350\277\236\346\216\245", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "\350\277\236\346\216\245", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "\344\270\262\345\217\243\345\217\267", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("MainWindow", "\346\211\213\346\214\207\345\216\213\345\212\233\346\225\260\346\215\256", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "\345\244\215\344\275\215", nullptr));
        display->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
