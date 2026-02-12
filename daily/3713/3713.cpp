#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int longestBalanced(string s)
    {
        /* 概要：すべての部分文字列を走査し、各部分文字列において「出現している文字の種類数 × 最大の出現頻度 == 部分文字列の長さ」が成立するかをチェックすることで、すべての文字が等しい回数出現しているか判定する。 */
        int n = s.length();
        int maxLen = 0;

        for (int i = 0; i < n; ++i)
        {
            vector<int> freq(26, 0);
            int distinctCount = 0;
            int maxFreq = 0;

            for (int j = i; j < n; ++j)
            {
                int charIdx = s[j] - 'a';
                if (freq[charIdx] == 0)
                {
                    distinctCount++;
                }
                freq[charIdx]++;
                maxFreq = max(maxFreq, freq[charIdx]);

                if (maxFreq * distinctCount == (j - i + 1))
                {
                    maxLen = max(maxLen, j - i + 1);
                }
            }
        }
        return maxLen;
    }
};