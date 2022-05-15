# Gimbal
Gimbal – Camera Stabilization System
Project Goal
The project's goal is to create a “gimbal”, a device balancing system used when taking photos or shooting a movie.
Finally, all vibrations caused by hand quivers or rapid movements might cause the quality deterioration of photos/videos.
The final product will be made with low expenditure while ensuring good quality service.
Implementation
The end device consists of:
•	Case and frame
•	Device movement sensory system
•	Stabilizing system
•	Power system
The case and frame in which the electronic device will be placed will be made in 3D printing technology.
The movements sensory system is a 3-axis accelerometer with a gyroscope, its going to react to changes in position with collected data sent to the computational unit.
The stabilizing system consists of 3 servos, receiving instructions from the computational unit, to balance the device in case of unwanted movement operating on all 3-axes.
The computatonal unit is microcontroler. The program uploaded to it contains algorithms taking in the raw data from the accelerometer computing them to the set of instructions controlling the right servos.
Power system creation uses a battery and step-down converter LM2956.
Communication between individual elements will be using the I2C transmission protocol.

