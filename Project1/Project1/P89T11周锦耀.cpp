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



/*t11*/
linknode* first;
void linknode::del(ll x)
{
	linknode* slow = first;
	linknode* fast = first->next;
	while (fast->next != NULL)
	{
		if (fast->val == x)
		{
			slow->next = fast->next;
		}
		slow = slow->next;
		fast = slow->next;
	}
}
class linknode
{
public:
	linknode* next;
	ll val;
	linknode() { next = NULL; val = 0; }
	void del(ll x);

};
int main()
{
	linknode lk;
	//输入数据然后调用del函数
	return 0 ;
}