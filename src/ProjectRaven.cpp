#include "vex.h"
#include <vector>
/*
class foo {

  public:
    std::vector<std::vector<int[2]>> encoderValues;
    foo(std::vector<std::vector<int[2]>> _encoderValues) {
      encoderValues = _encoderValues;
    };

  public: // we need to capture velocity as well
    task fetchCurrentEncoderValues(motor_group a, motor_group b) {
      int i = 0;
      while (1) { // I still need to figure out the exit condition
        std::vector<int[2]> foo;
        int *a = new int[2];

        for (int i = 0; i < 4; i++) {
          a[0] = 1;
          a[1] = 2;
          foo.assign(a, a);
        }

        foo.push_back(leftWheelMotorD.position(deg), 1);
        foo.push_back(leftWheelMotorB.position(deg));
        foo.push_back(rightWheelMotorA.position(deg));
        foo.push_back(rightWheelMotorC.position(deg));
        i++;

        task::sleep(25);
      }
    }

  public:
    void resetMotorEncoders() {
      leftMotors.resetPosition();
      rightMotors.resetPosition();
      intakeMotors.resetPosition();
      armMotor.resetPosition();
      pistonMotor.resetPosition();
    }

  public:
    void repeatLastActions() {
      leftMotors.setPosition(double value, rotationUnits units)
    }
  };

  */