#pragma once

#include "SignalBlock.h"

namespace ELCT350
{
    namespace Signal
    {
        namespace Blocks
        {
            class SummingPoint : public Block
            {
            public:
                enum SummingInputs : unsigned short
                {
                    signal_a, 
                    signal_b
                };

                enum OutputPorts : unsigned short
                {
                    Output
                };

                SummingPoint();

                virtual void initialize() override;
                virtual void signalStep(double timeStep, double time) override;
          
            };
        }
    }
}