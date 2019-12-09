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
 * @file PathPlanner.h
 * Design (iteration 2)
 * @author Vamshi - Navigator
 * @author Raja - Driver
 * Implementation (iteration-3)
 * @author Vamshi - Driver
 * @author Raja - Navigator
 * @date 4/12/2019
 * @version 1.0
 * @brief Definition of class PathPlanner that calls the inbuilt Path planning
 * algorithm in navigation stack.
 */

#ifndef SRC_PATHPLANNER_H_
#define SRC_PATHPLANNER_H_

#include "ros/ros.h"
#include "actionlib/client/simple_action_client.h"
#include "geometry_msgs/PoseStamped.h"
#include "move_base_msgs/MoveBaseGoal.h"
#include "move_base_msgs/MoveBaseAction.h"
#include "tf/transform_broadcaster.h"
#include "nav_msgs/GetMap.h"
#include "nav_core/base_global_planner.h"
#include "move_base/move_base.h"

/**
 * @brief PathPlanner class that implements methods to send goal to move_base
 * package and also receive status, that indicates robot reached goal or not.
 */
class PathPlanner {
 public:
  /**
   * constructor for this class.
   */
  PathPlanner();

  /**
   * Detructor for this class.
   */
  ~PathPlanner();

  /**
   * @brief sets the goal which is a private attribute to this class
   *  of type move_base_msgs::MoveBaseActionGoal
   * @param double x which is x position of the goal that is sent.
   * @param double y which is y position of the goal that is sent.
   * @return None
   */
  void setGoal(double x, double y);

  /**
   * @brief gets the goal that is being published, getter for
   * private data member.
   * @param None.
   * @return move_base_msgs::MoveBaseActionGoal returns goal position.
   */
  move_base_msgs::MoveBaseActionGoal getGoal();

  /**
   * @brief A publisher that sends the goal to move_base node by publishing to
   * /move_base/goal topic.
   * @param None.
   * @return None
   */
  void sendGoal();

  /**
   * @brief A getter that gets the status of the robot currently helpful in
   * tracking the progree of robot motion.
   * @param None.
   * @return uint8_t returns the status variable stored in the actionlib_msgs::GoalStatusArray
   * message.
   */
  uint8_t getStatus();

  /**
   * @brief A subscriber to "/move_base/status" topic which is helpful to get status.
   * @param None.
   * @return None.
   */
  void subscribeStatus();

  /**
   * @brief A callback function for status subscriber, this method retrieves current status
   * of the robot and stores in variable.
   * @param actionlib_msgs::GoalStatusArray::ConstPtr& msg  A pointer to a message type
   * that has status information.
   * @return None.
   */
  void reachedTargetCallback(
      const actionlib_msgs::GoalStatusArray::ConstPtr& msg);

 private:
  move_base_msgs::MoveBaseActionGoal goalMsg;  // goal to be sent
  // node handler for the PathPlanner class.
  ros::NodeHandle nodeHandler;
  ros::Publisher publishGoal = nodeHandler
      .advertise<move_base_msgs::MoveBaseActionGoal>("/move_base/goal", 1000);  // goal publisher
  ros::Subscriber readStatus;  // subscriber to "/move_base/status"
  int goalReached = 0;  // variable to indicate if goal is reached.
  actionlib_msgs::GoalStatusArray statusMessage;  // type of status message
};

#endif /* SRC_PATHPLANNER_H_ */

