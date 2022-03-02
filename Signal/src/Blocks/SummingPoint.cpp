#include "Blocks/SummingPoint.h"


using namespace ELCT350::Signal::Blocks;


SummingPoint::SummingPoint()
    : Common::Block(3),
    Block(2, 1) // 2 input 1 output
{ 
    //setOutputPortValue(SummingPoint::OutputPorts::Output, 33.0);
    //throw NotImplementedException();
}


void SummingPoint::initialize()
{
    setOutputPortValue(SummingPoint::OutputPorts::Output,
        (getInputPortValue(SummingInputs::signal_a)
            + getInputPortValue(SummingInputs::signal_b)));

}

void SummingPoint::signalStep(double timeStep, double time)
{
    initialize();

   // throw NotImplementedException();
}