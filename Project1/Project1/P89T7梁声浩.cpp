#include <iostream>
#include <vector>
using namespace std;

int main(){
	
	vector<int> arr = {1,3,5,7};
	vector<int> brr={1,2,4,5,9};
	vector<int> crr;
	
	for(int i=0;i<int(arr.size());++i){
		int tick=0, left=0,right=int(brr.size())-1;
		
		while(left<=right){
			int mid=(left+right)/2;
			if(brr[mid]==arr[i])
			{
				tick=1;
				break;
			}
			else if(brr[mid]>arr[i])
				right=mid-1;
			else
				left=mid+1;
		}
		if(tick==0){
			crr.push_back(arr[i]);
		}
		
		
		
	}
	
	for(vector<int>::iterator it=crr.begin();it!=crr.end();++it){
		cout<<*it<<" ";
	}
}
