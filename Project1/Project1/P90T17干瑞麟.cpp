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
	LinkList() { head = nullptr; /*tail = nullptr;*/ };
	LinkList(const LinkList& l);
	//void createlist(vector<int>& arr);
	void insert(ListNode* pos, int data);
	ListNode* findNearestBigger(int data);
	void printAll();
};


class Set {
public:
	LinkList data;
public:
	Set() {};
	Set(vector<int>& arr);
	void insert(int num);
	bool isIn(int num);
	Set& Union(Set s2);
	void printAll();
};
Set Intersection(Set& s1, Set& s2);
int main()
{
	vector<int> v{ 1,3,5,7 }; vector<int>r{ 1,3,4,5,7 };
	Set s1(v); Set s2(r);
	Set s3 = Intersection(s1, s2);
	s3.printAll();
	return 0;
}


//void LinkList::createlist(vector<int>& arr)
//{
//	head = new ListNode(arr[0]);
//	tail = head;
//	ListNode* p, * tmp;
//	for (int i = 1; i < arr.size(); i++) {
//		tmp = new ListNode(arr[i]);
//		tail->next = tmp;
//		tail = tmp;
//	}
//}
LinkList::LinkList(const LinkList& l)
{
	head = l.head; //tail = l.tail;
}
void LinkList::insert(ListNode* pos, int data)
{

	ListNode* node = new ListNode(data);
	if (pos == head) {
		node->next = head;
		head = node;
		return;
	}

	ListNode* tmp = head;
	while (tmp!=nullptr && tmp->next != pos) {
		tmp = tmp->next;
	}
	if (tmp != nullptr) {
		tmp->next = node;
		node->next = pos;
	}
}

ListNode* LinkList::findNearestBigger(int data)
{
	ListNode* tmp = head, *ret=nullptr;
	while (tmp != nullptr) {
		if (tmp->val > data) {
			ret = tmp;
			break;
		}
		tmp = tmp->next;
	}
	//if(tmp==nullptr) ×î´óÊý
	return ret;
}

Set::Set(vector<int>& arr)
{
	data.head = new ListNode(arr[0]);
	for (int i = 1; i < arr.size(); i++) {
		insert(arr[i]);
	}
}


bool Set::isIn(int num)
{
	ListNode* tmp = data.head;
	while (tmp != nullptr) {
		if (tmp->val == num) {
			return true;
		}
		tmp = tmp->next;
	}
	return false;
}
Set& Set::Union(Set s2)
{
	auto head2 = s2.data.head;
	while (head2 != nullptr) {
		insert(head2->val);
		head2 = head2->next;
	}
	return *this;
}
void Set::insert(int num)
{
	if (!isIn(num)) {
		ListNode* node = data.findNearestBigger(num);
		data.insert(node, num);
	}
}
void LinkList::printAll()
{
	ListNode* tmp = head;
	while (tmp != nullptr) {
		cout << tmp->val << " ";
		tmp = tmp->next;
	}
	cout << endl;
}
void Set::printAll()
{
	data.printAll();
}

Set Intersection(Set& s1, Set& s2)
{
	Set ret; 
	LinkList data = s2.data;
	ListNode* tmp = data.head;
	ListNode* curr = ret.data.head;
	while (tmp) {
		if (s1.isIn(tmp->val)) {
			if (ret.data.head == nullptr) {
				ret.data.head = new ListNode(tmp->val);
				//curr = ret.data.head;
			}
			else {
				//ListNode* node = new ListNode(tmp->val);
				ret.insert(tmp->val);
			}
		}
		tmp = tmp->next;
	}
	return ret;
}
