//Queue implementation using fixed size array

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int arr[MAX_SIZE];
    int front;
    int rear;
} Queue;

Queue* createQueue() {
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

int isEmpty(Queue *q) {
    return q->front == -1;
}

int isFull(Queue *q) {
    return q->rear == MAX_SIZE - 1;
}

void enqueue(Queue *q, int value) {
    if (isFull(q)) {
        printf("Queue overflow!\n");
        return;
    }
    if (isEmpty(q)) q->front = 0;
    q->arr[++q->rear] = value;
    printf("Enqueued: %d\n", value);
}

int dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue underflow!\n");
        return -1;
    }
    int value = q->arr[q->front++];
    if (q->front > q->rear) {
        q->front = q->rear = -1;  // reset queue
    }
    printf("Dequeued: %d\n", value);
    return value;
}

int peek(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return -1;
    }
    return q->arr[q->front];
}
