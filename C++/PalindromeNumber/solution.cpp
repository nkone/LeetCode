#include <iostream>

using namespace std;

class Solution {
    public:
        bool isPalindrome(int x) {

            // 0 is a palindrome
            if (x < 0)
                return false;

            // reverse number method
            long int reverseNum = 0;
            long int num;

            num = x;

            while (num)
            {
                reverseNum = reverseNum*10 + num%10;
                num /= 10;
            }

            if (reverseNum == x)
                return true;
            else
                return false;

        }
};

int main() {

    Solution solution;

    solution.isPalindrome(121) ? cout << "True" : cout << "False";
    cout << endl;
    return 0;
}

