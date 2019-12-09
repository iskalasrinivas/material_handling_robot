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
 * @file MaterialHandler.h
 * Design (iteration 1)
 * @author Vamshi - Driver
 * @author Raja - navigator
 * @implementation (iteration 3)
 * @author Vamshi - navigator
 * @author Raja - Driver
 * @date 4/12/2019
 * @version 1.0
 * @brief class Definition for MaterialHandler class.
 */

#ifndef SRC_MATERIALHANDLER_H_
#define SRC_MATERIALHANDLER_H_

#include <vector>

/**
 * @brief A struct that stores position with x and y values indicating position
 * of the object on the map.
 */
struct Position {
  double x;
  double y;
};

/**
 * @brief MaterialHandler class which has pickup
 * and drop off locations as attributes, and has methods to get them.
 */
class MaterialHandler {
 public:

  /**
   * constructor for this class.
   */
  MaterialHandler();

  /**
   * Destructor for this class.
   */
  ~MaterialHandler();

  /**
   * @brief getter for dropOffPosition1 which is a private attribute of
   * this class.
   * @param None.
   * @return struct Position returns a struct that has position of drop off 1
   * location.
   */
  Position getDropOff1();

  /**
   * @brief getter for dropOffPosition2 which is a private attribute of
   * this class.
   * @param None.
   * @return struct Position returns a struct that has position of drop off 2
   * location.
   */
  Position getDropOff2();

  /**
   * @brief getter for dropOffPosition3 which is a private attribute of
   * this class.
   * @param None.
   * @return struct Position returns a struct that has position of drop off 3
   * location.
   */
  Position getDropOff3();

  /**
   * @brief getter for pickUpPosition1 which is a private attribute of
   * this class.
   * @param None.
   * @return struct Position returns a struct that has position of pickup 1
   * location.
   */
  Position getPickUp1();

  /**
   * @brief getter for pickUpPosition2 which is a private attribute of
   * this class.
   * @param None.
   * @return struct Position returns a struct that has position of pickup 2
   * location.
   */
  Position getPickUp2();

  /**
   * @brief getter for pickUpPosition3 which is a private attribute of
   * this class.
   * @param None.
   * @return struct Position returns a struct that has position of pickup 3
   * location.
   */
  Position getPickUp3();

 private:
  // Struct for drop off position1
  Position dropOffPosition1;
  // Struct for drop off position2
  Position dropOffPosition2;
  // Struct for drop off position3
  Position dropOffPosition3;
  // Struct for pickup position1
  Position pickUpPosition1;
  // Struct for pickup position2
  Position pickUpPosition2;
  // Struct for pickup position3
  Position pickUpPosition3;
};

#endif /* SRC_MATERIALHANDLER_H_ */


