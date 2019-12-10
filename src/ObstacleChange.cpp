/**
 *  MIT License
 *
 *  Copyright (c) 2019 Vamshi Bogoju, Raja Srinivas Iskala
 *
 *  Permission is hereby granted, free of charge, to any person obtaining a
 *  copy of this software and associated documentation files (the "Software"),
 *  to deal in the Software without restriction, including without
 *  limitation the rights to use, copy, modify, merge, publish, distribute,
 *  sublicense, and/or sell copies of the Software, and to permit persons to
 *  whom the Software is furnished to do so, subject to the following
 *  conditions:
 *
 *  The above copyright notice and this permission notice shall be included
 *  in all copies or substantial portions of the Software.
 *
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
 *  THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 *  FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 *  DEALINGS IN THE SOFTWARE.
 */

/**
 * @copyright 2019
 * @copyright MIT License
 * @file ObstacleChange.cpp
 * Design (iteration 1)
 * @author Vamshi - Navigator
 * @author Raja - Driver
 * @implementation (iteration 3)
 * @author Vamshi - Driver
 * @author Raja - Navigator
 * @date 4/12/2019
 * @version 1.0
 * @brief implementation of class ObstacleChange.
 */

#include "material_handling_robot/ObstacleChange.h"
#include "ros/ros.h"

ObstacleChange::ObstacleChange() {
}

ObstacleChange::~ObstacleChange() {
}

std::string ObstacleChange::setTargetPoint(double targetPoint) {
  std::ostringstream os;
  os << targetPoint;
  return os.str();
}

std::string ObstacleChange::spawnObject(double x, double y) {
  std::string g_x = setTargetPoint(x);
  std::string g_y = setTargetPoint(y);
  std::string start = "rosrun gazebo_ros spawn_model -file src"
      "/material_handling_robot/gazebo_models/wood_cube_10cm/model.sdf -sdf ";
  std::string x_vals = "-x ";
  std::string y_vals = " -y ";
  std::string end = " -z 0 -model wood";
  std::string cmd = start + x_vals + g_x + y_vals + g_y + end;
  const char* command = cmd.c_str();
  ROS_INFO("Set the objects in the map %s", command);
  system(command);
  return cmd;
}

std::string ObstacleChange::destroyObject() {
  // Rosservice to remove the model from the gazebo environment.
  std::string destroy = "rosservice call /gazebo/delete_model";
  // models name to be removed
  std::string cont = " wood";
  // Joining the string to make it a command.
  std::string cmd = destroy + cont;
  const char* command = cmd.c_str();
  ROS_INFO("Removed the Object from the map");
  // Send the command to the system.
  system(command);
  return cmd;
}


