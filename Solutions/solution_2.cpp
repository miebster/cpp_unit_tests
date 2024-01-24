
#include "solution_2.h"

#include <iostream>     // std::cout
#include <algorithm>    // std::sort
#include <vector>       // std::vector
#include <map>          // std::map
#include <set>

using std::vector;
using std::map;
using std::set;

Solution_2::Solution_2()= default;

vector<vector<int>> Solution_2::threeSum(vector<int>& nums_) {
    set<vector<int>> triplets;

    vector<int> nums;
    map<int, int> count; // {value, index}
    for (int idx = 0; idx < nums_.size(); ++idx) {
        count[nums_.at(idx)] += 1;
        if (count[nums_.at(idx)] < 4)
        {
            nums.push_back(nums_.at(idx));
        }
    }
    sort(nums.begin(), nums.end());

    map<int, int> value_to_index_map; // {value, index}
    for (int idx = 0; idx < nums.size(); ++idx) {
        value_to_index_map.insert({nums.at(idx), idx});
    }

    int i = 0, j = 1, k = 2;
    int target_j_k;
    int target_k;

    for (i = 0; i < j; i++) {
        // if (nums[i] > 0) {
        //     // array is sorted, all negative targets have been tried, only positives remain.
        //     break;
        // }
        target_j_k = -nums[i];
        for (j = i + 1; j < nums.size() - 1; j++) {
            // if (nums[j] + nums[j + 1] > target_j_k)
            // {
            //     break;
            // }
            if (value_to_index_map.count(-nums[i] - nums[j]) == 1) {
                int idx = value_to_index_map[-nums[i] - nums[j]];
                if (idx != i && idx != j) {
                    vector<int> triplet{nums[i], nums[j], -nums[i] - nums[j]};
                    sort(triplet.begin(), triplet.end());
                    triplets.insert(triplet);
                }
            }
        }
    }

    vector<vector<int>> triplets_vector;
    for (auto v : triplets) {
        triplets_vector.push_back(v);
    }

    return triplets_vector;
};
