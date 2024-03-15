#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<sstream>
#include<string>
#include<string.h>
#include<iomanip>
#include<map>
#include<queue>
#include<limits.h>
#include<climits>

struct linknode
{
	linknode* next;
	int val;
	linknode() { next = NULL; }
};

class solution
{
public:
	linknode* derepeat(linknode* p)
	{
		linknode* head = p;
		while (head->next != NULL)
		{
			while (head->next->val != head->val) { head = head->next;}
			linknode* fast = head;
			while (fast->next!=NULL and fast->val == fast->next->val) { fast = fast->next; }
			head->next = fast->next;
			head = head->next;
		}
		head = p;
		return head;
	}
};