/********************************************************************************
** Form generated from reading UI file 'main.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef TELE_MAINWINDOW_H
#define TELE_MAINWINDOW_H

#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include "turtlesim/Color.h"
#include "turtlesim/Pose.h"

#include <QtCore/QVariant>
#include <QtCore/QString>
#include <QtCore/QTimer>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QShortcut>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Tele_MainWindow {
    /** 基类Tele_MainWindow \n
     * QT Designer设计界面*.ui文件 \n
     * 然后通过uic工具转换成*.h文件 \n
     * 在此基础上修改并增加代码
     * */
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QSlider *horizontalSlider;
    QPushButton *pushButton;
    QPushButton *pushButton_3;
    QSlider *horizontalSlider_2;
    QPushButton *pushButton_2;
    QPushButton *pushButton_4;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->setFixedSize(750, 250);
        MainWindow->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_2, 0, 0, 1, 1);

        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label, 0, 1, 1, 1);

        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_3, 0, 2, 1, 1);

        horizontalSlider = new QSlider(centralwidget);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setMinimum(1);
        horizontalSlider->setMaximum(100);
        horizontalSlider->setSliderPosition(50);
        horizontalSlider->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(horizontalSlider, 1, 0, 1, 1);

        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout->addWidget(pushButton, 1, 1, 1, 1);

        horizontalSlider_2 = new QSlider(centralwidget);
        horizontalSlider_2->setObjectName(QString::fromUtf8("horizontalSlider_2"));
        horizontalSlider_2->setMinimum(1);
        horizontalSlider_2->setMaximum(100);
        horizontalSlider_2->setSliderPosition(50);
        horizontalSlider_2->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(horizontalSlider_2, 1, 2, 1, 1);

        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        gridLayout->addWidget(pushButton_3, 2, 0, 1, 1);

        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        gridLayout->addWidget(pushButton_2, 2, 1, 1, 1);

        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));

        gridLayout->addWidget(pushButton_4, 2, 2, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));

        statusbar->showMessage(QString("Pose:(x,y,z,phi,theta,psi)"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "TeleOp", nullptr));
        pushButton->setText(QApplication::translate("MainWindow", "W", nullptr));
        pushButton_3->setText(QApplication::translate("MainWindow", "A", nullptr));
        pushButton_2->setText(QApplication::translate("MainWindow", "S", nullptr));
        pushButton_4->setText(QApplication::translate("MainWindow", "D", nullptr));
        label->setText(QApplication::translate("MainWindow", "Twist:(x,y,z,phi,theta,psi)", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "\347\272\277\351\200\237\345\272\246", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "\350\247\222\351\200\237\345\272\246", nullptr));

#ifndef QT_NO_SHORTCUT
        pushButton->setShortcut(QApplication::translate("MainWindow", "W", nullptr));
        pushButton_3->setShortcut(QApplication::translate("MainWindow", "A", nullptr));
        pushButton_2->setShortcut(QApplication::translate("MainWindow", "S", nullptr));
        pushButton_4->setShortcut(QApplication::translate("MainWindow", "D", nullptr));
#endif // QT_NO_SHORTCUT
    } // retranslateUi

};

namespace Tele {
    class MainWindow: public Tele_MainWindow, public QMainWindow {
        /** 派生类Ui::MainWindow \n
         * (多重)继承于Ui_MainWindow和QMainWindow
         * */
    public:
        double k_;
        double v_lx_, v_az_; // velocity of linear x-axis, angular z-axis

        ros::NodeHandle nh_;
        ros::Publisher cmd_pub_;
        ros::Subscriber color_sub_, pose_sub_;

        QShortcut* up_sc_;
        QShortcut* down_sc_;
        QShortcut* left_sc_;
        QShortcut* right_sc_;
        QTimer* update_timer_;


        /* 构造函数 */
        explicit MainWindow(const ros::NodeHandle &nh);

        /* 信号(signal)函数 */
        void connectUi();

    private:
        /* 槽(slot)函数 */
        void pubTwist(double k_lx, double k_az);

        /* 回调函数 */
        void colorCallback(const turtlesim::ColorConstPtr &color);
        void poseCallback(const turtlesim::PoseConstPtr &pose);

    };

} // namespace Tele

QT_END_NAMESPACE

#endif // TELE_MAINWINDOW_H
