#include <iostream>
#include <string>

bool isOpenBracket(char c)
{
    return (c == '(' || c == '[' || c == '{');
}

bool isCloseBracket(char c)
{
    return (c == ')' || c == ']' || c == '}');
}

class Solution {
public:
    bool isValid(string s)
    {
        char buffer[10000] = {0};
        int bufferIndex = 0;
        if (s.length() & 1)
            return false;
        bool isClose = false;

        for (int i = 0; i < s.length(); i++)
        {
            // Store open brackets
            if (isOpenBracket(s[i]))
                buffer[bufferIndex++] = s[i];
            if (isCloseBracket(s[i]))
            {
                isClose = true;
                if (bufferIndex != 0)
                    bufferIndex--;
                if (s[i] == ')' && buffer[bufferIndex] != '(' ||
                        s[i] == '}' && buffer[bufferIndex] != '{' ||
                        s[i] == ']' && buffer[bufferIndex] != '[')
                    return false;
                buffer[bufferIndex] = 0;
            }
        }

        // Check buffer to see if there are open brackets
        for (int i = 0; i < 10000; i++)
            if (buffer[i] != 0)
                return false;

        // return true if there are close brackets
        return (isClose) ? true : false;
        }
};

int main()
{
    Solution solution;
    solution.isValid("({{[[()]]}})") ? cout << "True\n" : cout << "False\n";
	return 0;
}
