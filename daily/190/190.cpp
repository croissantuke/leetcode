#include <cstdint>

class Solution
{
public:
    uint32_t reverseBits(uint32_t n)
    {
        /* 入力値の最下位ビットを順次取り出し、結果を左シフトしながら追加していくことでビット列を反転させる。 */
        uint32_t result = 0;
        for (int i = 0; i < 32; i++)
        {
            result = (result << 1) | (n & 1);
            n >>= 1;
        }
        return result;
    }
};