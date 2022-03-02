#pragma once
#include "SignalPort.h"

namespace ELCT350
{
  namespace Signal
  {
    class OutputPort : public Port
    {
    public:
      OutputPort();

      bool isReady() const;
      
      //set ready flag to false
      void reset();
   

      //sets value and set ready flag to true
    virtual void setValue(double value) override;
    private:
      bool _ready;
    };
  }
}