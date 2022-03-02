#pragma once
#include "Exceptions/Exception.h"

namespace ELCT350
{
  namespace Common
  {
    namespace Exceptions
    {
      class NotImplementedException : public virtual Exception
      {
      public:
        NotImplementedException();
      private:
        static constexpr const char* const DEFAULT_MESSAGE = "Not yet implemented";
      };
    }
  }
}