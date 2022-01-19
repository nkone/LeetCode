#include <iostream>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
	public:
		bool isSameTree(TreeNode *p, TreeNode *q) {
			// If one node is Null then return the equality of p and q
			// If both is NULL return True, if one is but the other is not then false
			// Check if p val is equal to q val
			// Traverse node towards the left using recursion
			// Traverse node towards the right using recursion
			
			if (p == NULL || q == NULL)
				return (p == q);
			return (p->val == q->val) && 
				isSameTree(p->left, q->left) &&
				isSameTree(p->right,q->right);
		}
};

int main()
{
	struct TreeNode* p;
	struct TreeNode* q;
	Solution solution;

	p = new TreeNode(1);
	p->left = new TreeNode(1);
	p->right = new TreeNode(2);

	q = new TreeNode(1);
	q->left = new TreeNode(1);
	q->right = new TreeNode(2);

	cout << solution.isSameTree(p,q) << endl;
	return 0;
}
