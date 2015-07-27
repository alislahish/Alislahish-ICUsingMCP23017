/*
*
*  ICUsingMCP23017.h
*  
*  by anwarhahjjeffersongeorge
*
*  With this class is enacted a helper for creating subclasses
*  by which ICs are controlled by Arduinos which may or may not
*  employ MCP23017 GPIO expanders as intermediaries.
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


#include "Arduino.h"
#include "Adafruit_MCP23017.h"


#ifndef ICUSINGMCP23017_H
#define ICUSINGMCP23017_H

class ICUsingMCP23017{
	private:
		boolean _isUsingMCP23017;
		Adafruit_MCP23017 * _mcpPtr;
		uint8_t _mcpAddr;
		
  	public:
  		virtual void setMCP23017(bool usingMCP23017, Adafruit_MCP23017 * mcp23017Ptr, uint8_t mcpAddr);
  		virtual void pinMode(uint8_t pin, uint8_t direction);
  		virtual void digitalWrite(uint8_t pin, uint8_t direction);
  		virtual uint8_t digitalRead(uint8_t pin);
};

#endif 