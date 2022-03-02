#pragma once
#include "SignalBlock.h"
#include <set>
namespace ELCT350
{
  namespace Signal
  {
    class Solver
    {
    public:
      #pragma region Constructors
      Solver(double timeStep);
      #pragma endregion

      #pragma region Modifiers
      //Initializes all the signal blocks
      //(calls initialize() on them)
      void initialize();

      //Connect block ports together
      //1. Add block to our block set
      //2. Connecting  
      void connect(const Block& outputBlock, size_t outputPortIndex,
                   Block& inputBlock, size_t inputPortIndex);

      //Steps all the blocks **in order**
      //In between steps copy output port values into input ports
      //that they're connected to
      void step();
      #pragma endregion

      #pragma region Observers
      double getTimeStep() const;
      double getTime() const;
      #pragma endregion
    private:
      #pragma region Constants
      const double _timeStep;
      #pragma endregion

      #pragma region Variables
      double _time;
      std::set<Block*> _blocks;
      #pragma endregion
    };
  }
}