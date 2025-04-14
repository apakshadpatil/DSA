#include <iostream>
using namespace std;

#define SIZE 5

int stack[SIZE];
int top = -1;

void push(int value) {
    if (top == SIZE - 1)
        cout << "Stack Overflow\n";
    else
        stack[++top] = value;
}

void pop() {
    if (top == -1)
        cout << "Stack Underflow\n";
    else
        top--;
}

void display() {
    for (int i = top; i >= 0; i--)
        cout << stack[i] << " ";
    cout << "\n";
}

int main() {
    push(10);
    push(20);
    push(30);
    display();

    pop();
    display();

    return 0;
}
