#include <iostream>
#include <vector>

using namespace std;

class Solution {
	public:
		vector<int> plusOne(vector<int>& digits) {
			int i;

			// Traverse backwards and add 1
			i = digits.size() - 1;
			for (; i >= 0; i--)
			{
				if (digits[i] == 9)
				{
					digits [i] = 0;
				}
				else
				{
					digits[i] += 1;
					return digits;
				}
			}
			digits[0] = 1;
			digits.push_back(0);
			return digits;
		}
};

int main()
{
	Solution solution;
	vector<int> digits = {3,8,9};
	digits = solution.plusOne(digits);
	for(int i : digits)
		cout << i;
	cout << endl;
	return 0;
}
