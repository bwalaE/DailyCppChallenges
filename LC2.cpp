#include <iostream>
#include <string>
//#include "implementations/LinkedList.cpp"

using std::cout;
using std::endl;
using std::string;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void printList(ListNode* l1) {

    ListNode* curr;
    curr = l1;

    while (curr != NULL) {
        cout << "[" << curr->val << "] ";
        curr = curr->next;
    }
    cout <<  endl;
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) { // the pointers point to the heads of their respective lists
    ListNode* curr1;
    ListNode* curr2;
    ListNode* result;

    int val1 = -1;
    int val2 = -1;
    int val3 = -1;

    bool carryNext = false; // carries the digit over if val1 + val2 >= 10

    curr1 = l1;
    curr2 = l2;

    while (curr1 != NULL || curr2 != NULL) {

        if (curr1 && !curr2) { //curr1 is a value but curr2 is null
            val1 = curr1->val;
            val2 = 0;
        }
        else if (!curr1 && curr2) { //curr2 is a value but curr1 is null
            val1 = 0;
            val2 = curr2->val;
        }
        else if (!curr1 && !curr2) {
            break;
        }
        else {
            val1 = curr1->val;
            val2 = curr2->val;
        }

        //check if val1 + val2 < 10
        if (val1 + val2 < 10) {
            val3 = val1 + val2;
        }
        else {
            val3 = 10 - (val1 + val2);
        }

        if (carryNext) {
            val3 += 1;
            carryNext = false;
        }

        //check if list is empty
        if (result != NULL) { // list is not empty
            result = new ListNode(val3, result);
        }
        else { // list is empty
            result = new ListNode(val3);
        }
        
        if (val1 + val2 >= 10) {
            carryNext = true;
        }

        curr1 = curr1->next;
        curr2 = curr2->next;
    }

    //printList(result);
    return result;
}

int main() {

    ListNode* l1;
    l1 = new ListNode(3);
    l1 = new ListNode(2, l1);
    l1 = new ListNode(1, l1);

    ListNode* l2;
    l2 = new ListNode(5);
    l2 = new ListNode(4, l2);
    l2 = new ListNode(3, l2);

    printList(l1);
    printList(l2);

    ListNode* result;
    result = addTwoNumbers(l1, l2);
    printList(result);

    return 0;
}