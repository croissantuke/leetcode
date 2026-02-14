#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    double champagneTower(int poured, int query_row, int query_glass)
    {
        /* 概要：2次元配列を使用して各グラスに流入するシャンパンの総量をシミュレーションする。各グラスで1.0を超えた溢れ分を計算し、直下の2つのグラスへ均等に分配していく。 */
        double dp[102][102] = {0.0};
        dp[0][0] = (double)poured;

        for (int r = 0; r <= query_row; r++)
        {
            for (int c = 0; c <= r; c++)
            {
                double overflow = (dp[r][c] - 1.0) / 2.0;
                if (overflow > 0)
                {
                    dp[r + 1][c] += overflow;
                    dp[r + 1][c + 1] += overflow;
                }
            }
        }

        return dp[query_row][query_glass] > 1.0 ? 1.0 : dp[query_row][query_glass];
    }
};