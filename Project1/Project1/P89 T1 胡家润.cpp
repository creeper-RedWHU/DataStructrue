#include<iostream>
#include<vector>
#include"commonFunc.h"
using namespace std;

int bs(vector<int>& v, int target);

//ʱ�临�Ӷȣ�nlogn �ռ临�Ӷȣ�O(1)
void insert(vector<int>& v, int target);//��vector�����
void testinsert();

int maininsert() {

	testinsert();
	return 0;
}

int bs(vector<int>& v, int target)
{
	//�ҵ������Ŀ����Ԫ��
	int l = 0, r = v.size() - 1, ret = -1;//δ�ҵ�����-1
	while (l <= r) {
		int mid = l + (r - l) / 2;//��ֹ���
		if (v[mid] > target) {
			ret = mid;
			r = mid - 1;
		}
		else {
			l = mid + 1;
		}
	}
	return ret;
}

void insert(vector<int>& v, int target)
{
	int pos = bs(v, target);
	if (pos == -1) v.push_back(target);
	else {
		auto iter = v.begin() + pos;
		v.insert(iter, target);
	}
}

void testinsert()
{
	vector<int>arr = { 1, 2, 3, 4, 5, 9 };
	printAll(arr);
	insert(arr, 0);
	printAll(arr);
	insert(arr, 7);
	printAll(arr);
	insert(arr, 11);
	printAll(arr);
}

