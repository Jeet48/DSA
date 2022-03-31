#include <bits/stdc++.h>
using namespace std;
 
struct node {
    int data;
    node* next;
    node(int val)
    {
        data = val;
        next = NULL;
    }
};
 
struct llist {
 
    node* head;
    llist() { head = NULL; }
 
    // insert operation at the beginning of the list.
    void insertAtBegin(int val)
    {
        node* newNode = new node(val);
        newNode->next = head;
        head = newNode;
    }
 
    
    void nthFromEnd(int n)
    {
        
        node* main_ptr = head;
        node* ref_ptr = head;
 
        // if list is empty, return
        if (head == NULL) {
            cout << "List is empty" << endl;
            return;
        }
 
        // move ref_ptr to the n-th node from beginning.
        for (int i = 1; i < n; i++) {
            ref_ptr = ref_ptr->next;
            if (ref_ptr == NULL) {
                cout << n
                     << " is greater than no. of nodes in "
                        "the list"
                     << endl;
                return;
            }
        }
 
        // move ref_ptr and main_ptr by one node until
        // ref_ptr reaches end of the list.
        while (ref_ptr != NULL && ref_ptr->next != NULL) {
            ref_ptr = ref_ptr->next;
            main_ptr = main_ptr->next;
        }
        cout << "Node no. " << n
             << " from end is: " << main_ptr->data << endl;
    }
 
    void displaylist()
    {
        node* temp = head;
        while (temp != NULL) {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};
 
int main()
{
    llist ll;
 
    for (int i = 60; i >= 10; i -= 10)
        ll.insertAtBegin(i);
 
    ll.displaylist();
 
    for (int i = 1; i <= 7; i++)
        ll.nthFromEnd(i);
 
    return 0;
}