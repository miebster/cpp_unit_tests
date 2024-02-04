#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../doctest.h"

#include "solution_2.h"

#include "rapidjson/document.h"
#include "rapidjson/filereadstream.h"

#include<iostream>
#include<sstream>

//Signature:
//// Print a floating-point number
//// If decimal_precision == 0: print the minimum precision required to represent the value
//// If decimal_precision > 0: print exactly the specified number of digits following the decimal point, rounding as necessary

//print_float(float value, int decimal_places)

//Test cases:
//print_float(123.456, 0) → “123.456”
//print_float(123.456, 5) → “123.45600”
//print_float(123.456, 1) → “123.5”

TEST_CASE("test_case_1"){
    Solution_2 solution2;
    CHECK(solution2.float_to_string(123.456, 0) == "123.456");
}

TEST_CASE("test_case_2"){
    Solution_2 solution2;
    CHECK(solution2.float_to_string(123.456, 5) == "123.45600");
}

TEST_CASE("test_case_3"){
    Solution_2 solution2;
    CHECK(solution2.float_to_string(123.456, 1) == "123.5");
}

TEST_CASE("test_case_4"){
    Solution_2 solution2;
    CHECK(solution2.float_to_string(123.450, 1) == "123.5");
}

TEST_CASE("test_case_5"){
    Solution_2 solution2;
    CHECK(solution2.float_to_string(123.449, 1) == "123.4");
}

TEST_CASE("test_case_6"){
    Solution_2 solution2;
    CHECK(solution2.float_to_string(123.999, 1) == "124.0");
}

TEST_CASE("test_case_7"){
    Solution_2 solution2;
    CHECK(solution2.float_to_string(-123.999, 1) == "-124.0");
}

