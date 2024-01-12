#include "teleop/tele_mainwindow.h"

using namespace Tele;

MainWindow::MainWindow(const ros::NodeHandle &nh) : Tele_MainWindow(), nh_(nh), k_(0.03), v_lx_(1.0), v_az_(1.0) {
    cmd_pub_ = nh_.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel", 1);
    color_sub_ = nh_.subscribe("/turtle1/color_sensor", 1, &MainWindow::colorCallback, this);
    pose_sub_ = nh_.subscribe("/turtle1/pose", 1, &MainWindow::poseCallback, this);

    up_sc_ = new QShortcut(Qt::Key_Up, this);
    down_sc_ = new QShortcut(Qt::Key_Down, this);
    left_sc_ = new QShortcut(Qt::Key_Left, this);
    right_sc_ = new QShortcut(Qt::Key_Right, this);
    update_timer_ = new QTimer(this);
    update_timer_->setInterval(16);
    update_timer_->start();

    setupUi(this);
    connectUi();
}

void MainWindow::connectUi() {
    /* String-based写法 */
    connect(horizontalSlider, SIGNAL(valueChanged(int)), label_2, SLOT(setNum(int)));
    connect(horizontalSlider_2, SIGNAL(valueChanged(int)), label_3, SLOT(setNum(int)));

    /* Functor-based写法,使用lambda表达式 */
    connect(up_sc_, &QShortcut::activated, this, [this]() {
        horizontalSlider->setValue(horizontalSlider->value() + 1);
    });
    connect(down_sc_, &QShortcut::activated, this, [this]() {
        horizontalSlider->setValue(horizontalSlider->value() - 1);
    });
    connect(right_sc_, &QShortcut::activated, this, [this]() {
        horizontalSlider_2->setValue(horizontalSlider_2->value() + 1);
    });
    connect(left_sc_, &QShortcut::activated, this, [this]() {
        horizontalSlider_2->setValue(horizontalSlider_2->value() - 1);
    });
    connect(update_timer_, &QTimer::timeout, this, [this]() {
        ros::spinOnce();
        if (!ros::ok()) close();
    });

    connect(pushButton, &QPushButton::clicked, this, [this]() {
        pubTwist(k_, 0);
    });
    connect(pushButton_2, &QPushButton::clicked, this, [this]() {
        pubTwist(-k_, 0);
    });
    connect(pushButton_3, &QPushButton::clicked, this, [this]() {
        pubTwist(0, k_);
    });
    connect(pushButton_4, &QPushButton::clicked, this, [this]() {
        pubTwist(0, -k_);
    });
}

void MainWindow::pubTwist(double k_lx, double k_az) {
    v_lx_ = double(horizontalSlider->value());
    v_az_ = double(horizontalSlider_2->value());

    geometry_msgs::Twist twist;
    twist.linear.x = k_lx * v_lx_;
    twist.angular.z = k_az * v_az_;
    cmd_pub_.publish(twist);

    label->setText(QString("Twist:(") + QString::number(twist.linear.x) + QString(",0,0,0,0,") +
                   QString::number(twist.angular.z) + QString(")"));
}

void MainWindow::colorCallback(const turtlesim::ColorConstPtr &color) {
    label->setStyleSheet("QLabel { background-color: " + QColor(color->r, color->g, color->b).name() + "; " +
                         "color: " + QColor(255 - color->r, 255 - color->g, 255 - color->b).name() + "; }");
}

void MainWindow::poseCallback(const turtlesim::PoseConstPtr &pose) {
    statusbar->showMessage(QString("Pose:(") + QString::number(pose->x) + QString(",") + QString::number(pose->y) +
                           QString(",0,0,0,") + QString::number(pose->theta) + QString(")"));
}