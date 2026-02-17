#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    vector<string> readBinaryWatch(int turnedOn)
    {
        /* 概要：0時から11時、0分から59分までのすべての組み合わせを走査し、時と分のビットの合計（点灯数）が turnedOn と一致するものを抽出する。 */
        vector<string> result;
        for (int h = 0; h < 12; ++h)
        {
            for (int m = 0; m < 60; ++m)
            {
                if (__builtin_popcount(h) + __builtin_popcount(m) == turnedOn)
                {
                    result.push_back(to_string(h) + (m < 10 ? ":0" : ":") + to_string(m));
                }
            }
        }
        return result;
    }
};