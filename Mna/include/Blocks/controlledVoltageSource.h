#pragma once
#include "MnaBlock.h"

namespace ELCT350
{
    namespace Mna
    {
        namespace Blocks
        {
            class vsource : public Block
            {
            public:
                enum Parameters
                {
                    Resistance
                };

                enum Ports
                {
                    P,
                    N
                };

                vsource();

                virtual void initialize() override;
                virtual void mnaStep(double timeStep, double time) override;
            };
        }
    }
}