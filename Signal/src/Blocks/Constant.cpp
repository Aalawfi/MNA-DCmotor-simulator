#include "Blocks/Constant.h"


using namespace ELCT350::Signal::Blocks;


Constant::Constant()
    : Common::Block(1),
    Block(0, 1) // 0 input 1 output
{ 
   
    //throw NotImplementedException();
}


void Constant::initialize()
{
   // setParameterValue(Parameters::ConstantValue, getParameterValue())
    this->setOutputPortValue(Output, getParameterValue(ConstantValue));
  //  throw NotImplementedException();
  //  throw NotImplementedException();
}

void Constant::signalStep(double timeStep, double time)
{
    initialize();
   // throw NotImplementedException();
}