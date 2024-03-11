#include <iostream>
#include <vector>

using namespace std;

int main(){
	
	vector<int> arr = {1, 2, 3};
	int b[10]={5,1,4,2};
	vector<int> brr(b,b+4);
	vector<int> crr;
	for(int i=0;i<int(arr.size());++i){
		int tick=0;
		for(int j=0;j<int(brr.size());++j){
			if(arr[i]==brr[j]){
				tick=1;
			}
			
		}
		if(tick==0){
			crr.push_back(arr[i]);
		}
	}
	
	
	
	
	for(vector<int>::iterator it=crr.begin();it!=crr.end();++it){
		cout<<*it<<" ";
	}
}
