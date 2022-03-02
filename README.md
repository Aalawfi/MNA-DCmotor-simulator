# MNA-DCmotor-simulator

# Introduction
The aim of this project is to create a discrete time simulation of a simple PID control system to control the rotation speed of a PMDC motor. The simulation was attempted in c++ and via Simulink tool. In order to simulate the system, a mathematical description of the DC motor’s transfer function is necessary. Modified Nodal Analysis (MNA) is also used in this project to find the voltages and currents across and through the components of the systems. The closed-loop system is composed of a reference value (desired output), negative feedback, PID controller, model of the PMDC motor and added torque, and controller voltage source. The overall block diagram is shown in figure 1.

![image](https://user-images.githubusercontent.com/87329726/156281996-bb82f59e-85b9-47cd-a860-f52036fe51da.png)

# Modified Noda Analysis (MNA)
The traditional signal flow approach require the examiner to track the input and outputs of each node for the circuit. Some limitation of that approach is that it requires a new derivation of equations for each node or output. The current expression can only be applied to the current circuit topology. Any change on the circuit will require new derivation of output equations. It is also difficult to track the signal when the system is cascaded with another system. An example of the traditional signal-flow approach is the nodal analysis performed on the circuit of the DC motor in the previous section.
A major feature of MNA is that it allows to create a solver method that eliminates the need for manual analysis. This mean each block of the circuit (each component) will have characteristics information that does not correlate to the other blocks or components of the overall system. Then, the algorithm takes into account all the characteristics matrices of the blocks and combine them to create an overall system matrix. This often yield larger set of expressions, however, it is easier to automate the process of solving the circuit with a computer.
The MNA standard form is given in equation below. Here, I is referred to as the through vector, G is the Jacobian matrix, V is the across vector. In case of electrical circuits, this would be the current and the voltage respectively.
𝐼⃗=𝐺𝑉⃗⃗−𝐵 
The Jacobian matrix and the intercept matrix hold a signature description of an MNA block. That signature, plays a major role in determining the through vector and the across vector. The size of the Jacobian matrix is n×n where n is the number of ports of the block. The vectors will also have n number of rows. For instance, figure below shows an MNA block of a resistor. As labled, the resistor have two ports, P and N.

![image](https://user-images.githubusercontent.com/87329726/156282233-f5bb6532-aa5d-4468-a3a9-830f71361875.png)


Hence, the size of the Jacobian matrix is 2×2, and the remaining vectors will have two rows. Since this example deals with an electrical component, the through vector represent the current through the resistor and the across vector represents the voltage across the resistor. The current through the resistor is obtained by the equation below. The current at port N is flowing out of the resistor, hence the direction is opposite to the current flowing in (the value will be negated).


