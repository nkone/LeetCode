#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
	public:
		ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

			// Initialize temp and head
			// Check if list1 or list2 is empty
			// Check the first value of each list and point the starting head
			// Set temp to head
			// While list1 or list2 is not null
			// If the value of list1 is lower than list2
			// Set temp to that node value and move the pointer to next value
			// else
			// do the same for list2
			// Move pointer of temp
			// Connect the temp to the rest of the tail
			// Return head
			ListNode *temp;
			ListNode *head;

			temp = NULL;
			head = NULL;
			if (!list1)
				return (list2);
			if (!list2)
				return (list1);
			
			if (list1->val < list2->val)
			{
				head = list1;
				list1 = list1->next;
			}
			else
			{
				head = list2;
				list2 = list2->next;
			}

			temp = head;

			while (list1 && list2)
			{
				if (list1->val < list2->val)
				{
					temp->next = list1;
					list1 = list1->next;
				}
				else
				{
					temp->next = list2;
					list2 = list2->next;
				}
				temp = temp->next;
			}

			if (list1)
				temp->next = list1;
			else
				temp->next = list2;
			return head;
		}
};

void printList(ListNode* list)
{
	while(list)
	{
		cout << list->val << " ";
		list = list->next;
	}
	cout << endl;
}

int main()
{
	Solution solution;
	struct ListNode* p;
	struct ListNode* q;
	struct ListNode* mergeList;

	p = new ListNode(1);
	p->next = new ListNode(2);
	p->next->next = new ListNode(3);

	q = new ListNode(1);
	q->next = new ListNode(2);
	q->next->next = new ListNode(3);

	cout << "Printing list..." << endl;
	printList(solution.mergeTwoLists(p,q));
	return 0;
}
