#include "Block.h"
#include "Exceptions/Exception.h"
#include <iostream>
using namespace ELCT350::Common; 
using namespace ELCT350::Common::Exceptions;

Block::Block(size_t numberOfParameters) : _numberOfParameters(0), _parameters(nullptr)
{
	_numberOfParameters = numberOfParameters; 
}

Block::~Block()
{
	if (_parameters)
	{
		_parameters = nullptr;
		_numberOfParameters = 0;
	}
}

void Block::setParameterValue(size_t index, double value)
{
	checkParameterIndex(index);
	_parameters = new double();
	 (_parameters[index]) = value;
}
double Block::getParameterValue(size_t index) const
{
	checkParameterIndex(index);
	return (_parameters[index]);
}

void Block::checkParameterIndex(size_t index) const
{
	if (index >= _numberOfParameters)
		throw Exception("Worng index");

}