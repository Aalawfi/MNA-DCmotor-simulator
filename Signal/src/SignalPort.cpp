#pragma once 
#include "SignalPort.h"
#include "Exceptions/Exception.h"
using namespace ELCT350::Common::Exceptions;
/*
Port();

      virtual void setValue(double value);
      double getValue() const;
    private:
      double _value;
*/
using namespace ELCT350::Signal; 
Port::Port() : _value(0.0) {
    _value = 0.0;
    //_value = 0.0;
};
void Port::setValue(double value) {
    _value = value;
}
double Port::getValue() const {
    return _value; 
}