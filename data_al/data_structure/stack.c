/*
栈操作
包括入栈出栈
gcc stack.c -o stack
*/

#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int val;
    struct Node *next;
} Node;

typedef struct Stack
{
    Node *top;
} Stack;

void initStack(Stack *s) {
    s->top = NULL;
}

int isEmpty(Stack *s) {
    return NULL == s->top;
}

void push(Stack *s, int val) {
    Node *new = (Node *)malloc(sizeof(Node));
    new->val = val;
    new->next = s->top;
    s->top = new;
}

int pop(Stack *s) {
    if (isEmpty(s)) {
        return -1;
    }
    Node *tmp = s->top;
    int val = tmp->val;
    s->top = tmp->next;
    free(tmp);
    return val;
}

int main()
{
    Stack *s = (Stack *)malloc(sizeof(Stack));
    initStack(s);
    push(s, 1);
    push(s, 2);
    push(s, 3);
    push(s, 4);
    push(s, 5);
    push(s, 6);
    printf("%d \n", pop(s));
    printf("%d \n", pop(s));
    printf("%d \n", pop(s));
    printf("%d \n", pop(s));
    printf("%d \n", pop(s));
    printf("%d \n", pop(s));
    printf("%d \n", pop(s));
    printf("%d \n", pop(s));
    printf("%d \n", pop(s));
    printf("%d \n", pop(s));
}
