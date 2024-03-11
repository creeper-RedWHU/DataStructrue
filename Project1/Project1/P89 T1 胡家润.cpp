#include<iostream>
#include<vector>
#include"commonFunc.h"
using namespace std;

int bs(vector<int>& v, int target);

//时间复杂度：nlogn 空间复杂度：O(1)
void insert(vector<int>& v, int target);//在vector里插入
void testinsert();

int maininsert() {

	testinsert();
	return 0;
}

int bs(vector<int>& v, int target)
{
	//找到最近比目标大的元素
	int l = 0, r = v.size() - 1, ret = -1;//未找到返回-1
	while (l <= r) {
		int mid = l + (r - l) / 2;//防止溢出
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

