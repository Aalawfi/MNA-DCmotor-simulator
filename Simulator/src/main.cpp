#include "Blocks/Constant.h"
#include "Blocks/RCseries.h"
#include "Blocks/Resistor.h"
#include "Blocks/PID.h"
#include "Blocks/SquareWave.h"
#include "Blocks/SummingPoint.h"
#include "MnaSolver.h"
#include "SignalSolver.h"
#include "SignalPort.h"
#include "InputPort.h"; 
#include "OutputPort.h"
#include "MnaNode.h"
#include <iostream>
#include <fstream>

using namespace ELCT350::Math;
using namespace ELCT350::Mna::Blocks;
using namespace ELCT350::Mna;
using namespace ELCT350::Signal::Blocks;
using namespace ELCT350::Signal;
using namespace std;

using MnaSolver = ELCT350::Mna::Solver;
using SignalSolver = ELCT350::Signal::Solver;

enum ErrorCodes
{
  Ok = 0
};

int main(int argc, char* argv[])
{
   /* OutputPort s; 
    s.setValue(5.0);
    std::cout << s.getValue() << std::endl;*/
    

    //Constant a; 
    //a.setParameterValue(Constant::ConstantValue, 5.0);
    //std::cout << "a parameter: " << a.getParameterValue(Constant::ConstantValue) << std::endl;
    //a.initialize();
    //cout << "a.outpuPort: " << a.getOutputPortValue(Constant::Output) << endl;

    //Constant b; 
    //b.setParameterValue(Constant::ConstantValue, 1.0);
    //std::cout << "b parameter: " << b.getParameterValue(Constant::ConstantValue) << std::endl;
    //b.initialize();
    //cout << "b.outpuPort: " << b.getOutputPortValue(Constant::Output) << endl;

    //SummingPoint Junction;
    //Junction.connect(SummingPoint::signal_a, a, Constant::Output);
    //Junction.connect(SummingPoint::signal_b, b, Constant::Output);
    //cout << "Input a: "<< Junction.getInputPortValue(SummingPoint::signal_a) << endl;
    //cout << "Input b: " << Junction.getInputPortValue(SummingPoint::signal_b) << endl;

    //Junction.initialize();
    //cout << "Junction output: " << Junction.getOutputPortValue(SummingPoint::Output) << endl;

    Constant C;
    C.setParameterValue(Constant::ConstantValue, 2.0);
    C.initialize();
    cout << "First reference output: " << C.getOutputPortValue(Constant::Output)<< endl;
    Constant D; 
    D.setParameterValue(Constant::ConstantValue, 3.0); 
    D.initialize();
    cout << "Second reference output: " << D.getOutputPortValue(Constant::Output) << endl;
    SummingPoint J; 
    cout << "" << endl;
    SignalSolver s(0.01);
    s.connect(C, Constant::Output, J, SummingPoint::signal_a);
    s.connect(D, Constant::Output, J, SummingPoint::signal_b);
   
    cout << "Junction input a: " << J.getInputPortValue(SummingPoint::signal_a) << endl;
    cout << "Junction input b: " << J.getInputPortValue(SummingPoint::signal_b) << endl;
    s.step();
    cout << "Junction output: " << J.getOutputPortValue(SummingPoint::Output) << endl;
    PID controller; 
    controller.setGain(1.0, 1.0, 1.0); controller.setRef(1.0);
    s.connect(J, SummingPoint::Output, controller, PID::Input);
    cout << "" << endl;
    cout << "Controller input " << controller.getInputPortValue(PID::Input) << endl;
   s.step();
    cout << " Controller output :" << controller.getOutputPortValue(PID::Output) << endl;
  
    Resistor r1; 
    r1.setParameterValue(Resistor::Resistance, 1000);
    r1.initialize();
    
    r1.computeThroughValues();
    cout << r1.getThrough(0) << endl;
    /*cout << r1.getJacobian(Resistor::Ports::P, Resistor::Ports::P) << endl;
    Node a(r1.getMnaPort(0));
    a.getAcross();*/

   
    //SignalSolver wavy(0.01);
    //Constant duty; 
    //duty.setParameterValue(Constant::ConstantValue, 1);
    //duty.initialize();
    ////Square
    //SquareWave Test;
    //Test.setFunctionGenerator(1.0, 1.0);
    //wavy.connect(duty, Constant::Output, Test, SquareWave::SquareWaveInput::Input);

  
    //wavy.initialize();
    //while (wavy.getTime() <= 10.0)
    //{
    //    wavy.step();
    //    cout << Test.getOutputPortValue(SquareWave::OutputPorts::Output) << endl;
    //}
  ////  s.connect()


   // cout << J.getOutputPortValue(SummingPoint::Output) << endl;
  //  cout << J.getOutputPortValue(SummingPoint::Output) << endl;
  //  Junction.c
    // Constant velocity_ref;  
  //  velocity_ref.setParameterValue(Constant::ConstantValue, 1.0); 
    //std::cout << "velocity is: " << velocity_ref.getParameterValue(Constant::ConstantValue) << std::endl;
   
   
   
  // JunctionTest.setInputPortValue(SummingPoint::signal_a,
   //    input_1.getOutputPortValue(Constant::Output));


  // JunctionTest.signalStep(0.01, 1);
 //  std::cout << "Junction output  is: " << JunctionTest.getOutputPortValue(SummingPoint::Output) << std::endl;

 /*  signalConnector.connect(input_1, Constant::ConstantValue,
       JunctionTest, SummingPoint::signal_a);*/
   
    /* MnaSolver mnaSolver(0.01, 1e-7);
  SignalSolver signalSolver(0.01);

  Constant c1;
  c1.setParameterValue(Constant::ConstantValue, 10.0);

  RCseries rc1;
  rc1.setParameterValue(RCseries::Capacitance, 0.001);
  rc1.setParameterValue(RCseries::Resistance, 1000);
  rc1.setParameterValue(RCseries::IntegrationType, RCseries::ForwardEuler);

  signalSolver.connect(c1, Constant::Output,
                       rc1, RCseries::VoltageSource);

  //Example, modify this to perform RC Series simulation
  //Don't forget to get parameter values from argv
  Resistor r1;
  Resistor r2;
  r1.setParameterValue(Resistor::Resistance, 1000);
  r2.setParameterValue(Resistor::Resistance, 1000);

  mnaSolver.connect(r1, r1.getMnaPort(Resistor::N),
                    r2, r2.getMnaPort(Resistor::P));
 
  mnaSolver.initialize();
  signalSolver.initialize();
  while(mnaSolver.getTime() <= 10.0)
  {
    mnaSolver.step();
    signalSolver.step();

    r1.getAcross(Resistor::P);
    r1.getThrough(Resistor::P);
    rc1.getOutputPortValue(RCseries::CapacitorVoltage);
  }
  */
  return Ok;
}