#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

typedef struct {
    int items[MAX_SIZE];
    int front;
    int rear;
} Queue;

void initialize(Queue *q) {
    q->front = -1;
    q->rear = -1;
}

int isEmpty(Queue *q) {
    return q->front == -1;
}

int isFull(Queue *q) {
    return (q->rear + 1) % MAX_SIZE == q->front;
}

void enqueue(Queue *q, int value) {
    if (isFull(q)) {
        printf("Queue is full. Cannot enqueue.\n");
        return;
    }

    if (isEmpty(q)) {
        q->front = 0;
        q->rear = 0;
    } else {
        q->rear = (q->rear + 1) % MAX_SIZE;
    }

    q->items[q->rear] = value;
}

int dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    }

    int value = q->items[q->front];

    if (q->front == q->rear) {
        initialize(q);
    } else {
        q->front = (q->front + 1) % MAX_SIZE;
    }

    return value;
}

int main() {
    Queue q;
    initialize(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);

    printf("Dequeued: %d\n", dequeue(&q));
    printf("Dequeued: %d\n", dequeue(&q));

    enqueue(&q, 40);
    enqueue(&q, 50);

    printf("Dequeued: %d\n", dequeue(&q));
    printf("Dequeued: %d\n", dequeue(&q));
    printf("Dequeued: %d\n", dequeue(&q));

    return 0;
}
