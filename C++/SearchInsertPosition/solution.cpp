#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
		// Initialize low and high where low is the starting index
		// While low is less than or equal to high
		// find mid index
		// if the mid index value is less than the target
		// low will be mid + 1
		// else high will be mid - 1
		// return low

		int low, high;

		low = 0;
		high = nums.size() - 1;

		while (low <= high)
		{
			int mid = low + (high - low)/2;
			
			if (nums[mid] < target)
				low = mid + 1;
			else
				high = mid - 1;
		}
		return low;
    }
	int searchInsert2(vector<int>& nums, int target) {

		return lower_bound(nums.begin(), nums.end(), target) - nums.begin();
	}
};

int main()
{
	Solution solution;

	vector<int> nums = {0,1,4,5,8,10};
	int target = 6;
	cout << "Position: " << solution.searchInsert(nums,target) << endl;
	cout << "Position: " << solution.searchInsert2(nums,target) << endl;
	return 0;
}
