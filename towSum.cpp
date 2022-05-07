/*
 *  两数之和，C++实现，时间复杂度小于O(N^2)
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        vector<int> twoSum(vector<int> &nums, int target) {
            for (int i = 0; i < nums.size() - 1; i++) {
                for (int j = i + 1; j < nums.size(); j++) {
                    if (target == nums[i] + nums[j])
                        return {i, j};
                }
            }

            return {};
        }
};

int main()
{
    int target = 6;
    vector<int> nums{3, 3};

    Solution so;
    vector<int> index = so.twoSum(nums, target);

    for (int i : index)
        cout << i;
    cout << endl;

    return 0;
}
