#pragma once
#include <exception>
#include <string>

namespace ELCT350
{
  namespace Common
  {
    namespace Exceptions
    {
      class Exception : public virtual std::exception
      {
      public:
        #pragma region Constructors and Destructors
        Exception(const std::string& message);
        #pragma endregion

        #pragma region exception
        virtual const char* what() const noexcept override
        {
          return _message.c_str();
        }
        #pragma endregion
      private:
        #pragma region Variables
        std::string _message;
        #pragma endregion
      };
    }
  }
}