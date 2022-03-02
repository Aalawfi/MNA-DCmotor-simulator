#pragma once
#include "Exceptions/Exception.h"

namespace ELCT350
{
  namespace Common
  {
    namespace Exceptions
    {
      class UnknownParameterException : public virtual Exception
      {
      public:
        UnknownParameterException(size_t parameterIndex);
      private:
        static constexpr const char* const DEFAULT_MESSAGE = "Parameter not found at index ";
        const size_t _index;
      };
    }
  }
}