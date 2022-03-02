#pragma once

#include "SignalBlock.h"

namespace ELCT350
{
    namespace Signal
    {
        namespace Blocks
        {
            class SubtPoint : public Block
            {
            public:
                enum SubtInput : unsigned short
                {
                    signal_a, 
                    signal_b
                };

                enum OutputPorts : unsigned short
                {
                    Output
                };

                SubtPoint();

                virtual void initialize() override;
                virtual void signalStep(double timeStep, double time) override;
          
            };
        }
    }
}