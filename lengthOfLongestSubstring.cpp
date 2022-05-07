/*
 *  求无重复字符串的最长子串
 */

#include <iostream>

using namespace std;

class Solution {
    public:
        // 暴力求法
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
            
            cout << "final: " << finalstr << endl;
            return finalstr.size();
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
    string words = "";
//    cin >> words;

    Solution so;
    cout << so.lengthOfLongestSubstring(words) << endl;

    return 0;
}
