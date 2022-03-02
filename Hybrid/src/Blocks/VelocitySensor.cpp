#include "Blocks/VelocitySensor.h"

using namespace ELCT350::Hybrid::Blocks;

#pragma region Constructors
VelocitySensor::VelocitySensor()
              : Common::Block(0),
                Mna::Block(1),
                Signal::Block(0, 1)
{
}
#pragma endregion

#pragma region Block
void VelocitySensor::initialize()
{
}

void VelocitySensor::mnaStep(double timeStep, double time)
{
}

void VelocitySensor::signalStep(double timeStep, double time)
{
  setOutputPortValue(Velocity, getAcross(Sensor));
}
#pragma endregion