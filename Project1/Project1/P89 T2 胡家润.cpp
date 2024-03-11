#include<iostream>
using namespace std;
#include<vector>
#include"commonFunc.h"
void erase(vector<int>& v);
void testerase();
int mainerase() {

	testerase();
	return 0;
}

//ʱ�临�Ӷȣ�O(n) �ռ临�Ӷȣ� O(1)
void erase(vector<int>& v)
{
	//��С�ƶ���������
	int moveForward = 0; int n = v.size(); 
	int newSize = n;
	for (int i = 0; i < n; i++) {
		if (v[i] < 0) {
			moveForward++;
			newSize--;
		}
		else {
			v[i - moveForward] = v[i];
		}
	}
	v.resize(newSize);
}

void testerase()
{
	vector<int> v = { -1, 2, 4, 5, -5, 0, 1, -1, -1};
	printAll(v);
	erase(v);
	printAll(v);
}
