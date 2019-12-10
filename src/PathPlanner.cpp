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
 * @file PathPlanner.cpp
 * Design (iteration 2)
 * @author Vamshi - Navigator
 * @author Raja - Driver
 * Implementation (iteration-3)
 * @author Vamshi - Driver
 * @author Raja - Navigator
 * @date 4/12/2019
 * @version 1.0
 * @brief Implementation of class PathPlanner that calls the inbuilt Path planning
 * algorithm in navigation stack.
 */

#include "material_handling_robot/PathPlanner.h"

PathPlanner::PathPlanner() {
}

PathPlanner::~PathPlanner() {
}

move_base_msgs::MoveBaseActionGoal PathPlanner::getGoal() {
  return goalMsg;
}

void PathPlanner::setGoal(double x, double y) {
  // Define the initial velocity message
  goalMsg.goal.target_pose.header.frame_id = "map";
  goalMsg.goal.target_pose.header.stamp = ros::Time::now();
  goalMsg.goal.target_pose.pose.position.x = x;
  goalMsg.goal.target_pose.pose.position.y = y;
  goalMsg.goal.target_pose.pose.position.z = 0;
  geometry_msgs::Quaternion quat = tf::createQuaternionMsgFromYaw(0);
  goalMsg.goal.target_pose.pose.orientation = quat;
}

void PathPlanner::sendGoal() {
  publishGoal.publish(goalMsg);
}

uint8_t PathPlanner::getStatus() {
  return goalReached;
}

void PathPlanner::subscribeStatus() {
  readStatus = nodeHandler.subscribe("/move_base/status", 200,
                                     &PathPlanner::reachedTargetCallback, this);
}

void PathPlanner::reachedTargetCallback(
    const actionlib_msgs::GoalStatusArray::ConstPtr& msg) {
  if (!msg->status_list.empty()) {
    actionlib_msgs::GoalStatus goalStatus = msg->status_list[0];
    goalReached = goalStatus.status;
  }
}
