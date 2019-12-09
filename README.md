# Material_Handling_Robot
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
[![Build Status](https://travis-ci.org/vamshibogoju/material_handling_robot.svg?branch=iteration_development_3)](https://travis-ci.org/vamshibogoju/material_handling_robot)
[![Coverage Status](https://coveralls.io/repos/github/vamshibogoju/material_handling_robot/badge.svg?branch=iteration_development_3)](https://coveralls.io/github/vamshibogoju/material_handling_robot?branch=iteration_development_3)
---
Table Contents:
- [Authors](#authors)
- [Overview](#overview)
- [Licence](#licence)
- [Product Backlog and Sprint Schedule](#sip_process)
- Assumptions
- [Dependencies](#dependencies)
- Build Instructions
- [Run Tests](#tests)
- [Running Demo](#demo)
- [ROSBAG](#rosbag)

# <a name="authors"></a> Authors
- [Raja Srinivas Iskala  ](https://www.linkedin.com/in/raja-srinivas-iskala-6631aa118/)
- [Vamshi kumar Bogoju](https://www.linkedin.com/in/vamshi-kumar-bogoju/)

## [Raja](https://www.linkedin.com/in/raja-srinivas-iskala-6631aa118/)
Raja Srinivas is a Robotics Graduate student at UMD,College Park.He completed his undergraduation in Mechanical Engineering.His interests is medical robotics. 

## [Vamshi](https://www.linkedin.com/in/vamshi-kumar-bogoju/)
Vamshi is a Robotics Graduate student at UMD,College Park.He completed his undergraduation in Mechanical Engineering.His interests are Deep Learning,Machine Learning and Computer Vision.

# <a name="overview"></a> Overview
This projects depicts the functionality of material handling robot using a turtlebot2. It is used in hopital environment.Map is generated from gazebo world using slam gmapping. It  takes pickup and dropoff locations from user.It uses navigation stack to navigate between these ponts.It also uses AMCl algorithm to localise in the map.[DWA](http://wiki.ros.org/dwa_local_planner) algorithm as local planner to find optimal path netween pickup and dropff locations.

The navigation of robot can be seen in rviz and gazebo

# <a name="licence"></a> License
```
MIT License

Copyright (c) 2019 Vamshi Bogoju, Raja Srinivas Iskala

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
```

# <a name="sip_process"></a> Product Backlog and Sprint Schedule
The product backlog can be accessed [here](https://docs.google.com/spreadsheets/d/1nVl0dMQTroqI0meNcP8Amp6S9SXnRqDkkKQacyyF09o/edit?usp=sharing) to access the sprint schedule

The Sprint Planning and review can be accessed [here](https://docs.google.com/document/d/16DDF-5zMlHBn17OWl21v8ubEJHDfndoh-yup7gChvdo/edit?usp=sharing)

Raja and Vamshi worked together on this implementation and alternate commits were made. The commits are made by the driver while the other person acted as navigator.

# Assumptions
- Obstacles are static
- Speed of robot is limited.
- Object robot picksup is not more than threshold payload
[Dependencies Installation steps](https://youtu.be/P_-cCO_jp-s)

# <a name="dependencies"></a> Dependencies
This project uses the following packages:
1. ROS Kinetic
2. Ubuntu 16.04
3. Packages Dependencies:

 
 * gmapping slam packages
 * roscpp
 * rospy
 * std_msgs
 * geometry_msgs
 * rostest
 * rosbag
 * actionlib_msgs
 
## Build Instructions

If you followed above package dependencies intallation section follow this`

```

mkdir -p ~/catkin_ws/src
cd ~/catkin_ws/
catkin_make
source devel/setup.bash
cd src/
git clone --recursive https://github.com/vamshibogoju/material_handling_robot.git
cd ..
catkin_make
```
# <a name="tests"></a>Running Tests
- Level 1: unit tests
- Level 2: integration testsoth can run by the following command:
```
cd ~/catkin_ws/
catkin_make run_tests material_handling_robot
```

# <a name="demo"></a> Running Demo
- Demo can be run by following the undermentioned instructions
```
cd ~/catkin_ws
roslaunch material_handling_robot turtlebotDemo.launch 

```
This launches gazebo,rviz with turtlebot 2.Now run following in new terminal
```
rosrun  material_handling_robot materialHandlingRobot
```
User needs to input pickup and dropff points as asked in the terminal.Navigation of robot is shown in rviz and gazebo

# <a name="rosbag"></a> ROSBAG

## Recording ROSBAG

 Record the rostopics using the following command with the launch file:
```
roslaunch  material_handling_robot turtlebotDemo.launch record:=true
```
recorded bag file will be stored in the results folder and records all except camera topics, for 30 seconds.



## Running ROSBAG
Navigate to the results folder
```
cd ~/catkin_ws/src/ material_handling_robot/results
```
play the bag file
```
rosbag play turtlebotRecord.bag
