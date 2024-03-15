#include<iostream>

template <typename T>
struct DLinkNode
{
	T data;
	DLinkNode<T> *prior, *next;
	DLinkNode(): prior(NULL), next(NULL)  {}
	DLinkNode(T num): prior(NULL), next(NULL), data(num)  {}
};

template <typename T>
class DLinkList
{
public:
	DLinkNode<T> *head;
	
	DLinkList(int num, T input[])
	{
		head = new DLinkNode<T>;
		DLinkNode<T> * temp = head;
		for (int i = 0; i < num; i ++)
		{
			DLinkNode<T> *newone = new DLinkNode<T>;
			newone->data = input[i];
			temp->next = newone;
			newone->prior = temp;
			temp = temp->next;
		}
	}
	~DLinkList()
	{
		DLinkNode<T> *temp = head;//释放的包括什么？其他部分的临时变量？ 
		while(temp->next != NULL)  //考虑末尾 
		{
			temp = temp->next;
			delete temp->prior;
		} 
		delete temp; 
	}
	void print()
	{
		DLinkNode<T> *temp = head->next;     //两种情况 
		while (temp != NULL)
		{
			std:: cout << temp->data << " ";
			temp = temp->next;
		}
		std:: cout << std:: endl;
		delete temp;     //对delete的理解！ 
	}
	
	
};
 
template <typename T>
T together(DLinkList<T> &list1, DLinkList<T> &list2, int place)
{
	DLinkNode<T>* p1 = list1.head->next, *p2 = list2.head->next;
	while (p1 != NULL && p2 != NULL)
	{
		if (p1->data > p2->data)
		{
			if(-- place == 0)  return p2->data;
			p2 = p2->next;
			
		}
		else if(p1->data < p2->data)
		{
			if(-- place == 0)  return p1->data;
			p1 = p1->next;
		}
		else
		{
			p1 = p1->next;
			p2 = p2->next;
			if(-- place == 0 || -- place == 0)  return p1->data;
		}
	} 
	while (p1 != nullptr) {
        if (--place == 0)  return p1->data;
        p1 = p1->next;
    }

    while (p2 != nullptr) {
        if (--place == 0)   return p2->data;
        p2 = p2->next;
    }
	
}

int main()
{
	int a[2] = {1, 3},  b[5] = {2, 4, 6, 8, 10};
	int place;
	std::cin >> place;
	class DLinkList<int> list1 (2, a), list2 (5, b);
	std::cout << "Lists are as follow!" << std:: endl;
	list1.print();
	list2.print();
	std::cout << together(list1, list2, place) << std::endl;
	
	return 0;
}
