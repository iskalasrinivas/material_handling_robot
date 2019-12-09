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
 * @file MaterialHandlerTest.cpp
 * Design (iteration 2)
 * @author Vamshi - Driver
 * @author Raja - Navigator
 * @date 4/12/2019
 * @version 1.0
 * @brief This class used to implement testing for MaterialHandler class
 */

#include <ros/ros.h>
#include <gtest/gtest.h>
#include "material_handling_robot/MaterialHandler.h"


/**
 * @brief To test MaterialHandle intialization
 * @param MaterialHandlerTest gtest framework
 * @param testMethods name of test
 * @return None
 */
TEST(MaterialHandlerTest, testMethods) {
  // created object for MaterialHandler class
    MaterialHandler handle;

  // made an object of the struct for checking Position

  // checking position for drop off 1
  Position pose1 = handle.getDropOff1();
  EXPECT_EQ(8.0, pose1.x);
  EXPECT_EQ(0, pose1.y);

  // checking position for drop off 2
  Position pose2 = handle.getDropOff2();
  EXPECT_EQ(5.0, pose2.x);
  EXPECT_EQ(-5.0, pose2.y);

  // checking position for drop off 3
  Position pose3 = handle.getDropOff3();
  EXPECT_EQ(5.0, pose3.x);
  EXPECT_EQ(1.0, pose3.y);

  // checking position for pickup 1
  Position pose4 = handle.getPickUp1();
  EXPECT_EQ(3.0, pose4.x);
  EXPECT_EQ(7.0, pose4.y);

  // checking position for pickup 2
  Position pose5 = handle.getPickUp2();
  EXPECT_EQ(4.0, pose5.x);
  EXPECT_EQ(6.0, pose5.y);

  // checking position for pickup 3
  Position pose6 = handle.getPickUp3();
  EXPECT_EQ(7.0, pose6.x);
  EXPECT_EQ(8.0, pose6.y);
}
