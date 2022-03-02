#include "Blocks/PID.h"


using namespace ELCT350::Signal::Blocks;


PID::PID()
    : Common::Block(1),
    Block(1, 1)  // 1 input 1 output
{ 
    _ref = 0.0;
    _Kp = 0.0; 
    _Kd = 0.0; 
    _Ki = 0.0;

    //throw NotImplementedException();
}
void PID::setRef(double newRef) {
    _ref = newRef;
}
void PID::setGain(double Kp, double Kd, double Ki) {
    _Kp = Kp; 
    _Kd = Kd; 
    _Ki = Ki;
};

void PID::initialize()
{
    previous_error = 0.0; 
    prev_error_area = 0.0;
}



void PID::signalStep(double timeStep, double time)
{
    /* This means in the main, the Input port must be updated every iteration*/
    double error = (_ref - getInputPortValue(PID::Input)); 
    double error_change = (error - previous_error) / timeStep;
    
    double error_area = timeStep * error + prev_error_area;
    double u = _Kp * error
        + _Kd * error_change
        +_Ki * error_area;
    setOutputPortValue(PID::Output, u);
  
    previous_error = error; 
    prev_error_area = error_area;
}