#pragma once

#include "SignalBlock.h"

namespace ELCT350
{
  namespace Signal
  {
    namespace Blocks
    {
      class SquareWave : public Block
      {
      public:
          enum SquareWaveInput : unsigned short
          {
              Input
          };

        enum Parameters : unsigned short
        {
          Peak, 
          Freq, 
          DutyCycle
        };

        enum OutputPorts : unsigned short
        {
          Output
        };

        SquareWave();
        void setFunctionGenerator(double peak_voltage, double frequency);
        virtual void initialize() override;
        virtual void signalStep(double timeStep, double time) override;
      private: 
          double _peakVoltage; 
          double _Frequency; 
          double _DutyCycle;
      };
    }
  }
}