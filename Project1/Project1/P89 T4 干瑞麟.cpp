#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
vector<int> solve(vector<int>& a, vector<int>& b);
int main() {

	vector<int>a = { 1, 3, 2 };
	vector<int>b = { 5, 1, 4, 2 };
	vector<int>c = solve(a, b);
	for (int x : c) cout << x << " ";
	return 0;
}
/*时间复杂度O(min(m+n,mlogm,nlogn)) 空间复杂度：O(1)*/
vector<int> solve(vector<int>& a, vector<int>& b)
{
	vector<int>ret;
	int m = a.size(); int n = b.size();
	int i = 0; int j = 0;
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	while (i < m && j < n) {
		if (a[i] < b[j]) {
			ret.push_back(a[i++]);
		}
		else if (a[i] > b[j]) {
			ret.push_back(b[j++]);
		}
		else {
			ret.push_back(a[i++]);
			j++;
		}
	}
	while (i < m) ret.push_back(a[i++]);
	while (j < n) ret.push_back(b[j++]);
	return ret;
}
