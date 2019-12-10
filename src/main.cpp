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
 * @file main.cpp
 * Design (iteration 1)
 * @author Vamshi - Navigator
 * @author Raja - Driver
 * @implementation (iteration 3)
 * @author Vamshi - Driver
 * @author Raja - Navigator
 * @date 4/12/2019
 * @version 1.0
 * @brief main function.
 */

#include <iostream>
#include "material_handling_robot/PathPlanner.h"
#include "material_handling_robot/RobotController.h"
#include "material_handling_robot/ObstacleChange.h"
#include "material_handling_robot/MaterialHandler.h"

/**
 * @brief main function
 * @param  argc  The argc
 * @param  argv  The argv
 * @return int of value zero
 */
int main(int argc, char* argv[]) {
  // Initialize the ros node
  ros::init(argc, argv, "materialHandlingRobot");

  // create objects for classes
  PathPlanner planPath;
  RobotController robotControl;
  ObstacleChange obs;
  MaterialHandler handle;

  // user choice of pickup and dropoff locations
  int pickUpChoice;
  int dropOffChoice;
  std::cout
      << "choose a pickup Location from three available choices '1' '2' '3' ."
      << std::endl;
  std::cin >> pickUpChoice;
  std::cout
      << "choose a dropOff Location from three available choices '1' '2' '3' ."
      << std::endl;
  std::cin >> dropOffChoice;

  Position pickUp;
  Position dropOff;

  switch (pickUpChoice) {
    case 1:
      std::cout << "Choice is 1" << std::endl;
      pickUp = handle.getPickUp1();
      break;
    case 2:
      std::cout << "Choice is 2" << std::endl;
      pickUp = handle.getPickUp2();
      break;
    case 3:
      std::cout << "Choice is 3" << std::endl;
      pickUp = handle.getPickUp3();
      break;
    default:
      std::cout << "Invalid Choice choose correct one." << std::endl;
      std::cout << "choose a pickup Location from "
                "three available choices '1' '2' '3' ."
                << std::endl;
      std::cin >> pickUpChoice;
      break;
  }

  switch (dropOffChoice) {
    case 1:
      std::cout << "Choice is 1" << std::endl;
      dropOff = handle.getDropOff1();
      break;
    case 2:
      std::cout << "Choice is 2" << std::endl;
      dropOff = handle.getDropOff2();
      break;
    case 3:
      std::cout << "Choice is 3" << std::endl;
      dropOff = handle.getDropOff3();
      break;
    default:
      std::cout << "Invalid Choice choose correct one." << std::endl;
      std::cout << "choose a dropOff Location from "
                "three available choices '1' '2' '3' ."
                << std::endl;
      std::cin >> dropOffChoice;
  }

  bool flag = true;
  // vector to store pick and drop off positions.
  std::vector<Position> vec;
  vec.push_back(pickUp);
  vec.push_back(dropOff);
  std::cout << vec.size() << std::endl;

  // calling readVelocity function which subscribes to
  // "/navigation_velocity_smoother/raw_cmd_vel"
  robotControl.readVelocity();

  // subscribe to robot status /move_base/status topic.
  planPath.subscribeStatus();

  for (auto iter = vec.begin(); iter != vec.end(); iter++) {
    auto goal = *iter;
    planPath.setGoal(goal.x, goal.y);
    std::cout << planPath.getGoal() << std::endl;
    while (flag) {
      auto status = planPath.getStatus();
      ros::Rate loop_rate(1);
      planPath.sendGoal();
      robotControl.writeVelocity();
      ros::Duration(10).sleep();
      if (status == 3) {
        flag = false;
        obs.spawnObject(goal.x, goal.y);
        ros::Duration(2).sleep();
        obs.destroyObject();
        std::cout << "quit while loop" << std::endl;
      }
      // "Spin" a callback in case we set up any callbacks
      ros::spinOnce();
      // Sleep for the remaining time until we hit our 1 Hz rate
      loop_rate.sleep();
    }
    flag = true;
  }
  return 0;
}

