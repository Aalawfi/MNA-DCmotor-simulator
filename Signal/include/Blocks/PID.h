#pragma once

#include "SignalBlock.h"

namespace ELCT350
{
  namespace Signal
  {
    namespace Blocks
    {
      class PID : public Block
      {
      public:
          void setGain(double Kp, double Kd, double Ki);
          void setRef(double newRef);
        enum PIDInput : unsigned short
        {
          Input
        };

        enum OutputPorts : unsigned short
        {
          Output
        };

        PID();
       
        virtual void initialize() override;
        virtual void signalStep(double timeStep, double time) override;
      private: 
          double _ref;
          double _Kp;
          double _Kd; 
          double _Ki;
          double previous_error =0;
          double prev_error_area =0;
      };
    }
  }
}