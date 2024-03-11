#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<sstream>
#include<string>
#include<string.h>
#include<iomanip>
#include<map>
#include<queue>
#include<limits.h>
#include<climits>
using namespace std;
typedef long long ll;

/*t10*/
int a[100];
int b[100];
int c[1000];
int main()
{
	//a,b:up
	//a:lengtha,b:lengthb
	int lengtha = 50, lengthb = 50;
	int i = lengtha, j = lengthb;
	int ptr = 1;
	while (i > 0 and j > 0)
	{
		if (a[i] > b[j])c[ptr++] = a[i--];
		else c[ptr++] = b[j--];
	}
	while (i > 0)c[ptr++] = a[i--];
	while (j > 0)c[ptr++] = b[j--];
	return 0;
}