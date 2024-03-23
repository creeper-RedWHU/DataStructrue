#include<iostream>
using namespace std;
#include<stack>
bool athuiwen(string& str);
int main() {

	string str; cin >> str;
	if (athuiwen(str)) cout << 1 << endl;
	return 0;
}

bool athuiwen(string& str)
{
	stack<char>st;
	if (str.size() % 2 == 0) return false;
	int mid = str.size() / 2; // 0 1 2 3 4 
	int i = 0;
	for (; i < mid; i++) {
		st.push(str[i]);
	}
	//i==mid
	if(str[i++]!='@') return false ; //i==mid+1;
	for (; i < str.size(); i++) {
		if (st.top() != str[i]) return false;
		st.pop();
	}
	return true;
}
