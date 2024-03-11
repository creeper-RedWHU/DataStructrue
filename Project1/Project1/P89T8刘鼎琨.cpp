#include <iostream>
#include <cstring>
#include <algorithm>  
#include <vector>

int main()
{
	std::vector<int> A = {1, 3, 2};
	std::vector<int> B = {5, 1, 4, 2};
	std::vector<int> C;
	
	for (int i = 0; i < 3; i ++)
	{
		for (int j = 0; j < 4; j ++)
		{
			if (A[i] == B[j])
			{
				C.push_back(A[i]);
				A[i] == -65536;
			}
		}
	}
	for (int temp : C)
	{
		std::cout << temp << std::endl;
	}
	return 0; 
} 
