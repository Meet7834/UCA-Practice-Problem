// Longest Valid Parentheses: https://leetcode.com/problems/longest-valid-parentheses/description/

#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

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

bool isEmpty(struct Stack *st) { return (st->top == -1); }

bool push(struct Stack *st, int ele) {
    if (st->top == st->size - 1) return false;
    st->arr[++st->top] = ele;
    return true;
}

int pop(struct Stack *st) { return (isEmpty(st)) ? -1 : (st->arr[st->top--]);}

int top(struct Stack *st) { return (isEmpty(st)) ? -1 : (st->arr[st->top]);}

int longestValidParentheses(char* s) {
    int maxi = 0;
    struct Stack st;
    initialize(&st, strlen(s));
    push(&st, -1);

    for(int i=0; i<strlen(s); i++){
        if (s[i] == '(') push(&st, i);
        else {
            pop(&st);
            if (isEmpty(&st)) push(&st, i);
            else  maxi = ( maxi > i - top(&st)) ? maxi : i - top(&st);
        }
    }
    return maxi;
}