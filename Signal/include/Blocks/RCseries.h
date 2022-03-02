#pragma once

#include "SignalBlock.h"

namespace ELCT350
{
  namespace Signal
  {
    namespace Blocks
    {
      class RCseries : public Block
      {
      public:
        enum IntegrationType : unsigned short
        {
          ForwardEuler,
          BackwardEuler,
          Trapezoidal
        };

        enum Parameters : unsigned short
        {
          Resistance,
          Capacitance,
          IntegrationType
        };

        enum InputPorts : unsigned short
        {
          VoltageSource
        };

        enum OutputPorts : unsigned short
        {
          CapacitorVoltage,
          ResistorCurrent
        };

        RCseries();

        virtual void initialize() override;
        virtual void signalStep(double timeStep, double time) override;
        void forwardEuler(double timeStep);
        void backwardEuler(double timeStep);
        void trapezoidal(double timeStep);
      private: 
          double _previousInputVoltage;
      };
    }
  }
}