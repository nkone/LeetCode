#include <iostream>
#include <string>

using namespace std;

class Solution {
	public:
		int lengthOfLastWord(string s) {
			int i, wordLen;

			wordLen = 0;
			i = s.length() - 1;
			// Skip ending spaces
			while (s[i] == ' ')
				i--;
			// Count non spaces
			while (i >= 0 && s[i] != ' ')
			{
				wordLen++;
				i--;
			}
			return wordLen;
		}
};

int main()
{
	Solution solution;
	string s = "H ";

	cout << "Last word length: " << solution.lengthOfLastWord(s) << endl;
	return 0;
}
