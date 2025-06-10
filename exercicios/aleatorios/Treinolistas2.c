#include <stdlib.h>

typedef struct{
    int data;
    struct Node* next;
}Node;

Node* createNode(int value);
void append(Node** head, int value);
void printList(Node* head);

Node* createNode(int value){
    Node* NewNode = (Node*)malloc(sizeof(Node));
    if(NewNode->next == NULL)
        exit(0);
    NewNode->data = value;
    return NewNode;
}

void append(Node** head, int value){
    Node* NewNode = createNode(value);

    if(*head == NULL){
        *head = NewNode;
        return;
    }

    Node* temp = *head;

    while(temp->next != NULL)
        temp = temp->next;

    temp->next = NewNode;
}

void addinicio(Node** head, int value){
    Node* NewNode = createNode(value);
    NewNode->next = *head;
    *head = NewNode;
}
