// Postfix Expression Evaluation: https://www.hackerrank.com/contests/17cs1102/challenges/8-c-postfix-expression-evaluation/problem

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// whole stack data structure
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

int postfixEvaluation(char* str, int len){
    // initializing the stack
    struct Stack *st = (struct Stack*) malloc(sizeof(struct Stack));
    initialize(st, len);

    for(int i=1; i<len; i++){
        // if the char is a number we will continue to add up to the number until a space is found
        if (str[i] >= '0' && str[i] <= '9'){
            int num = 0;
            while(str[i] != ' '){
                num = (num * 10) + (str[i] - '0');
                i++;
            }
            push(st, num);
        }
        else if (str[i] == ' ') continue; // if its space we just continue
        // if its any of the other operations we pop both elements in the stack and perform the operations on them
        // note: the reason we do num2 - num1 (also valid for '/' ) and not num1 - num2 is because num2 was the first number to go inside the stack so the order of the operations stays the same
        else if (str[i] == '+'){
            int num1 = pop(st);
            int num2 = pop(st);
            push(st, num1 + num2);
        }
        else if (str[i] == '-'){
            int num1 = pop(st);
            int num2 = pop(st);
            push(st, num2 - num1);
        }
        else if (str[i] == '*'){
            int num1 = pop(st);
            int num2 = pop(st);
            push(st, num1 * num2);
        }
        else if (str[i] == '/'){
            int num1 = pop(st);
            int num2 = pop(st);
            push(st, num2 / num1);
        }
    }
    return pop(st);
}

int main() {
    int n;
    scanf("%d", &n);
    while(n--){

        // taking input for the given test case
        char* str = (char*) malloc(1000 * sizeof(char));
        int len = 0;
        while(1) {
            char ch;
            scanf("%c", &ch);
            str[len++] = ch;
            if (ch == '?') break;
        }
        len--;

        // calling the postfix function
        int postfix = postfixEvaluation(str, len);
        printf("%d\n", postfix);
    }
    return 0;
}
