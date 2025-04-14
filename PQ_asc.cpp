#include <iostream>
using namespace std;

#define MAX_SIZE 100

int pq[MAX_SIZE];
int count = 0;  // Renamed from 'size' to avoid ambiguity

void insert(int value) {
    int index = count - 1;
    while (index >= 0 && pq[index] > value) {
        pq[index + 1] = pq[index];
        index--;
    }
    pq[index + 1] = value;
    count++;
}

void remove() {
    if (count == 0) {
        cout << "Queue Underflow\n";
    } else {
        count--;
    }
}

void display() {
    for (int i = 0; i < count; i++) {
        cout << pq[i] << " ";
    }
    cout << "\n";
}

int main() {
    insert(30);
    insert(10);
    insert(20);
    display();  // Output: 10 20 30

    remove();
    display();  // Output: 20 30

    return 0;
}
