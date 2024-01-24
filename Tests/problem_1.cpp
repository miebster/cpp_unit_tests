#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "solution_1.h"

#include <rapidjson/document.h>
#include <rapidjson/filereadstream.h>

#include<iostream>
#include<sstream>

using std::string;
using std::set;
using std::stringstream;
using std::cout;
using std::endl;

/*
vector<vector<int>> result = solution1.threeSum(q1);
//    for (vector r1 : result) {
//        for (int r2 : r1) {
//            std::cout << r2 << ' ';
//        };
//        std::cout << std::endl;
//    };
 */

std::vector<std::vector<int>> loadJsonVectorVectorInt(const std::string& filename) {
    // Open the file for reading
    FILE* fp = fopen(filename.c_str(), "rb");
    if (fp == nullptr) {
        throw std::runtime_error("Could not open file for reading");
    }

    char readBuffer[65536];
    rapidjson::FileReadStream is(fp, readBuffer, sizeof(readBuffer));

    // Parse the JSON file
    rapidjson::Document doc;
    doc.ParseStream(is);
    fclose(fp);

    if (!doc.IsArray()) {
        throw std::runtime_error("JSON does not contain an array at the top level");
    }

    std::vector<std::vector<int>> result;
    for (const auto& array : doc.GetArray()) {
        if (!array.IsArray()) {
            throw std::runtime_error("JSON does not contain an array of arrays");
        }

        std::vector<int> innerVec;
        for (const auto& val : array.GetArray()) {
            if (!val.IsInt()) {
                throw std::runtime_error("JSON array contains non-integer types");
            }
            innerVec.push_back(val.GetInt());
        }
        result.push_back(innerVec);
    }

    return result;
}


std::vector<int> loadJsonVectorInt(const std::string& filename) {
    // Open the file for reading
    FILE* fp = fopen(filename.c_str(), "rb");
    if (fp == nullptr) {
        throw std::runtime_error("Could not open file for reading");
    }

    char readBuffer[65536];
    rapidjson::FileReadStream is(fp, readBuffer, sizeof(readBuffer));

    // Parse the JSON file
    rapidjson::Document doc;
    doc.ParseStream(is);
    fclose(fp);

    if (!doc.IsArray()) {
        throw std::runtime_error("JSON does not contain an array at the top level");
    }

    std::vector<int> result;
    for (const auto& val : doc.GetArray()) {
        if (!val.IsInt()) {
            throw std::runtime_error("JSON array contains non-integer types");
        }

        result.push_back(val.GetInt());
    }

    return result;
}

bool compareVectorVectorInts(const std::vector<std::vector<int>>& vv_a,
                     const std::vector<std::vector<int>>& vv_b) {

    bool pass = true;

    set<set<int>> ss_a;
    for (auto v_a : vv_a) {
        set<int> s_a(v_a.begin(), v_a.end());
        ss_a.insert(s_a);
    }

    set<set<int>> ss_b;
    for (auto v_b : vv_b) {
        set<int> s_b(v_b.begin(), v_b.end());
        ss_b.insert(s_b);
    }

    set<set<int>> ss_a_not_in_b;
    for (auto s_a : ss_a) {
        if (ss_b.find(s_a) == ss_b.end()) {
            ss_a_not_in_b.insert(s_a);
        }
    }

    set<set<int>> ss_b_not_in_a;
    for (auto s_b : ss_b) {
        if (ss_a.find(s_b) == ss_a.end()) {
            ss_b_not_in_a.insert(s_b);
        }
    }

    if (ss_a.size() != ss_b.size()) {
        pass = false;
        cout << "number of sets in A: " << ss_a.size() << endl;
        cout << "number of sets in B: " << ss_b.size() << endl;
    }

    if (!ss_a_not_in_b.empty()) {
        pass = false;
        cout << "sets in A that are not in B: " << endl;
        for (const auto &s_a_not_in_b: ss_a_not_in_b) {
            cout << "[";
            for (auto a_not_in_b: s_a_not_in_b) {
                cout << a_not_in_b << ", ";
            }
            cout << "]" << endl;
        }
    }

    if (!ss_b_not_in_a.empty()) {
        pass = false;
        cout << "sets in B that are not in A: " << endl;
        for (const auto &s_b_not_in_a: ss_b_not_in_a) {
            cout << "[";
            for (auto b_not_in_a: s_b_not_in_a) {
                cout << b_not_in_a << ", ";
            }
            cout << "]" << endl;
        }
    }

    return pass;
}

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

TEST_CASE("test_case_4") {

    string file_path = __FILE__;
    string dir_path = file_path.substr(0, file_path.rfind('/'));

    string q_file = dir_path + "/p1q4.json";
    vector<int> question = loadJsonVectorInt(q_file);

    string a_file = dir_path + "/p1a4.json";
    vector<vector<int>> answer = loadJsonVectorVectorInt(a_file);

    Solution_1 solution1;
    vector<vector<int>> result = solution1.threeSum(question);

    CHECK(compareVectorVectorInts(answer, result));

}



