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
 * @file ObstacleChange.h
 * Design (iteration 1)
 * @author Vamshi - Navigator
 * @author Raja - Driver
 * @date 4/12/2019
 * @version 1.0
 * @brief definition of methods for Stub ObstacleChange class.
 */

#include <iostream>
#include <vector>
#include "ros/ros.h"
#include "sensor_msgs/LaserScan.h"
#include "geometry_msgs/Twist.h"

#ifndef SRC_OBSTACLECHANGE_H_
#define SRC_OBSTACLECHANGE_H_

/**
 * @brief ObstacleChange class that spawns an object when robot arrives at location
 * in gazebo and also has method that makes the object disappear.
 */
class ObstacleChange {
 public:

  /**
   * constructor for this class.
   */
  ObstacleChange();

  /**
   * Destructor for this class.
   */
  ~ObstacleChange();

  /**
   * @brief sets the goal which is a private attribute to this class
   *  of type move_base_msgs::MoveBaseActionGoal
   * @param double targetPoint.
   * @return None
   */
  std::string targetPtSet(double targetPoint);

  /**
   * @brief spawns a wooden block in gazebo at location x, y specified.
   * @param double x which is x position on the map where the model to spawns.
   * @param double y which is y position on the map where the model to spawns.
   * @return None
   */
  void spawnObject(double x, double y);

  /**
   * @brief destroys the spawned object indicating robot picked up
   * the object.
   * @param None
   * @return None
   */
  void destroyObject();
};

#endif /* SRC_OBSTACLECHANGE_H_ */
