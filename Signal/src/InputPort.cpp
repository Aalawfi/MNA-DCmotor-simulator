#pragma once 
#include "InputPort.h"

using namespace ELCT350::Signal; 

InputPort::InputPort() :_connectedPort(0) {
    
}

/* 
private:
      const OutputPort* _connectedPort;
      */
void InputPort::connect(const OutputPort& port)
{
    _connectedPort = &port; // Set the connection
    copyValue(); // import values form connected port 
}
void InputPort::copyValue() {

    // Set the value of the input port to the value of the output port 
    if (areDependenciesSatisfied()); // if we are ready 
    { 
        this->Port::setValue(_connectedPort->getValue());
    }
}
bool InputPort::areDependenciesSatisfied() const
{
    if (_connectedPort->isReady())
        return true; 
    else return false;
    //return true;
};