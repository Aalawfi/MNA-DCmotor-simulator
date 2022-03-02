#include "SignalSolver.h"
#include "Exceptions/NotImplementedException.h"

using namespace ELCT350::Common::Exceptions;
using namespace ELCT350::Signal;

#pragma region Constructors
Solver::Solver(double timeStep)
      : _timeStep(timeStep), _time(0)
{
    
   // Solver::initialize();
  //throw NotImplementedException();
}
#pragma endregion

#pragma region Observers
double Solver::getTimeStep() const { return _timeStep; };
double Solver::getTime() const { return _time; }
#pragma endregion

#pragma region Modifiers
void Solver::initialize()
{
    _time = 0.0;
    for (auto ablock : _blocks)
    {
        ablock->initialize();
        
    }
}

void Solver::connect(const Block& outputBlock, size_t outputPortIndex,
                     Block& inputBlock, size_t inputPortIndex)
{
    _blocks.insert(&inputBlock);
    inputBlock.connect(inputPortIndex, outputBlock, outputPortIndex);
}

void Solver::step()
{
    for (auto ablock : _blocks)
    {
        ablock->signalStep(_timeStep, _time);
    }
    _time =_time + _timeStep;
}
#pragma endregion