#include "mbed.h"
#include "bbcar.h"

Ticker servo_ticker;
PwmOut pin8(D8), pin9(D9);

BBCar car(pin8, pin9, servo_ticker);

int main() {
    // please contruct you own calibration table with each servo
    double pwm_table0[] = {-150, -120, -90, -60, -30, 0, 30, 60, 90, 120, 150};
    double speed_table0[] = {-16.349, -15.791, -14.594, -11.404, -5.423, 0.000, 5.423, 11.404, 14.594, 15.791, 16.349};
    double pwm_table1[] = {-150, -120, -90, -60, -30, 0, 30, 60, 90, 120, 150};
    double speed_table1[] = {-16.588, -16.030, -14.993, -11.803, -6.061, 0.080, 6.061, 11.803, 14.993, 16.030, 16.588};

    // first and fourth argument : length of table
    car.setCalibTable(11, pwm_table0, speed_table0, 11, pwm_table1, speed_table1);

    while (1) {
        car.goStraightCalib(5);
        wait(5);
        car.stop();
        wait(5);
    }
}