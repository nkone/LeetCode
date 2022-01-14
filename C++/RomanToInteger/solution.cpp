#include <iostream>
#include <string>

using namespace std;

int roman(char c)
{
	switch(c)
	{
		case 'I': return 1;
		case 'V': return 5;
		case 'X': return 10;
		case 'L': return 50;
		case 'C': return 100;
		case 'D': return 500;
		case 'M': return 1000;
	}
	return 0;
}

class Solution {
	public:
		int romanToInt (string s)
		{
			int sum;
			int len;

			sum = 0;
			len = s.length();
			if (!len)
				return 0;
			for (int i = 0; i < len; i++)
			{
				int curr = roman(s[i]);
				int next = roman(s[i + 1]);
				if (curr < next)
					sum -= curr;
				else
					sum += curr;
			}
			return sum;
		}
};

int main()
{
	Solution solution;
	string Roman;
	int romanInteger;

	romanInteger = 0;
	Roman = "IV";
	cout << "Roman: " << Roman << endl;
	romanInteger = solution.romanToInt(Roman);
	cout << "Integer: " << romanInteger << endl;
	Roman = "LVIII";
	cout << "Roman: " << Roman << endl;
	romanInteger = solution.romanToInt(Roman);
	cout << "Integer: " << romanInteger << endl;
	Roman = "MCMXCIV";
	cout << "Roman: " << Roman << endl;
	romanInteger = solution.romanToInt(Roman);
	cout << "Integer: " << romanInteger << endl;
	return 0;
}
