// Design Circular Queue: https://leetcode.com/problems/design-circular-queue/description/

#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int *arr;
    int front;
    int rear;
    int size;
} MyCircularQueue;

MyCircularQueue* myCircularQueueCreate(int k) {
    MyCircularQueue* que = (MyCircularQueue*) malloc(sizeof(MyCircularQueue));
    que->arr = (int*) malloc(k * sizeof(int));
    que->front = -1;
    que->rear = -1;
    que->size = k;
    return que;
}

bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    return (obj->front == -1 && obj->rear == -1);
}

bool myCircularQueueIsFull(MyCircularQueue* obj) {
    return ((obj->rear+1) % obj->size == obj->front);
}

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    if (myCircularQueueIsFull(obj)) return false;
    if (obj->front == -1) obj->front++;
    if (obj->rear == obj->size - 1) obj->rear = -1;
    obj->arr[++obj->rear] =  value;
    return true;
}

bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    if (myCircularQueueIsEmpty(obj)) return false;
    if (obj->front == obj->rear){
        obj->front = obj->rear = -1;
        return true;
    }
    if (obj->front == obj->size - 1) obj->front = -1;
    obj->front++;
    return true;
}

int myCircularQueueFront(MyCircularQueue* obj) {
    return (obj->front == -1) ? -1 : obj->arr[obj->front];
}

int myCircularQueueRear(MyCircularQueue* obj) {
    return (obj->rear == -1) ? -1 : obj->arr[obj->rear];
}

void myCircularQueueFree(MyCircularQueue* obj) {
    obj->front = obj->rear = -1;
    free(obj->arr);
    free(obj);
}