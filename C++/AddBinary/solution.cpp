#include <iostream>
#include <string>

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
};

int main()
{
	Solution solution;
	string a ("1010");
	string b ("1011");
	string ret;

	ret = solution.addBinary(a, b);

	cout << "A: " << a << endl;
	cout << "int A: " << binaryStringToInt(a) << endl;
	cout << "B: " << b << endl;
	cout << "int B: " << binaryStringToInt(b) << endl;
	cout << "Return: " << ret << endl;
	return 0;
}
