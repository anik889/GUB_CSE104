//Queue implemantation using  linked list

#include <stdio.h>
#include <stdlib.h>
// Node structure
typedef struct Node {
    int data;
    struct Node *next;
} Node;
// Queue structure
typedef struct {
    Node *front;
    Node *rear;
} Queue;
// Create an empty queue
Queue* createQueue() {
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->front = NULL;
    q->rear = NULL;
    return q;
}
// Check if queue is empty
int isEmpty(Queue *q) {
    return q->front == NULL;
}
// Enqueue (add to rear)
void enqueue(Queue *q, int value) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        return;
    }
    
    newNode->data = value;
    newNode->next = NULL;
    
    if (isEmpty(q)) {
        q->front = newNode;
    } else {
        q->rear->next = newNode;
    }
    
    q->rear = newNode;
    printf("Enqueued: %d\n", value);
}

// Dequeue (remove from front)
int dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty! Cannot dequeue.\n");
        return -1;
    }
    
    Node *temp = q->front;
    int value = temp->data;
    q->front = temp->next;
    
    if (q->front == NULL) {
        q->rear = NULL;
    }
    
    free(temp);
    printf("Dequeued: %d\n", value);
    return value;
}

// Peek (view front without removing)
int peek(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return -1;
    }
    return q->front->data;
}

// Display queue
void display(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return;
    }
    
    printf("Queue: ");
    Node *current = q->front;
    while (current) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Free queue memory
void freeQueue(Queue *q) {
    while (!isEmpty(q)) {
        dequeue(q);
    }
    free(q);
}

// Main
int main() {
    Queue *q = createQueue();
    
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    enqueue(q, 40);
    
    display(q);
    
    printf("Front element: %d\n", peek(q));
    
    dequeue(q);
    dequeue(q);
    
    display(q);
    
    freeQueue(q);
    
    return 0;
}
