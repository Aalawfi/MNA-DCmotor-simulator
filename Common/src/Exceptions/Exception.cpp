#include "Exceptions/Exception.h"
#include <fstream>

using namespace ELCT350::Common::Exceptions;
using namespace std;

Exception::Exception(const string& message)
         : _message(message)
{
  ofstream file("Log.txt", ios_base::ate);
  file << _message;
}