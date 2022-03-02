#include "Blocks/SquareWave.h"
#include <cmath>
#include <iostream>
using namespace ELCT350::Signal::Blocks;


SquareWave::SquareWave()
    : Common::Block(2),
    Block(1, 1) // 1input 1 output
                
{ 
    _peakVoltage = 0;
    _Frequency = 0;
    _DutyCycle = 0;
    //throw NotImplementedException();
}

void SquareWave::setFunctionGenerator(double voltage, double freqeuncy) {
    _peakVoltage = voltage; 
    _Frequency = freqeuncy; 
}
void SquareWave::initialize()
{
    
}

bool is_integer(double k) {
    return std::floor(k) == k;
}
int count = 0;
void SquareWave::signalStep(double timeStep, double time)
{
    double period = (1.0 / _Frequency);
    double A = 1 - 2 * (std::fmod((time * period), 2));
    double output;
    if (A >= 0)
    {
        output = _peakVoltage;
        count++;
        setOutputPortValue(SquareWave::Output, output);
    }
    else
    {
        std::cout << count << std::endl;
        output = 0;
        setOutputPortValue(SquareWave::Output, output);
    }
}