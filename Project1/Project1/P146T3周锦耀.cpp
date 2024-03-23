#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<sstream>
#include<string>
#include<string.h>
#include<iomanip>
#include<stdlib.h>
#include<map>
#include<queue>
#include<limits.h>
#include<climits>
#include<fstream>
#include<stack>
typedef long long ll;
using namespace std;




class Solution
{
public:
	string trans(int a,int d)
	{
		string ans;
		stack<int>st;
		int t = a;
		while (t > 0)
		{
			st.push(t % d);
			t = t / d;
		}
		while (!st.empty())
		{
			ans += to_string(st.top());
			st.pop();

		}
		return ans;
	}
};