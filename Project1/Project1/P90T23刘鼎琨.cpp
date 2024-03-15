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
		head->next = head;
	
		DLinkNode<T> * temp = head;
		for (int i = 0; i < num; i ++)
		{
			DLinkNode<T> *newone = new DLinkNode<T>;
			newone->data = input[i];
			newone->next = temp->next;
			temp->next = newone;		
			temp = temp->next;   //循环链表的特殊之处！ 
		}
	}
	
	~DLinkList()  
	{  
    	DLinkNode<T> *temp = head->next; 
   	 	while (temp != head)
   	 	{  
      		DLinkNode<T> *toDelete = temp;  
     		temp = temp->next; 
      		delete toDelete; 
    	}  
    	delete head;   
	}
	
	void print()
	{
		DLinkNode<T> *temp = head->next;    
		while (temp != head)
		{
			std:: cout << temp->data << " ";
			temp = temp->next;
		}
		std:: cout << std:: endl;
	}
	
	void Fixprevious()
	{
		DLinkNode<T> *temp = head;
		while (temp->next != head)
		{
			temp->next->prior = temp;
			temp = temp->next;
		} 
		head->prior = temp;
	}

	
};

int main()
{
	// can check the problem by seeing how long the program ends!
	int a[3] = {3, 2, 1};
	DLinkList<int> example(3, a);
	example.print();
	example.Fixprevious();
	example.print();
	return 0;
}
