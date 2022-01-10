#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
class Solution {
	public:
		int removeElement(vector<int>& nums, int val)
		{
			if (nums.size() == 0)
				return 0;
			int k = 0;
			for (int i = 0; i < nums.size(); i++)
			{
				if (nums[i] != val)
				{
					nums[k++] = nums[i];
				}
			}
			return k;
		}
		int removeElement2(vector<int>& nums, int val)
		{
			nums.erase(remove(nums.begin(), nums.end(), val), nums.end());
			// Erase remove idiom
			//remove(nums.begin(), nums.end(), val);

			cout << "nums size: " << nums.size() << endl;
			return nums.size();
		}
};

int main()
{
	Solution solution;

	vector<int> nums {0, 0, 1, 2, 3, 4, 5};
	int val = 0;
	int k = solution.removeElement2(nums,val);
	cout << "K value: " << k << endl;
	for (int i = 0; i < k; i++)
		cout << nums[i] << " ";

	return 0;
}
