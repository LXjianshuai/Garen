/*
FIFO Queue
入队，出队
gcc queue.c -o queue
*/

#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int val;
    struct Node *next;
} Node;

typedef struct Queue {
    Node *head;
    Node *tail;
} Queue;

void initQueue(Queue *q) {
    q->head = q->tail = NULL;
}

int isEmpty(Queue *q) {
    return NULL == q->tail;
}

void Enqueue(Queue *q, int val) {
    Node *new = (Node *)malloc(sizeof(Node));
    new->val = val;
    new->next = NULL;
    if (isEmpty(q)) {
        q->head = q->tail = new;
    } else {
        q->tail->next = new;
        q->tail = new;
    }
}

int Dequeue(Queue *q) {
    if (isEmpty(q)) {
        return -1;
    } 
    Node *tmp = q->head;
    int ret = tmp->val;
    q->head = q->head->next;

    if (NULL == q->head) {
        free(tmp);
        q->tail = NULL;
    } else {
        free(tmp);
    }
    return ret;
}

int main() {
    Queue *q = (Queue *)malloc(sizeof(Queue));
    initQueue(q);
    Enqueue(q, 1);
    Enqueue(q, 2);
    Enqueue(q, 3);
    Enqueue(q, 4);
    Enqueue(q, 5);
    printf("%d \n", Dequeue(q));
    printf("%d \n", Dequeue(q));
    printf("%d \n", Dequeue(q));
    printf("%d \n", Dequeue(q));
    printf("%d \n", Dequeue(q));
    printf("%d \n", Dequeue(q));
    printf("%d \n", Dequeue(q));
    return 0;
}
