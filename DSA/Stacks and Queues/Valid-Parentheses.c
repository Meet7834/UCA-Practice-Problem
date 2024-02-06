// Valid Parentheses: https://leetcode.com/problems/valid-parentheses/description/

#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct Stack {
    int size;
    int top;
    char *arr;
};

void initialize(struct Stack *st, int size) {
    st->top = -1;
    st->size = size;
    st->arr = (char *) malloc(size * sizeof(char));
}

bool isEmpty(struct Stack *st) {
    return (st->top == -1);
}

bool push(struct Stack *st, char ele) {
    if (st->top == st->size - 1) return false;
    st->arr[++st->top] = ele;
    return true;
}

char pop(struct Stack *st) {
    if (isEmpty(st)) return '\0';
    return (st->arr[st->top--]);
}

char top(struct Stack *st) {
    if (isEmpty(st)) return '\0';
    return (st->arr[st->top]);
}

bool isValid(char *s) {
    struct Stack st;
    int len = strlen(s);
    initialize(&st, len);

    for (int i = 0; i < len; i++) {
        char ch = s[i];
        if (ch == '(' || ch == '[' || ch == '{') push(&st, ch);
        else if (ch == '}') {
            if (top(&st) == '{') pop(&st);
            else return false;
        } else if (ch == ')') {
            if (top(&st) == '(') pop(&st);
            else return false;
        } else if (ch == ']') {
            if (top(&st) == '[') pop(&st);
            else return false;
        }
    }
    return isEmpty(&st);
}