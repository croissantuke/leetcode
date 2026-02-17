#include <iostream>
#include <cstdint>
#include <bitset>
#include <string>

using namespace std;

class Solution
{
public:
    uint32_t reverseBits(uint32_t n)
    {
        /* 概要：32回ループを回し、入力値の最下位ビットを順次取り出し、結果を左シフトしながら追加していくことでビット列を反転させる。 */
        uint32_t result = 0;
        for (int i = 0; i < 32; i++)
        {
            result = (result << 1) | (n & 1);
            n >>= 1;
        }
        return result;
    }
};

void runTest(uint32_t n, string testName)
{
    Solution sol;
    uint32_t result = sol.reverseBits(n);

    cout << "--- " << testName << " ---" << endl;
    cout << "Input:  " << bitset<32>(n) << " (" << n << ")" << endl;
    cout << "Output: " << bitset<32>(result) << " (" << result << ")" << endl;
    cout << "---------------------------------" << endl;
}

int main()
{
    runTest(43261596, "Example 1");
    runTest(0b11111111111111111111111111111101, "Example 2");
    runTest(0, "All Zeros");
    runTest(4294967295, "All Ones");
    return 0;
}