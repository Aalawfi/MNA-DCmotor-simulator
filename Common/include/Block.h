#pragma once

namespace ELCT350
{
    namespace Common
    {
        class Block
        {
        public:
            virtual ~Block();

            void setParameterValue(size_t index, double value);
            double getParameterValue(size_t index) const;

            virtual void initialize() = 0;
        protected:
            Block(size_t numberOfParameters);
        private:
            size_t _numberOfParameters;
            double* _parameters;

            void checkParameterIndex(size_t index) const;
        };
    }
}