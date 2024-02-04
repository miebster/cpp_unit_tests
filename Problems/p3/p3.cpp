#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../doctest.h"

#include "Solution_3.h"

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

TEST_CASE("positives_1"){
    Solution_3 solution3;
    CHECK(solution3.float_to_string(123.456, 3) == "123.456");
}

TEST_CASE("positives_2"){
    Solution_3 solution3;
    CHECK(solution3.float_to_string(123.456, 5) == "123.45600");
}

TEST_CASE("positives_3"){
    Solution_3 solution3;
    CHECK(solution3.float_to_string(123.456, 1) == "123.5");
}

TEST_CASE("positives_4"){
    Solution_3 solution3;
    CHECK(solution3.float_to_string(123.451, 1) == "123.5");
}

TEST_CASE("positives_5"){
    Solution_3 solution3;
    CHECK(solution3.float_to_string(123.449, 1) == "123.4");
}

TEST_CASE("positives_6"){
    Solution_3 solution3;
    CHECK(solution3.float_to_string(123.999, 1) == "124.0");
}

TEST_CASE("negatives_1"){
    Solution_3 solution3;
    CHECK(solution3.float_to_string(-123.456, 3) == "-123.456");
}

TEST_CASE("negatives_2"){
    Solution_3 solution3;
    CHECK(solution3.float_to_string(-123.456, 5) == "-123.45600");
}

TEST_CASE("negatives_3"){
    Solution_3 solution3;
    CHECK(solution3.float_to_string(-123.456, 1) == "-123.5");
}

TEST_CASE("negatives_4"){
    Solution_3 solution3;
    CHECK(solution3.float_to_string(-123.451, 1) == "-123.5");
}

TEST_CASE("negatives_5"){
    Solution_3 solution3;
    CHECK(solution3.float_to_string(-123.449, 1) == "-123.4");
}

TEST_CASE("negatives_6"){
    Solution_3 solution3;
    CHECK(solution3.float_to_string(-123.999, 1) == "-124.0");
}

TEST_CASE("zeros_1"){
    Solution_3 solution3;
    CHECK(solution3.float_to_string(0.0, 1) == "0.0");
}

TEST_CASE("zeros_2"){
    Solution_3 solution3;
    CHECK(solution3.float_to_string(0.0, 1) == "0.0");
}

TEST_CASE("zeros_3"){
    Solution_3 solution3;
    CHECK(solution3.float_to_string(0.0, 3) == "0.000");
}

TEST_CASE("zeros_4"){
    Solution_3 solution3;
    CHECK(solution3.float_to_string(-0.0, 1) == "0.0");
}

TEST_CASE("small_1"){
    Solution_3 solution3;
    CHECK(solution3.float_to_string(0.123, 1) == "0.1");
}

TEST_CASE("small_2"){
    Solution_3 solution3;
    CHECK(solution3.float_to_string(0.123, 3) == "0.123");
}

TEST_CASE("small_3"){
    Solution_3 solution3;
    CHECK(solution3.float_to_string(0.123, 3) == "0.123");
}

TEST_CASE("small_4"){
    Solution_3 solution3;
    CHECK(solution3.float_to_string(-0.123, 3) == "-0.123");
}

TEST_CASE("smaller_1"){
    Solution_3 solution3;
    CHECK(solution3.float_to_string(0.00123, 1) == "0.0");
}

TEST_CASE("smaller_2"){
    Solution_3 solution3;
    CHECK(solution3.float_to_string(0.00123, 5) == "0.00123");
}

TEST_CASE("smaller_3"){
    Solution_3 solution3;
    CHECK(solution3.float_to_string(0.00123, 3) == "0.001");
}

TEST_CASE("smaller_4"){
    Solution_3 solution3;
    CHECK(solution3.float_to_string(-0.00123, 5) == "-0.00123");
}

TEST_CASE("smaller_5"){
    Solution_3 solution3;
    CHECK(solution3.float_to_string(0.00173, 3) == "0.002");
}

TEST_CASE("smallest_1"){
    Solution_3 solution3;
    CHECK(solution3.float_to_string(1.234e-8, 3) == "0.000");
}

TEST_CASE("big_1"){
    Solution_3 solution3;
    CHECK(solution3.float_to_string(123456.789, 7) == "123456.7890625");
}

TEST_CASE("big_2"){
    Solution_3 solution3;
    CHECK(solution3.float_to_string(123456.789, 3) == "123456.789");
}

TEST_CASE("big_3"){
    Solution_3 solution3;
    CHECK(solution3.float_to_string(123456.789, 4) == "123456.7891");
}

TEST_CASE("big_4"){
    Solution_3 solution3;
    CHECK(solution3.float_to_string(-123456.789, 4) == "-123456.7891");
}

TEST_CASE("bigger_1"){
    Solution_3 solution3;
    CHECK(solution3.float_to_string(-123.456e5, 0) == "-12345600");
}

TEST_CASE("bigger_2"){
    Solution_3 solution3;
    CHECK(solution3.float_to_string(-123.456e2, 1) == "-12345.6");
}

TEST_CASE("biggest_1"){
    Solution_3 solution3;
    CHECK(solution3.float_to_string(-123.456e27, 1) == "-12345600.0");
}