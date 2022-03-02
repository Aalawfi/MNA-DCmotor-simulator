#include "Exceptions/UnknownParameterException.h"

using namespace ELCT350::Common::Exceptions;
using namespace std;

UnknownParameterException::UnknownParameterException(size_t index)
                         : Exception(DEFAULT_MESSAGE + to_string(index)), _index(index)
{
}