#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

class Solution
{
public:
    double champagneTower(int poured, int query_row, int query_glass)
    {
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

void runTest(int poured, int query_row, int query_glass, double expected)
{
    Solution sol;
    double result = sol.champagneTower(poured, query_row, query_glass);
    cout << "Input: poured=" << poured << ", row=" << query_row << ", glass=" << query_glass << endl;
    cout << "Output: " << fixed << setprecision(5) << result << " (Expected: " << expected << ")" << endl;
    cout << "---------------------------------" << endl;
}

int main()
{
    runTest(1, 1, 1, 0.00000);
    runTest(2, 1, 1, 0.50000);
    runTest(100000009, 33, 17, 1.00000);
    return 0;
}