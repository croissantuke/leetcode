#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        /*
        概要：ソート済み配列から重複を完全に排除し、ユニークな要素のみを先頭に集める。
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

void runTest(vector<int> nums, string testName)
{
    Solution s;
    cout << "--- " << testName << " ---" << endl;
    cout << "Input:  [";
    for (int i = 0; i < nums.size(); ++i)
    {
        cout << nums[i] << (i == nums.size() - 1 ? "" : ", ");
    }
    cout << "]" << endl;

    int k = s.removeDuplicates(nums);

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
    runTest({1, 1, 2}, "Example 1");
    runTest({0, 0, 1, 1, 1, 2, 2, 3, 3, 4}, "Example 2");
    runTest({1, 2, 3, 4, 5}, "No Duplicates");
    runTest({1, 1, 1, 1}, "All Same Elements");
    return 0;
}