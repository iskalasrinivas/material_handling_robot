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
 * @file MaterialHandler.cpp
 * Design (iteration 1)
 * @author Vamshi - Driver
 * @author Raja - navigator
 * implementation (iteration 3)
 * @author Vamshi - navigator
 * @author Raja - Driver
 * @date 4/12/2019
 * @version 1.0
 * @brief class implementation for MaterialHandler class.
 */

#include "material_handling_robot/MaterialHandler.h"

/**
 * constructor implementation for this class.
 */
MaterialHandler::MaterialHandler() {
  dropOffPosition1.x = 8.0;
  dropOffPosition1.y = 0;
  dropOffPosition2.x = 5.0;
  dropOffPosition2.y = -5.0;
  dropOffPosition3.x = 5.0;
  dropOffPosition3.y = 1.0;
  pickUpPosition1.x = 3.0;
  pickUpPosition1.y = 7.0;
  pickUpPosition2.x = 4.0;
  pickUpPosition2.y = 6.0;
  pickUpPosition3.x = 7.0;
  pickUpPosition3.y = 8.0;
}

/**
 * Destructor for this class.
 */
MaterialHandler::~MaterialHandler() {
}

Position MaterialHandler::getDropOff1() {
  return dropOffPosition1;
}

Position MaterialHandler::getDropOff2() {
  return dropOffPosition2;
}

Position MaterialHandler::getDropOff3() {
  return dropOffPosition3;
}

Position MaterialHandler::getPickUp1() {
  return pickUpPosition1;
}

Position MaterialHandler::getPickUp2() {
  return pickUpPosition2;
}

Position MaterialHandler::getPickUp3() {
  return pickUpPosition3;
}

