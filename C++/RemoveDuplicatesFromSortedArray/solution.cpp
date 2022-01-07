#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        int removeDuplicates(vector<int>& nums) {
            int k = 0;

            // Collect unique values
            for (int x : nums)
            {
                if (x != nums[k])
                    nums[++k] = x;
            }
            return k + 1;
        }
};

int main()
{
    Solution solution;
    vector<int> num {1,1,2};
    int k = 0;

    k = solution.removeDuplicates(num);
    cout << "K value: " << k << endl;
    for (int i = 0; i < k; i++)
        cout << num[i] << " ";
    return 0;
}
