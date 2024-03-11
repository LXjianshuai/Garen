/*
Single-Link-List append, traverse, revert
Build command: gcc single_list.c -o single_list
*/

#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int val;
    struct Node *next;
} Node;

void append(Node **head, int val) {
    Node *new = (Node *)malloc(sizeof(Node));
    new->val = val;
    new->next = NULL;
    if (NULL == *head) {
        *head = new;
    } else {
        Node *cur = *head;
        while (cur->next)
        {
            cur = cur->next;
        }
        cur->next = new;
    }
}

void traverseList(Node *head) {
    Node *cur = head;
    while (cur)
    {
        printf("%d ", cur->val);
        cur = cur->next;
    }
    printf("\n");
}

Node *revertList(Node *head) {
    Node *prev = NULL, *cur = head, *next = NULL;
    while (cur)
    {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    return prev;
}






int main()
{
    Node *head = NULL;
    append(&head, 1);
    append(&head, 2);
    append(&head, 3);
    append(&head, 4);
    append(&head, 5);
    append(&head, 6);
    traverseList(head);
    head = revertList(head);
    traverseList(head);
    return 0;
}
