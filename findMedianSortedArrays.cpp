/**
  * 求解两数组的中位数
  */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    /**
      * 先将两数组合并，再排序，得出中位数
      */
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        double median_num = 0.0;

        for (int i = 0; i < nums2.size(); i++)
            nums1.push_back(nums2[i]);

        sort(nums1.begin(), nums1.end());

        const int length = nums1.size();

        if (length % 2 == 0)
            return ((double)nums1[(length/2)-1] + (double)nums1[(length/2)]) / 2.0;
        else
            return (double)nums1[length/2.0];

        return median_num;
    }
};

int main()
{
    vector<int>nums1 = {3, 4, 5, 6};
    vector<int>nums2 = {1, 2};
    Solution *solution = new Solution();
    cout << solution -> findMedianSortedArrays(nums1, nums2) << endl;

    return 0;
}
