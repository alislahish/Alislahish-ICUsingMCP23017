/*
*  2015 anwarhahjjeffersongeorge
**********************************************************************
*  This library is free software; you can redistribute it and/or
*  modify it under the terms of the GNU Lesser General Public
*  License as published by the Free Software Foundation; either
*  version 2.1 of the License, or (at your option) any later version.
*
*  This library is distributed in the hope that it will be useful,
*  but WITHOUT ANY WARRANTY; without even the implied warranty of
*  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
*  Lesser General Public License for more details.
*
*  You should have received a copy of the GNU Lesser General Public
*  License along with this library; if not, write to the Free Software
*  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#include "ICUsingMCP23017.h"

/**
 * designate an MCP23017 for this IC. the MCP23017 used should already have had Adafruit_MCP2301.begin() called on it 
 */
void ICUsingMCP23017::setMCP23017(bool usingMCP23017, Adafruit_MCP23017 * mcp23017Ptr=nullptr, uint8_t mcpAddr=0){
  _isUsingMCP23017 = usingMCP23017;
  _mcpAddr = mcpAddr;

  if( _isUsingMCP23017 && (mcp23017Ptr != nullptr) ){ //are supposed to use MCP23017 AND actually passed a pointer to one?
    _mcpPtr = mcp23017Ptr;
  } else {
    _mcpPtr = nullptr;
    _isUsingMCP23017 = false; //make sure we don't try to use non existent MCP23017
  }
}

/**
* set the mode of a given pin using MCP23017 or direct connection to Arduino
*/
void ICUsingMCP23017::pinMode(uint8_t pin, uint8_t direction){
  if(_isUsingMCP23017){
    _mcpPtr -> pinMode(pin, direction);
  } else{
    pinMode(pin, direction);
  }
}


/**
* write to an IC pin using MCP23017 or direct connection to Arduino
*/
void ICUsingMCP23017::digitalWrite(uint8_t pin, uint8_t direction){
  if(_isUsingMCP23017){
    _mcpPtr -> digitalWrite(pin, direction);
  } else {
    digitalWrite(pin, direction);
  }
}

/**
* read from an IC pin using MCP23017 or direct connection to Arduino
*/
uint8_t ICUsingMCP23017::digitalRead(uint8_t pin){
  if(_isUsingMCP23017){
    return _mcpPtr -> digitalRead(pin);
  } else {
    return digitalRead(pin);
  }
}