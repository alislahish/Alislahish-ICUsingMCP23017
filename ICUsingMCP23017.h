/*
*
*  ICUsingMCP23017.h
*  
*  by anwarhahjjeffersongeorge
*
*  With this class is enacted a helper for creating subclasses
*  by which ICs are controlled by Arduinos which may or may not
*  employ MCP23017 GPIO expanders as intermediaries.
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