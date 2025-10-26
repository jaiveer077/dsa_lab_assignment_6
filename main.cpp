SSIGNMENT-6
Q.1
#include <iostream>
using namespace std;
struct Node {
int data;
Node* next;
};
Node* head = NULL;
// Function to create new node
Node* createNode(int val) {
Node* newNode = new Node;
newNode->data = val;
newNode->next = NULL;
return newNode;
}
// Insert at beginning
void insertAtBeginning(int val) {
Node* newNode = createNode(val);
if (head == NULL) {
head = newNode;
head->next = head; // circular
} else {
Node* temp = head;
while (temp->next != head)
temp = temp->next;
temp->next = newNode;
newNode->next = head;
head = newNode;
}
cout << "Inserted " << val << " at beginning.\n";
}
// Insert at end
void insertAtEnd(int val) {
Node* newNode = createNode(val);
if (head == NULL) {
head = newNode;
head->next = head;
} else {
Node* temp = head;
while (temp->next != head)
temp = temp->next;
temp->next = newNode;
newNode->next = head;
}
cout << "Inserted " << val << " at end.\n";
}
// Insert after a specific node
void insertAfter(int key, int val) {
if (head == NULL) {
cout << "List empty!\n";
return;
}
Node* temp = head;
do {
if (temp->data == key) {
Node* newNode = createNode(val);
newNode->next = temp->next;
temp->next = newNode;
cout << "Inserted " << val << " after " << key << ".\n";
return;
}
temp = temp->next;
} while (temp != head);
cout << "Node " << key << " not found.\n";
}
// Delete a specific node
void deleteNode(int key) {
if (head == NULL) {
cout << "List empty!\n";
return;
}
Node* curr = head;
Node* prev = NULL;
// If head node to be deleted
if (head->data == key) {
Node* last = head;
while (last->next != head)
last = last->next;
if (head->next == head) {
delete head;
head = NULL;
} else {
last->next = head->next;
Node* temp = head;
head = head->next;
delete temp;
}
cout << "Deleted " << key << ".\n";
return;
}
// For other nodes
do {
prev = curr;
curr = curr->next;
if (curr->data == key) {
prev->next = curr->next;
delete curr;
cout << "Deleted " << key << ".\n";
return;
}
} while (curr != head);
cout << "Node " << key << " not found.\n";
}
// Search for a node
void searchNode(int key) {
if (head == NULL) {
cout << "List empty!\n";
return;
}
Node* temp = head;
int pos = 1;
do {
if (temp->data == key) {
cout << "Node " << key << " found at position " << pos << ".\n";
return;
}
temp = temp->next;
pos++;
} while (temp != head);
cout << "Node " << key << " not found.\n";
}
// Display list
void display() {
if (head == NULL) {
cout << "List empty!\n";
return;
}
Node* temp = head;
cout << "Circular Linked List: ";
do {
cout << temp->data << " ";
temp = temp->next;
} while (temp != head);
cout << endl;
}
// Main menu
int main() {
int choice, val, key;
do {
cout << "\n--- Circular Linked List Menu ---\n";
cout << "1. Insert at Beginning\n2. Insert at End\n3. Insert After\n";
cout << "4. Delete Node\n5. Search Node\n6. Display\n7. Exit\n";
cout << "Enter your choice: ";
cin >> choice;
switch (choice) {
case 1:
cout << "Enter value: ";
cin >> val;
insertAtBeginning(val);
break;
case 2:
cout << "Enter value: ";
cin >> val;
insertAtEnd(val);
break;
case 3:
cout << "Enter key and value: ";
cin >> key >> val;
insertAfter(key, val);
break;
case 4:
cout << "Enter value to delete: ";
cin >> val;
deleteNode(val);
break;
case 5:
cout << "Enter value to search: ";
cin >> val;
searchNode(val);
break;
case 6:
display();
break;
case 7:
cout << "Exiting...\n";
break;
default:
cout << "Invalid choice!\n";
}
} while (choice != 7);
return 0;
}
OUTPUT:
--- Circular Linked List Menu ---
1. Insert at Beginning
2. Insert at End
3. Insert After
4. Delete Node
5. Search Node
6. Display
7. Exit
Enter your choice: 1
Enter value: 3
Inserted 3 at beginning.
Q.2
#include <iostream>
using namespace std;
// Node structure
class Node {
public:
int data;
Node* next;
Node(int value) {
data = value;
next = nullptr;
}
};
// Function to display circular linked list
void displayCircular(Node* head) {
if (head == nullptr) {
cout << "List is empty." << endl;
return;
}
Node* temp = head;
// Traverse until we return back to head
do {
cout << temp->data << " ";
temp = temp->next;
} while (temp != head);
// Print head again at the end
cout << temp->data << endl;
}
int main() {
// Creating nodes
Node* head = new Node(20);
Node* second = new Node(100);
Node* third = new Node(40);
Node* fourth = new Node(80);
Node* fifth = new Node(60);
// Linking nodes circularly
head->next = second;
second->next = third;
third->next = fourth;
fourth->next = fifth;
fifth->next = head; // circular link
// Display
displayCircular(head);
return 0;
}
OUTPUT:
20 100 40 80 60 20
Q.3i
#include <iostream>
using namespace std;
struct Node {
int data;
Node* prev;
Node* next;
};
Node* head = NULL;
// Function to insert at end
void insertEnd(int val) {
Node* newNode = new Node;
newNode->data = val;
newNode->next = NULL;
newNode->prev = NULL;
if (head == NULL)
head = newNode;
else {
Node* temp = head;
while (temp->next != NULL)
temp = temp->next;
temp->next = newNode;
newNode->prev = temp;
}
}
// Function to find size
int getSize() {
int count = 0;
Node* temp = head;
while (temp != NULL) {
count++;
temp = temp->next;
}
return count;
}
// Display function
void display() {
Node* temp = head;
cout << "Doubly Linked List: ";
while (temp != NULL) {
cout << temp->data << " ";
temp = temp->next;
}
cout << endl;
}
int main() {
insertEnd(10);
insertEnd(20);
insertEnd(30);
insertEnd(40);
display();
cout << "Size of Doubly Linked List = " << getSize() << endl;
return 0;
}
OUTPUT:
Doubly Linked List: 10 20 30 40
Size of Doubly Linked List = 4
Q.3ii
#include <iostream>
using namespace std;
// Node structure
class Node {
public:
int data;
Node* next;
Node(int value) {
data = value;
next = nullptr;
}
};
// Function to count nodes in circular linked list
int getSize(Node* head) {
if (head == nullptr) return 0;
int count = 0;
Node* temp = head;
do {
count++;
temp = temp->next;
} while (temp != head);
return count;
}
int main() {
// Create nodes
Node* head = new Node(20);
Node* second = new Node(100);
Node* third = new Node(40);
Node* fourth = new Node(80);
Node* fifth = new Node(60);
// Link nodes circularly
head->next = second;
second->next = third;
third->next = fourth;
fourth->next = fifth;
fifth->next = head; // circular link
// Find size
cout << "Size of circular linked list: " << getSize(head) << endl;
return 0;
}
OUTPUT:
Size of circular linked list: 5
Q.4
#include <iostream>
using namespace std;
struct Node {
char data;
Node* prev;
Node* next;
};
Node* head = NULL;
// Function to insert a character at the end
void insertEnd(char ch) {
Node* newNode = new Node;
newNode->data = ch;
newNode->next = NULL;
newNode->prev = NULL;
if (head == NULL) {
head = newNode;
} else {
Node* temp = head;
while (temp->next != NULL)
temp = temp->next;
temp->next = newNode;
newNode->prev = temp;
}
}
// Function to display the list
void display() {
Node* temp = head;
cout << "Doubly Linked List: ";
while (temp != NULL) {
cout << temp->data << " ";
temp = temp->next;
}
cout << endl;
}
// Function to check palindrome
bool isPalindrome() {
if (head == NULL || head->next == NULL)
return true;
Node* left = head;
Node* right = head;
while (right->next != NULL)
right = right->next;
// Compare characters from both ends
while (left != right && right->next != left) {
if (left->data != right->data)
return false;
left = left->next;
right = right->prev;
}
return true;
}
int main() {
string str;
cout << "Enter a word: ";
cin >> str;
// Create doubly linked list from string
for (char ch : str)
insertEnd(ch);
display();
if (isPalindrome())
cout << "The given doubly linked list is a palindrome.\n";
else
cout << " The given doubly linked list is not a palindrome.\n";
return 0;
}
class Node {
public:
int data;
Node* next;
Node(int value) {
data = value;
next = nullptr;
}
};
bool isCircular(Node* head) {
if (head == nullptr) return false; // empty list not circular
Node* temp = head->next;
while (temp != nullptr && temp != head) {
temp = temp->next;
}
return (temp == head);
}
int main() {
Node* head1 = new Node(10);
Node* second1 = new Node(20);
Node* third1 = new Node(30);
head1->next = second1;
second1->next = third1;
third1->next = head1; // circular
cout << "List 1 is " << (isCircular(head1) ? "Circular" : "Not Circular") << endl;
Node* head2 = new Node(5);
Node* second2 = new Node(15);
Node* third2 = new Node(25);
head2->next = second2;
second2->next = third2;
third2->next = nullptr; // not circular
cout << "List 2 is " << (isCircular(head2) ? "Circular" : "Not Circular") << endl;
return 0;
}