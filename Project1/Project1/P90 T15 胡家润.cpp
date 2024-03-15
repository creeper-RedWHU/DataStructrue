#include <iostream>  
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};
void insertToTail(ListNode** head, int val) {
    ListNode* newNode = new ListNode(val);
    if (*head == nullptr) {
        *head = newNode;
    }
    else {
        ListNode* current = *head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }
}
void printList(ListNode* head) {
    ListNode* current = head;
    while (current != nullptr) {
        std::cout << current->val << " ";
        current = current->next;
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
ListNode* differenceSet(ListNode* A, ListNode* B) {
    ListNode* C = nullptr;
    ListNode* tailC = nullptr;

    while (A != nullptr) {
        bool isInB = false;
        ListNode* temp = B;
        while (temp != nullptr) {
            if (A->val == temp->val) {
                isInB = true;
                break;
            }
            temp = temp->next;
        }
        if (!isInB) {
            if (C == nullptr) {
                C = new ListNode(A->val);
                tailC = C;
            }
            else {
                tailC->next = new ListNode(A->val);
                tailC = tailC->next;
            }
        }
        A = A->next;
    }
    return C;
}
int main() {
    ListNode* A = nullptr;
    insertToTail(&A, 1);
    insertToTail(&A, 3);
    insertToTail(&A, 2);

    ListNode* B = nullptr;
    insertToTail(&B, 5);
    insertToTail(&B, 1);
    insertToTail(&B, 4);
    insertToTail(&B, 2);

    std::cout << "Set A: ";
    printList(A);
    std::cout << "Set B: ";
    printList(B);

    ListNode* C = differenceSet(A, B);

    std::cout << "Set C (Difference of A and B): ";
    printList(C);

    deleteList(A);
    deleteList(B);
    deleteList(C);

    return 0;
}