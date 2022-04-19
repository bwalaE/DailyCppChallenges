//#include <cstdlib> // do I need this?
#include <iostream>

using std::cout;
using std::endl;

class LinkedList {
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

        LinkedList() {
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


int main() {

    //cout << "helgslb" << endl;

    LinkedList DaList;

    DaList.AddNode(3);
    DaList.AddNode(12);
    DaList.AddNode(6);
    DaList.AddNode(18);

    DaList.DeleteNode(3);

    DaList.PrintList();

    return 0;
}