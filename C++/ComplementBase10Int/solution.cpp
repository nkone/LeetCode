#include <iostream>
#include <cmath>

using namespace std;

class Solution {
    public:
        int bitwiseComplement(int n) {
            int mask;

            mask = (2 << int(log2(n))) - 1;

            return mask ^ n;
        }

        int bitwiseComplement2(int n) {

            int mask = 1;

            // creating a mask of 1's bits
            while (n > mask)
                mask = mask * 2 + 1;
            
            return mask ^ n;  // or mask - n
        }
};


int main()
{
    Solution solution;
    cout << solution.bitwiseComplement(5) << endl;
    cout << solution.bitwiseComplement2(5) << endl;
    return 0;
}
