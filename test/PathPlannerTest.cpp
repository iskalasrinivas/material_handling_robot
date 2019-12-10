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
 * @file PathPlannerTest.cpp
 * Design (iteration 2)
 * @author Vamshi - Driver
 * @author Raja - Navigator
 * @date 4/12/2019
 * @version 1.0
 * @brief Tests the member methods of PathPlanner class.
 */

#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <gtest/gtest.h>
#include "material_handling_robot/PathPlanner.h"

/**
 * @brief To test for get goal functionality
 * @param PathPlannerTest gtest framework
 * @param testGetandSetGoal name of test
 * @return None
 */
TEST(PathPlannerTest, testGetandSetGoal) {
  PathPlanner plan;
  plan.setGoal(4, 5);
  auto goal = plan.getGoal();
  EXPECT_EQ(4, goal.goal.target_pose.pose.position.x);
  EXPECT_EQ(5, goal.goal.target_pose.pose.position.y);
}

/**
 * @brief To test for intialization of nodehandle
 * @param PathPlannerTest gtest framework
 * @param InitializationErrorTest name of test
 * @return None
 */
TEST(PathPlannerTest, InitializationErrorTest) {
  ros::NodeHandle nh;
  EXPECT_NO_FATAL_FAILURE(PathPlanner planner);
}

