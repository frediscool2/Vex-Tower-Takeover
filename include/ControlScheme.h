class ControllerInteraction {
public:
  static void moveLeftSide();
  static void moveRightSide();
  static void pullIntake();
  static void pushIntake();
  static void liftArm();
  static void lowerArm();
  static void extendPiston();
  static void retractPiston();
  static void stopIntake();
  static void stopArm();
  static void stopPiston();
};

class Driver {
  bool running = false;

  static void nothing();

public:
  static void setDriverCieran();
  static void setDriverCharlie();
  static void setDriverAndrew();
};