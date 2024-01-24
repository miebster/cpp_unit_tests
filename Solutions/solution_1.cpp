
#include "solution_1.h"

#include <iostream>     // std::cout
#include <algorithm>    // std::sort
#include <vector>       // std::vector
#include <map>          // std::map

using std::vector;
using std::map;

Solution_1::Solution_1()= default;

vector<vector<int>> Solution_1::threeSum(vector<int>& nums) {
    vector<vector<int>> triplets;

    sort(nums.begin(), nums.end());

    map<int, int> value_to_index_map; // {value, index}
    for (int idx = 0; idx < nums.size(); ++idx) {
        value_to_index_map.insert({nums.at(idx), idx});
    }

    int i = 0;
    int j, k;
    int prev_value;
    int target_j_k;
    int target_k;

    while (i < nums.size() - 2) {

        if (nums[i] > 0) {
            // array is sorted, all negative targets have been tried, only positives remain.
            break;
        }
        target_j_k = -nums[i];

        j = i + 1;
        while (j < nums.size() - 1) {

            if (nums[j] + nums[j + 1] > target_j_k)
            {
                break;
            }

            target_k = target_j_k - nums[j];

            if (value_to_index_map.count(target_k) == 1) {
                triplets.push_back(vector<int>{nums[i], nums[j], target_k});
            }

            // increment j
            prev_value = nums.at(j++);
            while (j < nums.size() && nums.at(j) == prev_value) {j++;}
            // cout << "new j " << j << endl;
        }

        // increment i
        prev_value = nums.at(i++);
        while (i < nums.size() && nums.at(i) == prev_value) {i++;}
        // cout << "new i " << i << endl;

    }

    return triplets;
};
