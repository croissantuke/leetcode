#include <vector>
using namespace std;

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        /*
        概要：各要素を1回のみ許可する。
        書き込みポインタ k を使い、現在の要素 n が直前に書き込んだ nums[k-1]
        より大きければ（＝新しい数字が現れたら）採用して上書きする。
        */
        int k = 0;
        for (int n : nums)
        {
            if (k < 1 || n > nums[k - 1])
            {
                nums[k] = n;
                k++;
            }
        }
        return k;
    }
};