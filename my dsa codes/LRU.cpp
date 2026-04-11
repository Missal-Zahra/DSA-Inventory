#include <stdio.h>
#include <stdlib.h>

#define CAPACITY 3
#define HASH_SIZE 100

// Node structure
struct Node {
    int key, value;
    struct Node* prev;
    struct Node* next;
};

// Hash table
struct Node* hash[HASH_SIZE];

// Head and Tail
struct Node* head = NULL;
struct Node* tail = NULL;

// Create new node
struct Node* createNode(int key, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->key = key;
    newNode->value = value;
    newNode->prev = newNode->next = NULL;
    return newNode;
}

// Add node to front
void addToFront(struct Node* node) {
    node->next = head;
    node->prev = NULL;

    if (head != NULL)
        head->prev = node;

    head = node;

    if (tail == NULL)
        tail = head;
}

// Remove node
void removeNode(struct Node* node) {
    if (node->prev != NULL)
        node->prev->next = node->next;
    else
        head = node->next;

    if (node->next != NULL)
        node->next->prev = node->prev;
    else
        tail = node->prev;
}

// Move node to front
void moveToFront(struct Node* node) {
    removeNode(node);
    addToFront(node);
}

// Remove least recently used
void removeLRU() {
    if (tail == NULL) return;

    hash[tail->key] = NULL;
    removeNode(tail);
}

// GET operation
int get(int key) {
    if (hash[key] == NULL)
        return -1;

    struct Node* node = hash[key];
    moveToFront(node);
    return node->value;
}

// PUT operation
void put(int key, int value) {
    if (hash[key] != NULL) {
        struct Node* node = hash[key];
        node->value = value;
        moveToFront(node);
    } else {
        if (CAPACITY == 0) return;

        int count = 0;
        struct Node* temp = head;
        while (temp != NULL) {
            count++;
            temp = temp->next;
        }

        if (count == CAPACITY)
            removeLRU();

        struct Node* newNode = createNode(key, value);
        addToFront(newNode);
        hash[key] = newNode;
    }
}

// Display cache
void display() {
    struct Node* temp = head;
    printf("Cache: ");
    while (temp != NULL) {
        printf("(%d,%d) ", temp->key, temp->value);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    put(1, 10);
    put(2, 20);
    put(3, 30);
    display();

    get(1); // makes 1 most recent
    display();

    put(4, 40); // removes least used (2)
    display();

    printf("Get 2: %d\n", get(2)); // -1
    printf("Get 3: %d\n", get(3)); // 30

    display();

    return 0;
}