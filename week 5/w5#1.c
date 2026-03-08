#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* createNode(int value) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = value;
    node->next = NULL;
    node->prev = NULL;
    return node;
}

struct Node* insertBeginning(struct Node* head, int value) {
    struct Node* node = createNode(value);
    node->next = head;
    if (head) head->prev = node;
    return node;
}

struct Node* insertEnd(struct Node* head, int value) {
    struct Node* node = createNode(value);
    if (!head) return node;
    struct Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = node;
    node->prev = temp;
    return head;
}

struct Node* insertMiddle(struct Node* head, int value, int pos) {
    if (pos <= 0) return insertBeginning(head, value);
    struct Node* node = createNode(value);
    struct Node* temp = head;
    int i;
    for (i = 0; i < pos - 1 && temp; i++) temp = temp->next;
    if (temp) {
        node->next = temp->next;
        node->prev = temp;
        if (temp->next) temp->next->prev = node;
        temp->next = node;
    }
    return head;
}

struct Node* deleteBeginning(struct Node* head) {
    if (!head) return NULL;
    struct Node* temp = head;
    head = head->next;
    if (head) head->prev = NULL;
    free(temp);
    return head;
}

struct Node* deleteEnd(struct Node* head) {
    if (!head) return NULL;
    if (!head->next) {
        free(head);
        return NULL;
    }
    struct Node* temp = head;
    while (temp->next->next) temp = temp->next;
    free(temp->next);
    temp->next = NULL;
    return head;
}

struct Node* deleteMiddle(struct Node* head, int pos) {
    if (!head || pos <= 0) return deleteBeginning(head);
    struct Node* temp = head;
    int i;
    for (i = 0; i < pos - 1 && temp->next; i++) temp = temp->next;
    if (temp->next) {
        struct Node* del = temp->next;
        temp->next = del->next;
        if (del->next) del->next->prev = temp;
        free(del);
    }
    return head;
}

void display(struct Node* head) {
    if (!head) {
        printf("List is empty\n");
        return;
    }
    struct Node* temp = head;
    while (temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void freeList(struct Node* head) {
    struct Node* temp;
    while (head) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    struct Node* head = NULL;
    int choice, n, i, val, pos;
    
    printf("=== Doubly Linked List Operations ===\n");
    
    while (1) {
        printf("\n1. Create List\n2. Insert Beginning\n3. Insert Middle\n");
        printf("4. Insert End\n5. Delete Beginning\n6. Delete Middle\n");
        printf("7. Delete End\n8. Display\n9. Exit\nChoice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter number of elements: ");
                scanf("%d", &n);
                head = NULL;
                printf("Enter %d elements: ", n);
                for (i = 0; i < n; i++) {
                    scanf("%d", &val);
                    head = insertEnd(head, val);
                }
                break;
                
            case 2:
                printf("Enter value: ");
                scanf("%d", &val);
                head = insertBeginning(head, val);
                break;
                
            case 3:
                printf("Enter value: ");
                scanf("%d", &val);
                printf("Enter position: ");
                scanf("%d", &pos);
                head = insertMiddle(head, val, pos);
                break;
                
            case 4:
                printf("Enter value: ");
                scanf("%d", &val);
                head = insertEnd(head, val);
                break;
                
            case 5:
                head = deleteBeginning(head);
                break;
                
            case 6:
                printf("Enter position: ");
                scanf("%d", &pos);
                head = deleteMiddle(head, pos);
                break;
                
            case 7:
                head = deleteEnd(head);
                break;
                
            case 8:
                printf("List: ");
                display(head);
                break;
                
            case 9:
                freeList(head);
                printf("Goodbye!\n");
                return 0;
                
            default:
                printf("Invalid choice!\n");
        }
    }
}
