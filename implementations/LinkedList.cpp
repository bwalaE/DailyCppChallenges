#include <cstdlib>
#include <iostream>

using std::cout;
using std::endl;

class LinkedList1 { // the LinkedList from the YouTube tutorial
    private:
        struct node
        {
            int data;
            node* next;
        };

        //typedef struct node* nodePtr; // now nodePtr means the same thing as node* in the code
        //commented out the above line because I'd rather just type node*

        node* head; // the node at the head of the list
        node* curr; // the current node
        node* temp; // temporary node

    public:

        LinkedList1() {
            head = NULL;
            curr = NULL;
            temp = NULL;
        }

        void AddNode(int addData) {
            node* n = new node;
            n->next = NULL;
            n->data = addData;

            if (head != NULL) { // the list is non-empty
                curr = head;
                while (curr->next != NULL) {
                    curr = curr->next;
                }
                curr->next = n;
            }
            else { // the list is empty
                head = n;
            }
        }

        void DeleteNode(int delData) {
            node* delPtr = NULL;
            temp = head;
            curr = head;
            while (curr != NULL && curr->data != delData) {
                temp = curr;
                curr = curr->next;
            }
            if(curr == NULL) {
                cout << delData << " was not in the list" << endl;
            }
            else {
                // the next 3 lines remove the targeted node from the list and then patch up the list seamlessly
                delPtr = curr;
                curr = curr->next; // move curr 1 node ahead so it's no longer associated with the node being deleted
                temp->next = curr;
                //now temp's next pointer points to the node 2 nodes ahead, and the node 1 node ahead can be deleted
                if (delPtr == head) {
                    head = head->next;
                    temp = NULL;
                }
                delete delPtr;
                cout << "The value " << delData << " was deleted" << endl;
            }
        }

        void PrintList() {
            curr = head;
            while (curr != NULL) {
                cout << "[" << curr->data << "] ";
                curr = curr->next;
            }
            cout << endl;
        }
};

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class LinkedList2 { // trying to refactor LinkedList1 to work with the LC requirements
    private:

        //typedef struct node* nodePtr; // now nodePtr means the same thing as node* in the code
        //commented out the above line because I'd rather just type node*

        ListNode* head; // the node at the head of the list
        ListNode* curr; // the current node
        ListNode* temp; // temporary node

    public:

        LinkedList2() {
            head = NULL;
            curr = NULL;
            temp = NULL;
        }

        void AddNode(int addData) {
            ListNode* n = new ListNode;
            n->next = NULL;
            n->val = addData;

            if (head != NULL) { // the list is non-empty
                curr = head;
                while (curr->next != NULL) {
                    curr = curr->next;
                }
                curr->next = n;
            }
            else { // the list is empty
                head = n;
            }
        }

        void DeleteNode(int delData) {
            ListNode* delPtr = NULL;
            temp = head;
            curr = head;
            while (curr != NULL && curr->val != delData) {
                temp = curr;
                curr = curr->next;
            }
            if(curr == NULL) {
                cout << delData << " was not in the list" << endl;
            }
            else {
                // the next 3 lines remove the targeted node from the list and then patch up the list seamlessly
                delPtr = curr;
                curr = curr->next; // move curr 1 node ahead so it's no longer associated with the node being deleted
                temp->next = curr;
                //now temp's next pointer points to the node 2 nodes ahead, and the node 1 node ahead can be deleted
                if (delPtr == head) {
                    head = head->next;
                    temp = NULL;
                }
                delete delPtr;
                cout << "The value " << delData << " was deleted" << endl;
            }
        }

        void PrintList() {
            curr = head;
            while (curr != NULL) {
                cout << "[" << curr->val << "] ";
                curr = curr->next;
            }
            cout << endl;
        }
};