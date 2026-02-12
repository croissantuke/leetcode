#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        int p1 = m - 1;
        int p2 = n - 1;
        int p = m + n - 1;

        while (p2 >= 0)
        {
            if (p1 >= 0 && nums1[p1] > nums2[p2])
            {
                nums1[p] = nums1[p1];
                p1--;
            }
            else
            {
                nums1[p] = nums2[p2];
                p2--;
            }
            p--;
        }
    }
};

void runTest(vector<int> nums1, int m, vector<int> nums2, int n, string testName)
{
    Solution s;
    cout << "--- " << testName << " ---" << endl;
    cout << "Input nums1: [";
    for (int i = 0; i < nums1.size(); ++i)
        cout << nums1[i] << (i == nums1.size() - 1 ? "" : ", ");
    cout << "], m = " << m << endl;
    cout << "Input nums2: [";
    for (int i = 0; i < nums2.size(); ++i)
        cout << nums2[i] << (i == nums2.size() - 1 ? "" : ", ");
    cout << "], n = " << n << endl;

    s.merge(nums1, m, nums2, n);

    cout << "Result: [";
    for (int i = 0; i < nums1.size(); ++i)
        cout << nums1[i] << (i == nums1.size() - 1 ? "" : ", ");
    cout << "]" << endl
         << endl;
}

int main()
{
    runTest({1, 2, 3, 0, 0, 0}, 3, {2, 5, 6}, 3, "Example 1");
    runTest({1}, 1, {}, 0, "Example 2");
    runTest({0}, 0, {1}, 1, "Example 3");
    runTest({4, 5, 6, 0, 0, 0}, 3, {1, 2, 3}, 3, "All nums2 smaller");
    return 0;
}