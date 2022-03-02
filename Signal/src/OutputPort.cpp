#pragma once 
#include "OutputPort.h"
using namespace ELCT350::Signal;
OutputPort::OutputPort() :_ready(0) {
    
};

bool OutputPort::isReady() const {
    return _ready;
};

//set ready flag to false
void OutputPort::reset() {
    _ready = false;
};


//sets value and set ready flag to true
void OutputPort::setValue(double value){
    _ready = true;
    this->Port::setValue(value);
    
};