cmake_minimum_required(VERSION 3.16)
project(teleop)

set(CMAKE_CXX_STANDARD 14)

find_package(catkin REQUIRED COMPONENTS roscpp)
find_package(Qt5 REQUIRED COMPONENTS Core Widgets)

include_directories(include ${catkin_INCLUDE_DIRS})
link_directories(${catkin_LIBRARY_DIRS})

catkin_package(CATKIN_DEPENDS geometry_msgs)

set(${PROJECT_NAME}_node_SRCS src/teleop.cpp src/tele_mainwindow.cpp)
set(${PROJECT_NAME}_node_HDRS include/teleop/tele_mainwindow.h)

qt5_wrap_cpp(${PROJECT_NAME}_node_MOCS ${${PROJECT_NAME}_node_HDRS})

add_executable(${PROJECT_NAME}_node ${${PROJECT_NAME}_node_SRCS} ${${PROJECT_NAME}_node_MOCS})
target_link_libraries(${PROJECT_NAME}_node ${catkin_LIBRARIES} Qt5::Core Qt5::Widgets)