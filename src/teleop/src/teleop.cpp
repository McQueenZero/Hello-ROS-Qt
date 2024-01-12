#include "teleop/tele_mainwindow.h"

namespace Tele {
    class OpApp : public QApplication {
    public:
        ros::NodeHandlePtr nh_;

        OpApp(int& argc, char** argv) : QApplication(argc, argv) {
            ros::init(argc, argv, "teleop_node");
            nh_.reset(new ros::NodeHandle);
        }

        int exec() {
            MainWindow mainWindow(*nh_);
            mainWindow.show();

            return QApplication::exec();
        }
    };
}

int main(int argc, char **argv)
{
    Tele::OpApp app(argc, argv);
    return app.exec();
}
