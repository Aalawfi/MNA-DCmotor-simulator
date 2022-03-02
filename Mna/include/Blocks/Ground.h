#pragma once
#include "MnaBlock.h"

namespace ELCT350
{
  namespace Mna
  {
    namespace Blocks
    {
      class Ground : public Block
      {
      public:

        enum Ports
        {
          G
        };

        Ground();

        virtual void initialize() override;
        virtual void mnaStep(double timeStep, double time) override;
      };
    }
  }
}