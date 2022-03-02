#pragma once

namespace ELCT350
{
  namespace Signal
  {
    class Port
    {
    public:
      Port();

      virtual void setValue(double value);
      double getValue() const;
    private:
      double _value;
    };
  }
}