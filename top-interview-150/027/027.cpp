#include <vector>
using namespace std;

class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        /*
        概要：配列を走査し、valと一致しない要素を配列の前方に詰め直す。
        書き込みポインタ k を使用し、nums[i] が val でない場合のみ nums[k] に代入して k を進める。
        */
        int k = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != val)
            {
                nums[k] = nums[i];
                k++;
            }
        }
        return k;
    }
};