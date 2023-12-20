// Assignment link: https://docs.google.com/document/d/1-8bj3mC6spA-fCh9pjcoXQFc7JcYxjFqrWSXyc2UkNU/edit

#include<stdio.h>

int bitAnd(int a, int b) {
    return ~(~a | ~b);
}

int bitXor(int a, int b) {
    return ~(~(a & ~b) & (~(~a & b)));
}

int sign(int n) {
    return (((1 << 30) | n) >> 30) & (~(!n));
}

int getByte(int x, int n) {
    return ((x >> (n << 3)) & 255) >> 4;
}

int logicalShift(int x, int n) {
    return (x >> n) & ~((-1 >> n) << 1);
}

int conditional(int x, int y, int z) {
    int k = (!x << 31) >> 31;
    return (y ^ z) ^ (k & y) ^ (~k & z);
}

int bang(int n) {
    return 1 & ((n >> 31) | ((~n + 1) >> 31));
}

int invert(int x, int p, int n) {
    return x ^ ((-1 << p) ^ (((-1 << n) << p)));
}

int main() {

}