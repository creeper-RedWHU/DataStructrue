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
using namespace std;
typedef long long ll;


/*t12*/
linknode* head;
class linknode;
void linknode::trans()
{
	linknode* slow = head;
	linknode* fast = slow->next;
	while (fast->next != NULL)
	{
		while (fast->next->val > 0)fast = fast->next;
		linknode* zz = fast->next;
		linknode* th2 = fast->next->next;
		//=fast->next->next;
		fast->next->next = slow->next;
		fast->next = th2;
		slow->next = zz;
		slow = slow->next;//ÈıÖ¸Õë£¬Ïà»¥ÂÖ»»

	}
}
class linknode
{
	linknode* next;
	int val;
	linknode() { next = NULL; val = 0; }
	void trans();
};

