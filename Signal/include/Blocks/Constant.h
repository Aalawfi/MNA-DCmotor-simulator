#pragma once

#include "SignalBlock.h"

namespace ELCT350
{
  namespace Signal
  {
    namespace Blocks
    {
      class Constant : public Block
      {
      public:
        enum Parameters : unsigned short
        {
          ConstantValue
        };

        enum OutputPorts : unsigned short
        {
          Output
        };

        Constant();

        virtual void initialize() override;
        virtual void signalStep(double timeStep, double time) override;

      };
    }
  }
}