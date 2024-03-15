#include<iostream>

template <typename T>
struct CLinkNode
{
	T data;
	CLinkNode<T> *next;
	CLinkNode():  next(NULL)  {}
	CLinkNode(T num):  next(NULL), data(num)  {}
};

template <typename T>
class CLinkList
{
public:
	CLinkNode<T> *head;
	
	CLinkList(int num, T input[])
	{
		head = new CLinkNode<T>;
		head->next = head;
		
		CLinkNode<T> * temp = head;
		for (int i = 0; i < num; i ++)
		{
			CLinkNode<T> *newone = new CLinkNode<T>;
			newone->data = input[i];
			newone->next = temp->next;
			temp->next = newone;
			temp = temp->next;   //循环链表的特殊之处！ 
		}
	}
	
	~CLinkList()  
	{  
    	CLinkNode<T> *temp = head->next, *temp2 = head->next->next;
    	while(temp2 != head)
    	{
    		delete temp;
    		temp = temp2;
    		temp2 = temp2->next;
		}
		 delete temp, temp2;
	}
	
	void print()
	{
		CLinkNode<T> *temp = head->next;    
		while (temp != head)
		{
			std:: cout << temp->data << " ";
			temp = temp->next;
		}
		std:: cout << std:: endl;
	}
	
	void SearchDelete(CLinkNode<T> *point)
	{
		CLinkNode<T> *late = point->next;
		CLinkNode<T> *early = point->next;
		while(early->next != point)
		{
			early = early->next;
		}
		//early and late are init!
		early->next = late;
		delete point; 
	}


	
};

int main()
{
	int a[5] = {1, 2, 3, 6, 5};
	CLinkList<int> example(5, a);
	example.print();
	example.SearchDelete(example.head->next->next->next);
	example.print();
	return 0;
}
