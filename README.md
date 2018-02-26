# PID Controller for Udacity's Self Driving Car Simulator
  
  
## Summary

This program implements a PID controller for a simulated car driving around a track. Cross Track Error (CTE) is calculated based on the car's position away from the middle of the track. Udacity's SDC Simulator provides the CTE and this program determines the steering angle using a PID controller.
  
  
## Tuning Hyperparameters

Hyperparameters for the proportional, integral, and differential components (Kp, Ki, Kd) were tuned manually. Initial values of (0.1, 0.1, 0.1) were individually modified by a factor of 10 to gauge their effects. Initially the car steered immediately off the track. Based on experimentation it was discovered that lowering Ki to 0.001 enabled the car to drive somewhat straight. However the car went off track during turns. Values for Kp and Kd were increased to 1.0. Doing so caused the car to wobble back and forth erratically. Kp was reduced back to 0.1 which mitigated this effect. Kd was increased to 3.0 and Ki was decreased to 0.0001. This produced good results and the car successfully completed the track. 

The hyperparameters were fine tuned to mitigate wobble in the car's motion while responding well to turns. Their final values are: (Kp = 0.1, Ki = 0.0002, Kd = 4.0).
  
  
## Hyperparameter Discussion

Based on experimentation it was noticed that higher P and I components improved the controller's performance during turns. However they made the car's motion unstable (sharply turning left and right). Specially the I component had a large impact on this effect. It makes intuitive sense since the I component is multiplied by an integral (sum) of the CTE, thus producing large steering angles. For that reason the I component is kept small (0.0001 order of magnitude). 

Conversely the D component is only effected by the rate of change in the CTE. If the CTE does not change (even if it has a large value) the D component will have little effect. However during period of change in the CTE the D component plays a significant role. As such it had a 'smoothing' effect and mitigated the wobble caused by higher P and I values. During experimentation it was noted that values for Kd as high as 10.0 kept the car's motion stable. However it was reduced to 4.0 to avoid erratic steering angles.
  
  
## Dependencies

* cmake >= 3.5
 * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1(mac, linux), 3.81(Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools]((https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)
* [uWebSockets](https://github.com/uWebSockets/uWebSockets)
  * Run either `./install-mac.sh` or `./install-ubuntu.sh`.
  * If you install from source, checkout to commit `e94b6e1`, i.e.
    ```
    git clone https://github.com/uWebSockets/uWebSockets 
    cd uWebSockets
    git checkout e94b6e1
    ```
    Some function signatures have changed in v0.14.x. See [this PR](https://github.com/udacity/CarND-MPC-Project/pull/3) for more details.
* Simulator. You can download these from the [project intro page](https://github.com/udacity/self-driving-car-sim/releases) in the classroom.

There's an experimental patch for windows in this [PR](https://github.com/udacity/CarND-PID-Control-Project/pull/3)
  
  
## Basic Build Instructions

1. Clone this repo.
2. Make a build directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./pid`
5. Start `Project 4: PID Controller` in Udacity's SDC Simulator

Tips for setting up your environment can be found [here](https://classroom.udacity.com/nanodegrees/nd013/parts/40f38239-66b6-46ec-ae68-03afd8a601c8/modules/0949fca6-b379-42af-a919-ee50aa304e6a/lessons/f758c44c-5e40-4e01-93b5-1a82aa4e044f/concepts/23d376c7-0195-4276-bdf0-e02f1f3c665d)
