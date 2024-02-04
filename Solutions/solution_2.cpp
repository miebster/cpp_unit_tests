#include "solution_2.h"

#include <iostream>
#include <cmath>

Solution_2::Solution_2() = default;

std::string Solution_2::float_to_string(float value, int decimal_places) {

    //// Print a floating-point number
    //// If decimal_precision == 0: print the minimum precision required to represent the value
    //// If decimal_precision > 0: print exactly the specified number of digits following the decimal point, rounding as necessary
    std::string result;
    int sign = 1;
    if (value < 0) {
        value = -value;
        sign = -1;
    }

    int whole = (int) (value);
    float decimal = value - (float) whole ;

    if (decimal_places < 0 || decimal_places > 7 ) {
        decimal_places = 7;
    }

    if (decimal_places == 0) {
        float diff = 1.0;
        while (fabs(diff) > 0.01) {
            decimal *= 10;
            diff = (float) (int) (decimal) - decimal;
            decimal_places++;
        }
    } else {
        for (int i = 0; i < decimal_places; i++) {
            decimal *= 10;
        }
    }

    int int_decimal = (int) decimal;
    float remainder = decimal - int_decimal;

    if (remainder >= 0.5) {
        int_decimal += 1;
    }

    for (int i = 0; i < decimal_places; i++) {
        result.insert(0, 1, char (0x30 + int_decimal % 10));
        int_decimal /= 10;
    }

    // if the rounding step added a digit, it should flow
    // over the decimal point into the whole number.
    if (int_decimal > 0) {
        whole += 1;
    }

    result.insert(0, 1, '.');

    while (whole > 0) {
        int num = whole % 10;
        result.insert(0, 1, char (0x30 + num));

        whole /= 10;
    }

    if (sign < 0) {
        result.insert(0, 1, '-');
    }

    return result;
};
