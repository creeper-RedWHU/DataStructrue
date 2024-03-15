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


/*时间复杂度为O(mn),空间复杂度为O(mn)*/
struct linknode
{
	linknode* next;
	int val;
	linknode() { next = NULL; val = 0; }
};
class solution
{
public:
	linknode* merge(linknode* a, linknode* b)
	{
		linknode* c = new linknode;
		linknode* arun = a;
		linknode* brun = b;
		while (arun != NULL and brun != NULL)
		{
			linknode* neww = new linknode;
			if (arun->val < brun->val)
			{
				neww->val = arun->val;
				arun = arun->next;
			}
			else
			{
				neww->val = brun->val;
				brun = brun->next;
			}
			neww->next = c->next;
			c->next = neww;
		}
		while (arun != NULL) { linknode* neww = new linknode; neww->val = arun->val; neww->next = c->next; c->next = neww; arun = arun->next; }
		while (brun != NULL) { linknode* neww = new linknode; neww->val = brun->val; neww->next = c->next; c->next = neww; brun = brun->next; }
		linknode* ans = c->next;
		delete c;
		return ans;
	}
};