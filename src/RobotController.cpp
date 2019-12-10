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
 * @file RobotController.cpp
 * Design (iteration 2)
 * @author Vamshi - Driver
 * @author Raja - Navigator
 * @implementation (iteration 3)
 * @author Vamshi - navigator
 * @author Raja - Driver
 * @date 4/12/2019
 * @version 1.0
 * @brief Implementation of RobotController class that subscribes to velocity topic on
 * move_base node, and publishes on /cmd_vel topic.
 */

#include "material_handling_robot/RobotController.h"

/**
 * constructor for this class.
 */
RobotController::RobotController() {
}
/**
 * Destructor for this class.
 */
RobotController::~RobotController() {
}

geometry_msgs::Twist RobotController::getVelocity() {
  return commandVelocity;
}

void RobotController::readVelocity() {
  subscribeVelocity = nodeHandler.subscribe(
      "/navigation_velocity_smoother/raw_cmd_vel", 200,
      &RobotController::velocityCallback, this);
}

void RobotController::velocityCallback(
    const geometry_msgs::Twist::ConstPtr& msg) {
  commandVelocity = *(msg);
}

void RobotController::writeVelocity() {
  publishVelocity.publish(commandVelocity);
}


