//
// Created by Sisu on 3/15/2016.
//

/*
 * Given a collection of distinct numbers, return all possible permutations.
 * For example,
 * [1,2,3] have the following permutations:
 * [1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1].
 */

#include <iostream>
#include <vector>
#include <iterator>

class Solution {
private:
    void helper(std::vector<int>& nums, std::vector<std::vector<int>>& res, int pos) {
        if (pos >= nums.size()) { res.push_back(nums); return; }
        for (int i = pos; i < nums.size(); ++i) {
            // if nums[i] == nums[pos], then we need to skip. see PermutationsII
            std::swap(nums[pos], nums[i]);
            helper(nums, res, pos+1);
            std::swap(nums[pos], nums[i]);
        }
    }

public:
    std::vector<std::vector<int>> permuteUnique2(std::vector<int> const& nums) {
        std::vector<std::vector<int>> res;
        std::vector<int> tmp = nums;
        helper(tmp, res, 0);
        return res;
    }

public:
    std::vector<std::vector<int>> permute(std::vector<int> const & nums) { // 16 ms
        std::vector<std::vector<int>> res[2];
        int cur = 0;

        for (auto const& val : nums) {
            int nxt = (cur+1)%2;
            res[nxt].clear();
            if (res[cur].empty()) {
                res[nxt].push_back({val});
            } else {
                for (auto& cur_res : res[cur]) {
                    for (int i = 0; i <= cur_res.size(); ++i) { // note the "<=" here
                        auto tmp = cur_res;
                        tmp.insert(tmp.begin() + i, val);
                        res[nxt].push_back(tmp);
                    }
                }
            }
            cur = nxt;
        }

        return res[cur];
    }
};

int main() {
    Solution sol;
    std::vector<std::vector<int>> tests = {
            {}
            , {1}
            , {1,2}
            , {1,2,3}
            , {1,2,3,4,5,6}
    };
    std::ostream_iterator<int> out_it(std::cout, ", ");

    for (auto const& test: tests) {
        std::cout << std::endl << "inputs:";
        std::copy(test.begin(), test.end(), out_it);
        std::cout << std::endl;

        auto res = sol.permute(test);
        std::cout << "result size: " << res.size() << std::endl;
        for (auto const& val : res) {
            std::cout << "  ";
            std::copy(val.begin(), val.end(), out_it);
            std::cout << std::endl;
        }
    }

    return 0;
}