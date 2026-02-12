#include <vector>
using namespace std;

class Solution
{
public:
    int removeDuplicates(std::vector<int> &nums)
    {
        /*
        1. i<2 : 最初の2要素は、どんな値であっても必ず残す
        2. n> nums[i - 2] : 現在の要素が、すでに確定した部分の「2つ前の要素」より大きい
        （ソート済みなので、2つ前の要素より大きければ、3つ以上の重複にはならない）
        */
        int i = 0;
        for (int n : nums)
        {
            if (i < 2 || n > nums[i - 2])
            {
                nums[i] = n;
                i++;
            }
        }
        return i;
    }
};