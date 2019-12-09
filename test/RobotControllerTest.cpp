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

/*
 * @copyright 2019
 * @copyright MIT License
 * @file RobotControllerTest.cpp
 * Design (iteration 1)
 * @author Vamshi - Navigator
 * @author Raja - Driver
 * @date 4/12/2019
 * @version 1.0
 * @brief Tests the member methods of RobotController class.
 */

#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <gtest/gtest.h>
#include "material_handling_robot/RobotController.h"
#include <memory>

/**
 * Tests the velocitycallBack method and get velocity method of the
 * Robot Controller Class.
 */
TEST(RobotControllerTest, velocityCallBackTest) {
  // created object for the RobotController class.
  RobotController control;
  //creating a twist message
  geometry_msgs::Twist message;
  // setting linear velocity in x is 2
  message.linear.x = 2;
  geometry_msgs::Twist::ConstPtr velocity(new geometry_msgs::Twist(message));
  // sending velocity to callBack function
  control.velocityCallback(velocity);
  geometry_msgs::Twist vel = control.getVelocity();
  // testing velocity set by the callback function is correct.
  EXPECT_EQ(2, vel.linear.x);
}


