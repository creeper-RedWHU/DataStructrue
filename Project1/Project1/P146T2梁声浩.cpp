#include <stack>
#include <iostream>
using namespace std;
template<typename T>
T popNth(stack<T>& stk, int n) {
    if (n <= 0 || stk.size() < n) {
        throw invalid_argument("shu cuo le ");
    }
    stack<T> tempStack;
    for (int i = 1; i < n; ++i) {
        tempStack.push(stk.top());
        stk.pop();

    }
    T nthElement = stk.top();
    stk.pop();
    while (!tempStack.empty())
    {
        stk.push(tempStack.top());
        tempStack.pop();
    }
    return nthElement;
}
int main()
{
    int n;
    stack<int> sta;
    cin >> n;
    for (int i = 0; i < 7; ++i) {

        sta.push(i);
    }
    int result = popNth(sta, n);
    cout << "the " << n << "th is " << result;
  
}

