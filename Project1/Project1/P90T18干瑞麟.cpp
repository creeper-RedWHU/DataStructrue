
#include<iostream>
#include<vector>
using namespace std;
struct ListNode
{
	int val;
	ListNode* next;
	ListNode(int x) :val(x), next(NULL) {};
};
class LinkList
{
public:
	ListNode* head;
	//ListNode* tail;
public:
	LinkList() {head = new ListNode(0); head->next = nullptr; /*tail = nullptr;*/ };
	LinkList(const LinkList& l);
	void createlist(vector<int>& arr);
	//void insert(ListNode* pos, int data);
	//ListNode* findNearestBigger(int data);
	void printAll();
};
class Set {
public:
	LinkList data;
	Set() {};
	Set(const Set& s) { data = s.data; };
	Set(vector<int>& v);
	void printAll();
	void Insert(int num);
};
Set Intersection(Set& s1, Set& s2);
int main() {

	vector<int> a = { 1,3,5,7 }; vector<int>b = { 1,2,4,5,7 };
	Set s1(a); Set s2(b);
	Set ret = Intersection(s1, s2);
	ret.printAll();
	return 0;
}
LinkList::LinkList(const LinkList& l)
{ 
	head = l.head;
}

void LinkList::createlist(vector<int>& arr)
{
	ListNode* curr = head; int n = arr.size();
	for (int i = 0; i < n; i++) {
		curr->next = new ListNode(arr[i]);
		curr = curr->next;
	}
}

void LinkList::printAll()
{
	ListNode* tmp = head->next;
	while (tmp) {
		cout << tmp->val << " ";
		tmp = tmp->next;
	}
	cout << endl;
}

Set::Set(vector<int>& v)
{
	data.createlist(v);
}

void Set::printAll()
{
	data.printAll();
}

void Set::Insert(int num)
{
	ListNode* node = new ListNode(num);
	ListNode* tmp = data.head;
	while (tmp->next) tmp = tmp->next;
	//下一个节点为空
	tmp->next = node;
}

Set Intersection(Set& s1, Set& s2)
{
	Set ret;
	ListNode* ptr1 = s1.data.head->next;
	ListNode* ptr2 = s2.data.head->next;
	while (ptr1 && ptr2) {
		if (ptr1->val < ptr2->val) {
			//ret.Insert(ptr1->val);
			ptr1 = ptr1->next;
		}
		else if (ptr1->val > ptr2->val) {
			//ret.Insert(ptr2->val);
			ptr2 = ptr2->next;
		}
		else {
			ret.Insert(ptr1->val);
			ptr1 = ptr1->next;
			ptr2 = ptr2->next;
		}
	}
	return ret; 
}

