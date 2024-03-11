#include <iostream>
#include <cstring>
#include <algorithm>  
#include <vector>

int main()
{
	std::vector<int> A = {1, 3, 5, 7};
	std::vector<int> B = {1, 2, 4, 5, 7};
	std::vector<int> C;
	
	int *pointerA, *pointerB; 
	for (int i = 0; i < 4; i ++)
	{
		for (int j = 0; j < 5; j ++)
		{
			if (A[i] > B[j])
			{
				continue;
			}
			else if (A[i] < B[j])
			{
				break;
			}
			else if (A[i] == B[j])
			{
				C.push_back(A[i]);
			}
		}
	}
	
	for (int temp : C)
	{
		std::cout << temp << std::endl;
	}
	return 0; 
} 
