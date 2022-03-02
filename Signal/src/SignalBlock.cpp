#include "Exceptions/NotImplementedException.h"
#include "SignalBlock.h"

using namespace ELCT350::Common::Exceptions;
using namespace ELCT350::Signal;

Block::Block(size_t numberOfInputPorts, size_t numberOfOutputPorts)
	: _numberOfInputPorts(0),
	_numberOfOutputPorts(0),
	_inputPorts(nullptr),
	_outputPorts(nullptr)
{
	_inputPorts = new InputPort[numberOfInputPorts];
	_outputPorts = new OutputPort[numberOfOutputPorts];
	_numberOfInputPorts = numberOfInputPorts;
	_numberOfOutputPorts = numberOfOutputPorts;

}
Block::~Block()
{
	if (_outputPorts == NULL)
		return;
	if (_inputPorts == NULL)
		return;
	if (_outputPorts)
	{
		delete[] _outputPorts;
		_outputPorts = nullptr;
		_numberOfOutputPorts = 0;
	}
	if (_inputPorts)
	{
		delete[] _inputPorts;
		_inputPorts = nullptr;
		_numberOfInputPorts =0;
	}



	//throw NotImplementedException();
}

double Block::getOutputPortValue(size_t index) const
{
	return _outputPorts[index].getValue();
}

void Block::setOutputPortValue(size_t index, double value)
{

	_outputPorts[index].setValue(value);

}

double Block::getInputPortValue(size_t index) const
{
	return _inputPorts[index].getValue();
}

void Block::connect(size_t inputPortIndex,
	const Block& outputBlock, size_t outputPortIndex) {
	_inputPorts[inputPortIndex].connect(outputBlock._outputPorts[outputPortIndex]);
};
void Block::copyValues() {
	
};
