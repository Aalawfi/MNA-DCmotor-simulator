#pragma once
#include "MnaBlock.h"
#include "SignalBlock.h"

namespace ELCT350
{
  namespace Hybrid
  {
		namespace Blocks
		{
			class VelocitySensor
				: public Mna::Block,
					public Signal::Block
			{
			public:
				#pragma region Types
				enum MnaPorts
				{
					Sensor
				};

				enum SignalOutputPorts
				{
					Velocity
				};
				#pragma endregion

				#pragma region Constructors
				VelocitySensor();
				#pragma endregion

				#pragma region Block
				virtual void initialize() override;
				virtual void mnaStep(double timeStep, double time) override;
				virtual void signalStep(double timeStep, double time) override;
				#pragma endregion
			};
		}
  }
}