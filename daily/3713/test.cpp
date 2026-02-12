#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int longestBalancedSubstring(string s)
    {
        int n = s.length();
        int maxLen = 0;
        for (int i = 0; i < n; ++i)
        {
            int freq[26] = {0};
            int distinct = 0;
            int maxF = 0;
            for (int j = i; j < n; ++j)
            {
                int c = s[j] - 'a';
                if (freq[c] == 0)
                    distinct++;
                freq[c]++;
                if (freq[c] > maxF)
                    maxF = freq[c];
                if (maxF * distinct == (j - i + 1))
                {
                    maxLen = max(maxLen, j - i + 1);
                }
            }
        }
        return maxLen;
    }
};

void runTest(string s, int expected)
{
    Solution sol;
    int result = sol.longestBalancedSubstring(s);
    cout << "Input: s = \"" << s << "\"" << endl;
    cout << "Output: " << result << " (Expected: " << expected << ")" << endl;
    cout << (result == expected ? "PASS" : "FAIL") << endl;
    cout << "---------------------------------" << endl;
}

int main()
{
    runTest("abbac", 4);
    runTest("zzabccy", 4);
    runTest("aba", 2);
    runTest("aaaaa", 5);
    runTest("abcdef", 6);
    return 0;
}