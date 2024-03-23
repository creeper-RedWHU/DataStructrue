#include<iostream>
using namespace std;
#include<stack>
#include<vector>
#include<sstream>
string int_to_string(int i) {
	ostringstream oss;
	oss << i;
	return oss.str();
}
int main() {
	stack<int>in;
	vector<int>out;
	int n = 4; //编号从1到4
	string ans;
	for (int i = 1; i <= n; i++) {
		cout << "push" << " "<<i<<endl;
		if (i & 1) {
			out.push_back(i);
			cout << "pop" << " "<<i<<endl;
			ans += int_to_string(i);
		}
		else {
			in.push(i);
		}
	}
	while (!in.empty()) {
		int t = in.top();
		out.push_back(t);
		in.pop();
		cout << "pop" << " " << t << endl;
		ans += int_to_string(t);
	}
	cout << "结果字符串为：" << ans << endl;
	return 0;
}