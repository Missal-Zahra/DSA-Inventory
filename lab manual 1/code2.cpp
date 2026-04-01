#include <iostream>
using namespace std;
struct DNode {
int data;
DNode* prev;
DNode* next;
};
class DoublyLinkedList {
private:
DNode* head;
public:
DoublyLinkedList() {
head = NULL;
}
// Display forward
void displayForward() {

if (head == NULL) {
cout << "List is empty.\n";
return;
}
DNode* temp = head;
while (temp != NULL) {
cout << temp->data << " <-> ";
temp = temp->next;
}
cout << "NULL\n";
}
// 1. Add node at start
void addAtStart(int value) {
DNode* newNode = new DNode();
newNode->data = value;
newNode->prev = NULL;
newNode->next = head;
if (head != NULL) {
head->prev = newNode;
}
head = newNode;
}
// 2. Add node at end
void addAtEnd(int value) {
DNode* newNode = new DNode();
newNode->data = value;
newNode->next = NULL;
newNode->prev = NULL;
if (head == NULL) {
head = newNode;
return;
}

DNode* temp = head;
while (temp->next != NULL) {
temp = temp->next;
}
temp->next = newNode;
newNode->prev = temp;
}
// 3. Add node at specific position
void addAtPosition(int value, int position) {
if (position < 1) {
cout << "Invalid position.\n";
return;
}
if (position == 1) {
addAtStart(value);
return;
}
DNode* temp = head;
for (int i = 1; i < position - 1 && temp != NULL; i++) {
temp = temp->next;
}
if (temp == NULL) {
cout << "Position out of range.\n";
return;
}
DNode* newNode = new DNode();
newNode->data = value;
newNode->next = temp->next;
newNode->prev = temp;
if (temp->next != NULL) {

temp->next->prev = newNode;
}
temp->next = newNode;
}
// 4. Update first node
void updateFirstNode(int value) {
if (head == NULL) {
cout << "List is empty.\n";
return;
}
head->data = value;
}
// 5. Update last node
void updateLastNode(int value) {
if (head == NULL) {
cout << "List is empty.\n";
return;
}
DNode* temp = head;
while (temp->next != NULL) {
temp = temp->next;
}
temp->data = value;
}
// 6. Update node at specific position
void updateAtPosition(int value, int position) {
if (position < 1) {
cout << "Invalid position.\n";
return;
}
DNode* temp = head;

for (int i = 1; i < position && temp != NULL; i++) {
temp = temp->next;
}
if (temp == NULL) {
cout << "Position out of range.\n";
return;
}
temp->data = value;
}
// 7. Delete first node
void deleteFirstNode() {
if (head == NULL) {
cout << "List is empty.\n";
return;
}
DNode* temp = head;
head = head->next;
if (head != NULL) {
head->prev = NULL;
}
delete temp;
}
// 8. Delete last node
void deleteLastNode() {
if (head == NULL) {
cout << "List is empty.\n";
return;
}
if (head->next == NULL) {
delete head;

head = NULL;
return;
}
DNode* temp = head;
while (temp->next != NULL) {
temp = temp->next;
}
temp->prev->next = NULL;
delete temp;
}
// 9. Delete node at specific position
void deleteAtPosition(int position) {
if (head == NULL) {
cout << "List is empty.\n";
return;
}
if (position < 1) {
cout << "Invalid position.\n";
return;
}
if (position == 1) {
deleteFirstNode();
return;
}
DNode* temp = head;
for (int i = 1; i < position && temp != NULL; i++) {
temp = temp->next;
}
if (temp == NULL) {
cout << "Position out of range.\n";
return;

}
if (temp->next != NULL) {
temp->next->prev = temp->prev;
}
if (temp->prev != NULL) {
temp->prev->next = temp->next;
}
delete temp;
}
};
int main() {
DoublyLinkedList list;
list.addAtEnd(10);
list.addAtEnd(20);
list.addAtEnd(30);
cout << "Initial Doubly Linked List: ";
list.displayForward();
list.addAtStart(5);
cout << "After adding at start: ";
list.displayForward();
list.addAtPosition(15, 3);
cout << "After adding 15 at position 3: ";
list.displayForward();
list.updateFirstNode(100);
cout << "After updating first node: ";
list.displayForward();
list.updateLastNode(300);
cout << "After updating last node: ";
list.displayForward();

list.updateAtPosition(200, 3);
cout << "After updating node at position 3: ";
list.displayForward();
list.deleteFirstNode();
cout << "After deleting first node: ";
list.displayForward();
list.deleteLastNode();
cout << "After deleting last node: ";
list.displayForward();
list.deleteAtPosition(2);
cout << "After deleting node at position 2: ";
list.displayForward();
return 0;
}