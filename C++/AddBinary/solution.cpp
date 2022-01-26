#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int binaryStringToInt(string a)
{
	int ret;
	int size;

	size = a.size();
	ret = 0;
	int binary = 1;
	// Traverse backwards
	for (int i = size - 1; i >= 0; i--)
	{
		if (a[i] == '1')
		{
			ret += binary;
		}
		else
			ret += 0;
		binary *= 2;
	}

	return ret;
}

string intToBinaryString(int a)
{

	char arr[32] = {0};
	int i = 0;

	while(a)
	{
		arr[i++] = (a % 2) ? '1' : '0';
		a /= 2;
	}
	cout << "i: " << i << endl;
	string ret (i, '0');

	i--;
	// Copy backwards
	for (int k = 0; i >= 0; i--, k++)
	{
		ret[k] = arr[i];
	}

	return ret;
}

class Solution {
	public:
		string addBinary(string a, string b) {
			int numA;
			int numB;

			numA = binaryStringToInt(a);
			numB = binaryStringToInt(b);

			int total;

			total = numA + numB;

			string ret = "0";
			if (!total)
				return ret;

			ret = intToBinaryString(total);

			return ret;
    }
		string addBinary2(string a, string b) {
			string result = "";
			int carry, i, j;

			carry = 0;
			i = a.size() - 1;
			j = b.size() - 1;

			// Runs until both strings are exhausted
			// or there the carry is 1
			while (carry == 1 || i >= 0 || j >= 0)
			{
				// Add to carry from both strings
				carry += (i >= 0) ? (a[i--] - '0') : 0;
				carry += (j >= 0) ? (b[j--] - '0') : 0;

				// Append carry to result string
				// If carry is 0 or 2 then append 0
				// because 1 + 1 is 0 in binary
				// Adding '0' converts integer to ascii
				result = char((carry % 2) + '0');

				// If carry is 2 or 3, there is carry
				// otherwise 0 for next loop
				// 3 in case of carry is one in previous loop
				carry /= 2;
			}

			reverse(result.begin(),result.end());
			return result;
		}
};

int main()
{
	Solution solution;
	string a ("1010");
	string b ("1011");
	string ret;

	ret = solution.addBinary2(a, b);

	cout << "A: " << a << endl;
	cout << "int A: " << binaryStringToInt(a) << endl;
	cout << "B: " << b << endl;
	cout << "int B: " << binaryStringToInt(b) << endl;
	cout << "Return: " << ret << endl;
	return 0;
}
