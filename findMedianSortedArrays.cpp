/**
  * 求解两有序数组的中位数
  */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    /**
      * 暴力求解：时间复杂度取决于排序算法的时间复杂度（时间复杂度O(m+n)）
      */
//    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
//        double median_num = 0.0;
//
//        for (int i = 0; i < nums2.size(); i++)
//            nums1.push_back(nums2[i]);
//
//        sort(nums1.begin(), nums1.end());
//
//        const int length = nums1.size();
//
//        if (length % 2 == 0)
//            return ((double)nums1[(length/2)-1] + (double)nums1[(length/2)]) / 2.0;
//        else
//            return (double)nums1[length/2.0];
//    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        return 1.0;
    }
};

int main()
{
    vector<int>nums1 = {3, 8, 9, 10};
    vector<int>nums2 = {2, 4, 6, 12, 18, 20};
    Solution *solution = new Solution();
    cout << solution -> findMedianSortedArrays(nums1, nums2) << endl;

    return 0;
}
