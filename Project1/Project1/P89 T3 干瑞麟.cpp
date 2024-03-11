#include<iostream>
#include<vector>
using namespace std;
void printAll(vector<int>& v);
void testmove();
void moveNegative(vector<int>& v);
int main() {

	testmove();
	return 0;
}

void testmove()
{
	vector<int> v = { -1, 2, 4, 5, -5, 0, 1, -1, -1 };
	printAll(v);
	moveNegative(v);
	printAll(v);
}

void printall(vector<int>& v)
{
	for (int x : v) {
		cout << x << " ";
	}
	cout << endl;
}
void moveNegative(vector<int>& v)
{
	int n = v.size(), cnt = 0;//cnt 表示前面夹在两个负数之间的正数个数
	for (int i = 0; i < n; i++) {
		if (v[i] < 0) {
			for (int j = 1; j <= cnt; j++) {
				swap(v[i - j], v[i - j + 1]);
			}
		}
		else {
			cnt++;
		}
	}
}
