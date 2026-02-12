#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        /*
        '''
        概要：ソート済み配列から、同じ数字が3回以上出現しないように加工する。
        書き込みポインタ k を使い、条件を満たす要素を配列の前方に詰め直す。
        '''
        */
        int k = 0;
        for (int n : nums)
        {
            if (k < 2 || n > nums[k - 2])
            {
                nums[k] = n;
                k++;
            }
        }
        return k;
    }
};

void runTest(vector<int> nums)
{
    Solution s;

    cout << "Input:  [";
    for (int i = 0; i < nums.size(); ++i)
    {
        cout << nums[i] << (i == nums.size() - 1 ? "" : ", ");
    }
    cout << "]" << endl;

    int k = s.removeDuplicates(nums);

    cout << "Output k: " << k << endl;
    cout << "Result Array: [";
    for (int i = 0; i < k; ++i)
    {
        cout << nums[i] << (i == k - 1 ? "" : ", ");
    }
    cout << "]" << endl;
    cout << "---------------------------------" << endl;
}

int main()
{
    runTest({1, 1, 1, 2, 2, 3});
    runTest({0, 0, 1, 1, 1, 1, 2, 3, 3});
    runTest({1, 2, 3});
    runTest({});

    return 0;
}