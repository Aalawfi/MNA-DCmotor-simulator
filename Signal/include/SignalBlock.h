#pragma once
#include "Block.h"
#include "InputPort.h"
#include <set>

namespace ELCT350
{
    namespace Signal
    {
        class Block : public virtual Common::Block
        {
        public:
            virtual ~Block();

            double getOutputPortValue(size_t index) const;
            bool isReady() const;

            void connect(size_t inputPortIndex,
                const Block& outputBlock, size_t outputPortIndex);
            void copyValues();
            virtual void signalStep(double timeStep, double time) = 0;
            double getInputPortValue(size_t index) const;
        protected:
            Block(size_t numberOfInputPorts, size_t numberOfOutputPorts);

            void addDependency(size_t inputPortIndex);
            void setOutputPortValue(size_t index, double value);
            
        private:
            size_t _numberOfInputPorts;
            size_t _numberOfOutputPorts;

            InputPort* _inputPorts;
            OutputPort* _outputPorts;

            std::set<InputPort*> _dependencies;

            const OutputPort& getOutputPort(size_t outputPortIndex) const;
        };
    }
}