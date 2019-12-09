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
 * @file RobotController.h
 * Design (iteration 2)
 * @author Vamshi - Driver
 * @author Raja - Navigator
 * @implementation (iteration 3)
 * @author Vamshi - navigator
 * @author Raja - Driver
 * @date 4/12/2019
 * @version 1.0
 * @brief Definition of class RobotController that subscribes to velocity topic on
 * move_base node, and publishes on /cmd_vel topic.
 */

#ifndef SRC_ROBOTCONTROLLER_H_
#define SRC_ROBOTCONTROLLER_H_

#include "ros/ros.h"
#include "geometry_msgs/Twist.h"
#include "move_base_msgs/MoveBaseAction.h"

/**
 * @brief RobotController class that subscribes to /raw_cmd_vel topic
 * and remaps to /cmd_vel topic.
 */
class RobotController {
 public:

  /**
   * constructor for this class.
   */
  RobotController();

  /**
   * Destructor for this class.
   */
  ~RobotController();

  /**
   * @brief subscribes to "/navigation_velocity_smoother/raw_cmd_vel" topic
   * where move_base publishes the velocity messages.
   * @param None.
   * @return None.
   */
  void readVelocity();
  /**
   * @brief To get the private attribute cmd_vel
   * @params None
   * @return  geometry_msgs::Twist, this function returns cmd_vel which is private attribute
   */
  geometry_msgs::Twist getVelocity();

  /**
   * @brief publishes to "/cmd_vel topic" which is subscribed by the turtlebot
   * and receives velocity messages.
   * @param None.
   * @return None.
   */
  void writeVelocity();

  /**
   * @brief is a callback function for the subscriber, this function sets the command
   * message from the move_base message.
   * @param None.
   * @return None.
   */
  void velocityCallback(const geometry_msgs::Twist::ConstPtr& msg);

 private:
  ros::NodeHandle nodeHandler;  // Node handler for this class
  // Publisher to the cmd_vel topic
  ros::Publisher publishVelocity = nodeHandler.advertise<geometry_msgs::Twist>(
      "/cmd_vel", 1000);
  geometry_msgs::Twist commandVelocity;
  ros::Subscriber subscribeVelocity;  // Subscribes to "/navigation_velocity_smoother/raw_cmd_vel" topic
};

#endif /* SRC_ROBOTCONTROLLER_H_ */


