#pragma once
#include "MnaBlock.h"

namespace ELCT350
{
    namespace Mna
    {
        namespace Blocks
        {
            class DCmotor : public Block
            {
            public:
                enum Parameters
                {
                    J,
                    R,
                    L,
                    K,
                    B
  
                };

                enum Ports
                {
                    P,
                    N,
                    T
                };

                DCmotor();

                virtual void initialize() override;
                virtual void mnaStep(double timeStep, double time) override;
            };
        }
    }
}