#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* createNode(int value);
void append(struct Node** head, int value);
void printList(struct Node* head);

struct Node* createNode(int value){
    struct Node* NewNode = (struct Node*)malloc(sizeof(struct Node));
    NewNode->data = value;
    NewNode->next = NULL;
    return NewNode;
}

void append(struct Node** head, int value){
    struct Node* newNode= createNode(value);

    if(*head == NULL){
        *head = newNode;
        return;
    }
    struct Node* temp = *head;

    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
}

void printList(struct Node* head){
    struct Node* temp = head;
    while(temp->next != NULL){
        printf("%d\n",temp->data);
        temp = temp->next;
    }
    printf("%d\n", temp->data);
}

int main() {
    struct Node* head = NULL;  // Inicializa a lista como vazia

    append(&head, 10);
    append(&head, 20);
    append(&head, 30);
    
    printList(head);  // Imprime: 10 -> 20 -> 30 -> NULL

    return 0;
}
