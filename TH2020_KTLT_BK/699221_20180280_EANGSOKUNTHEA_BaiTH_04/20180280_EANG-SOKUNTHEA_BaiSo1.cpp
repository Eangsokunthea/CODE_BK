/*	HoTen: EANG SOKUNTHEA
	MSSV: 20180280
*/
#include <iostream>
using namespace std;
struct Node { 
    int data; 
    Node* next;

    Node(int data) {
        this->data = data;
        next = NULL;
    }
};

// push a new element to the beginning of the list
Node* prepend(Node* head, int data) {
    Node* temp = new Node(data); 
    temp->next = head; 
    return temp; 
}

// print the list content on a line
void print(Node* head) {
    struct Node* temp = head; 
        while (temp != NULL) { 
            cout << temp->data << " "; 
            temp = temp->next; 
        } 
}

// return the new head of the reversed list
Node* reverse(Node* head) {
    Node* current = head; 
        Node *prev = NULL, *next = NULL; 
  
        while (current != NULL) { 
            // Store next 
            next = current->next; 
  
            // Reverse current node's pointer 
            current->next = prev; 
  
            // Move pointers one position ahead. 
            prev = current; 
            current = next; 
        } 
        head = prev; 
        return head;
}
  
int main() {
	printf("HoTen: EANG SOKUNTHEA\n");
	printf("MSSV: 20180280\n");
    int n, u;
    cin >> n;
    Node* head = NULL;
    for (int i = 0; i < n; ++i){
        cin >> u;
        head = prepend(head, u);
    } 
    
    cout << "Original list:";
    print(head);

    head = reverse(head);
    
    cout << "\nReversed list:";
    print(head);

    return 0; 
}
