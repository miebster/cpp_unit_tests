#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "solution_1.h"


/*
vector<vector<int>> result = solution1.threeSum(q1);
//    for (vector r1 : result) {
//        for (int r2 : r1) {
//            std::cout << r2 << ' ';
//        };
//        std::cout << std::endl;
//    };
 */

TEST_CASE("test_case_1"){
    Solution_1 solution1;
    vector<int> q1 {-1,0,1,2,-1,-4};
    vector<vector<int>> a1 {{-1,-1,2},{-1,0,1}};
    CHECK(solution1.threeSum(q1) == a1);
}

TEST_CASE("test_case_2"){
    Solution_1 solution1;
    vector<int> q1 { 0,1,1 };
    vector<vector<int>> a1 { };
    CHECK(solution1.threeSum(q1) == a1);
}

TEST_CASE("test_case_3"){
    Solution_1 solution1;
    vector<int> q1 {0,0,0};
    vector<vector<int>> a1 {{0,0,0}};
    CHECK(solution1.threeSum(q1) == a1);
}

