
#include "Blocks/SubtPoint.h"


using namespace ELCT350::Signal::Blocks;


SubtPoint::SubtPoint()
    : Common::Block(3),
    Block(2, 1) // 2 input 1 output
{ 
    //setOutputPortValue(SummingPoint::OutputPorts::Output, 33.0);
    //throw NotImplementedException();
}


void SubtPoint::initialize()
{
    setOutputPortValue(SubtPoint::OutputPorts::Output,
        (getInputPortValue(SubtPoint::signal_a)
            - getInputPortValue(SubtPoint::signal_b)));

}

void SubtPoint::signalStep(double timeStep, double time)
{
    initialize();

   // throw NotImplementedException();
}