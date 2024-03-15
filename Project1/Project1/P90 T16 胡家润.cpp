#include <iostream>  

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};
ListNode* differenceSet(ListNode* A, ListNode* B) {
    ListNode dummy(0); 
    ListNode* tail = &dummy; 

    while (A != nullptr) {
        if (B == nullptr || A->val < B->val) {
            tail->next = new ListNode(A->val);
            tail = tail->next;
            A = A->next;
        }
        else if (A->val == B->val) {
            A = A->next;
            B = B->next;
        }
        else {
            B = B->next;
        }
    }

    return dummy.next;  
}
void printList(ListNode* head) {
    while (head != nullptr) {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << std::endl;
}
void deleteList(ListNode* head) {
    ListNode* current = head;
    while (current != nullptr) {
        ListNode* temp = current;
        current = current->next;
        delete temp;
    }
}
int main() {
    ListNode* A = new ListNode(1);
    A->next = new ListNode(3);
    A->next->next = new ListNode(5);
    A->next->next->next = new ListNode(7);

    ListNode* B = new ListNode(2);
    B->next = new ListNode(3);
    B->next->next = new ListNode(5);
    B->next->next->next = new ListNode(8);
    ListNode* C = differenceSet(A, B);
    std::cout << "Set C (Difference of A and B): ";
    printList(C);

    deleteList(A);
    deleteList(B);
    deleteList(C);

    return 0;
}