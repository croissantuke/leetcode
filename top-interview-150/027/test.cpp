#include <iostream>
#include <vector>
#include <string>

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

void runTest(vector<int> nums, int val, string testName)
{
    Solution s;
    cout << "--- " << testName << " ---" << endl;
    cout << "Input:  nums = [";
    for (int i = 0; i < nums.size(); ++i)
    {
        cout << nums[i] << (i == nums.size() - 1 ? "" : ", ");
    }
    cout << "], val = " << val << endl;

    int k = s.removeElement(nums, val);

    cout << "Output k: " << k << endl;
    cout << "Result:  [";
    for (int i = 0; i < k; ++i)
    {
        cout << nums[i] << (i == k - 1 ? "" : ", ");
    }
    cout << "]" << endl
         << endl;
}

int main()
{
    runTest({3, 2, 2, 3}, 3, "Example 1");
    runTest({0, 1, 2, 2, 3, 0, 4, 2}, 2, "Example 2");
    runTest({1}, 1, "Single Element Match");
    runTest({1, 2, 3}, 4, "No Match");
    return 0;
}