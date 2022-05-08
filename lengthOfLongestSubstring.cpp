/*
 *  求无重复字符串的最长子串
 */

#include <iostream>
#include <set>
#include <map>

using namespace std;

class Solution {
    public:
        // 暴力求解法
        int lengthOfLongestSubstring(string s) {
            size_t slen = s.size();
            string tmpstr, finalstr;

            if (slen == 0)
                return 0;

            tmpstr = finalstr = s[0];
            for (int i = 1; i < slen; i++) {
                tmpstr += s[i];
                if (checkSameLetter(tmpstr)) {
                    tmpstr = tmpstr.substr(1, tmpstr.size());
                } else {
                    if (finalstr.size() < tmpstr.size())
                        finalstr = tmpstr;
                }
            }
            
            return finalstr.size();
        }

        // 滑动窗思想，双指针实现
        int lengthOfLongestSubstringWithDoublePointer(string s) {
            size_t slen = s.size();

            if (slen == 0)
                return 0;

            int length = 0, maxLength = 0;
            char *p1 = &s[0], *p2 = &s[0];
            set<char> chs;

            while (*p1) {
                int ret = chs.insert(*p1).second;
                if (!ret) {
                    // 插入失败
                    chs.erase(*p2);
                    p2++;
                    length--;
                } else {
                    // 插入成功
                    p1++;
                    length++;
                }
                if (length > maxLength)
                    maxLength = length;
            }

            return maxLength;
        }

    private:
        bool checkSameLetter(string s) {
            size_t slen = s.size();

            for (int i = 0; i < slen; i++) {
                for (int j = 0; j < slen; j++) {
                    if (i == j)
                        continue;
                    if (s[i] == s[j])
                        return true;
                }
            }

            return false;
        }
};

int main()
{
    string words = "pwwkew";
    cin >> words;

    Solution so;
    cout << "滑动窗思想：" << so.lengthOfLongestSubstringWithDoublePointer(words) << endl;
    cout << "暴力求解：" << so.lengthOfLongestSubstring(words) << endl;

    return 0;
}
