#include "Blocks/Constant.h"
#include "Exceptions/NotImplementedException.h"

using namespace ELCT350::Common::Exceptions;
using namespace ELCT350::Signal::Blocks;

enum ErrorCodes
{
  Ok,
  FunctionNotImplemented = 0x1,
  OtherExceptions = 0x2,
  parameterValueFailure = 0x4,
};

static const double CONSTANT_VALUE = 10.0;

int main()
{
  int errorCode = Ok;

  try
  {
    Constant constant;

    constant.setParameterValue(Constant::ConstantValue, CONSTANT_VALUE);
    if (constant.getParameterValue(Constant::ConstantValue) != CONSTANT_VALUE)
    {
      errorCode |= parameterValueFailure;
    }
  }
  catch (const NotImplementedException&)
  {
    errorCode |= FunctionNotImplemented;
  }
  catch (...)
  {
    errorCode |= OtherExceptions;
  }

  return errorCode;
}