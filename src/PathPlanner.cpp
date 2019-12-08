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
 * @file PathPlanner.cpp
 * Design (iteration 1)
 * @author Vamshi - Navigator
 * @author Raja - Driver
 * @date 4/12/2019
 * @version 1.0
 * @brief Stub implementation of class PathPlanner that calls the inbuilt Path planning
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
  (void) x;
  (void) y;
}

void PathPlanner::sendGoal() {
}

uint8_t PathPlanner::getStatus() {
  return 1;
}

void PathPlanner::subscribeStatus() {
}

void PathPlanner::reachedTargetCallback(
    const actionlib_msgs::GoalStatusArray::ConstPtr& msg) {
  (void) msg;
}
