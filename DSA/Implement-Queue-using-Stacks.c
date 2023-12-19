// Implement Queue using Stacks : https://leetcode.com/problems/implement-queue-using-stacks/description/

#include <stdlib.h>
#include <stdbool.h>

struct Stack {
    int size;
    int top;
    int *arr;
};

void initialize(struct Stack *st, int size) {
    st->top = -1;
    st->size = size;
    st->arr = (int *) malloc(size * sizeof(int));
}

bool isEmpty(struct Stack *st) {
    return (st->top == -1);
}

bool push(struct Stack *st, int ele) {
    if (st->top == st->size - 1) return false;
    st->arr[++st->top] = ele;
    return true;
}

int pop(struct Stack *st) {
    if (isEmpty(st)) return -1;
    return (st->arr[st->top--]);
}

int top(struct Stack *st) {
    if (isEmpty(st)) return -1;
    return (st->arr[st->top]);
}

typedef struct {
    struct Stack st1;
    struct Stack st2;
} MyQueue;


MyQueue* myQueueCreate() {
    MyQueue* que = (MyQueue*) malloc(sizeof (MyQueue));
    initialize(&que->st1, 100);
    initialize(&que->st2, 100);
    return que;
}

void myQueuePush(MyQueue* obj, int x) {
    if (isEmpty(&obj->st1)) {
        push(&obj->st1, x);
        return;
    }

    while(!isEmpty(&obj->st1)){
        push(&obj->st2, pop(&obj->st1));
    }
    push(&obj->st1, x);

    while(!isEmpty(&obj->st2)){
        push(&obj->st1, pop(&obj->st2));
    }
}

int myQueuePop(MyQueue* obj) {
    return pop(&obj->st1);
}

int myQueuePeek(MyQueue* obj) {
    return top(&obj->st1);
}

bool myQueueEmpty(MyQueue* obj) {
    return isEmpty(&obj->st1);
}

void myQueueFree(MyQueue* obj) {
    while(!isEmpty(&obj->st1)) pop(&obj->st1);
}