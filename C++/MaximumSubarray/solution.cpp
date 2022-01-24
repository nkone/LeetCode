#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
		int sum, max;

		sum = nums[0];
		max = sum;
		for (int i = 0; i < nums.size(); i++)
		{
			sum = nums[i];
			if (sum > max)
				max = sum;
			for (int k = i+1; k < nums.size(); k++)
			{
				sum += nums[k];
				if (sum > max)
					max = sum;
			}
		}
		return max;
    }
	int maxSubArray2(vector<int>& nums) {
		int sum, max;
		sum = nums[0];
		max = sum;
		for (int i = 1; i < nums.size(); i++)
		{
			sum = ((sum + nums[i]) < nums[i]) ? nums[i] : (sum + nums[i]);
			max = (sum < max) ? max : sum;
		}
		return max;
	}
};

int main()
{
	Solution solution;
	vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
	vector<int> nums2 = {5,4,-1,7,8};
	vector<int> nums3 = {-2,1};

	cout << "Max sum: " << solution.maxSubArray(nums) << endl; 
	cout << "Max sum: " << solution.maxSubArray(nums2) << endl; 
	cout << "Max sum: " << solution.maxSubArray(nums3) << endl; 
	cout << "Max sum: " << solution.maxSubArray2(nums) << endl; 
	cout << "Max sum: " << solution.maxSubArray2(nums2) << endl; 
	cout << "Max sum: " << solution.maxSubArray2(nums3) << endl; 
	return 0;
}
