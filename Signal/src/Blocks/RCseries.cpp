#include "Blocks/RCseries.h"
#include "Exceptions/NotImplementedException.h"
#include "SignalBlock.h"
using namespace ELCT350::Common::Exceptions;
using namespace ELCT350::Signal::Blocks;
using namespace ELCT350::Signal;
RCseries::RCseries()
    : Common::Block(3),
    Block(1, 2) // 1 input two output
{
  //  initialize();
  //  throw NotImplementedException();
}

void RCseries::initialize()
{
    _previousInputVoltage = 0.0;
    //Blocks::RCseries rc(1, 2);
   // throw NotImplementedException();
}

void RCseries::signalStep(double timeStep, double time)
{
    switch (static_cast<unsigned short>(getParameterValue(IntegrationType)))
    {
    case ForwardEuler:
        forwardEuler(timeStep);
        break;
    case BackwardEuler:
        backwardEuler(timeStep);
        break;
    case Trapezoidal:
        trapezoidal(timeStep);
        break;
    }

    _previousInputVoltage = getInputPortValue(VoltageSource);

   // throw NotImplementedException();
}
void RCseries::forwardEuler(double timeStep)
{
    double r = getParameterValue(Resistance);
    double rc = r * getParameterValue(Capacitance);
    double previousValueFactor = (rc - timeStep) / rc;
    setOutputPortValue(CapacitorVoltage, previousValueFactor * getOutputPortValue(CapacitorVoltage) +
        timeStep * _previousInputVoltage / rc);
    setOutputPortValue(ResistorCurrent, previousValueFactor * getOutputPortValue(ResistorCurrent) +
        (getInputPortValue(VoltageSource) - _previousInputVoltage) / r);
}

void RCseries::backwardEuler(double timeStep)
{
    double c = getParameterValue(Capacitance);
    double rc = getParameterValue(Resistance) * c;
    double rcPlusDeltaT = rc + timeStep;
    double previousValueFactor = rc / rcPlusDeltaT;

    setOutputPortValue(CapacitorVoltage, previousValueFactor * getOutputPortValue(CapacitorVoltage) +
        timeStep * getInputPortValue(VoltageSource) / rcPlusDeltaT);
    setOutputPortValue(ResistorCurrent,
        previousValueFactor * getOutputPortValue(ResistorCurrent) +
        c * (getInputPortValue(VoltageSource) - _previousInputVoltage) / rcPlusDeltaT);
}

void RCseries::trapezoidal(double timeStep)
{
    double inputVoltage = getInputPortValue(VoltageSource);
    double c = getParameterValue(Capacitance);
    double rc = getParameterValue(Resistance) * c;
    double twoRCplusDeltaT = 2.0 * rc + timeStep;
    double previousValueFactor = (2.0 * rc - timeStep) / twoRCplusDeltaT;

    setOutputPortValue(CapacitorVoltage, previousValueFactor * getOutputPortValue(CapacitorVoltage) +
        timeStep * (inputVoltage + _previousInputVoltage) / twoRCplusDeltaT);
    setOutputPortValue(ResistorCurrent, previousValueFactor * getOutputPortValue(ResistorCurrent) +
        2.0 * c * (inputVoltage - _previousInputVoltage) / twoRCplusDeltaT);
}