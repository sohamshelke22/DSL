/*Name: Soham Shelke 

Class: SE2

Roll Number: 72

PRN Number: F23112151



Problem Statement

A double-ended queue (deque) is a linear list in which

additions and deletions may be made at either end. Obtain a data representation mapping a

deque into a one- dimensional array. Write C++ program to simulate deque with functions to

add and delete elements from either end of the deque. 

*/



#include <iostream>

using namespace std;



class Deque {

private:

    int* arr;

    int front;

    int rear;

    int capacity;

    int size;



public:

    Deque(int cap) {

        capacity = cap;

        arr = new int[capacity];

        front = -1;

        rear = -1;

        size = 0;

    }



    ~Deque() {

        delete[] arr;

    }



    bool isEmpty() {

        return size == 0;

    }



    bool isFull() {

        return size == capacity;

    }



    void addFront(int value) {

        if (isFull()) {

            cout << "Deque is full. Cannot add " << value << " at the front." << endl;

            return;

        }

        if (isEmpty()) {

            front = rear = 0;

        } else {

            front = (front - 1 + capacity) % capacity;

        }

        arr[front] = value;

        size++;

    }



    void addRear(int value) {

        if (isFull()) {

            cout << "Deque is full. Cannot add " << value << " at the rear." << endl;

            return;

        }

        if (isEmpty()) {

            front = rear = 0;

        } else {

            rear = (rear + 1) % capacity;

        }

        arr[rear] = value;

        size++;

    }



    void deleteFront() {

        if (isEmpty()) {

            cout << "Deque is empty. Cannot delete from the front." << endl;

            return;

        }

        cout << "Deleted from front: " << arr[front] << endl;

        if (front == rear) {

            front = rear = -1;

        } else {

            front = (front + 1) % capacity;

        }

        size--;

    }



    void deleteRear() {

        if (isEmpty()) {

            cout << "Deque is empty. Cannot delete from the rear." << endl;

            return;

        }

        cout << "Deleted from rear: " << arr[rear] << endl;

        if (front == rear) {

            front = rear = -1;

        } else {

            rear = (rear - 1 + capacity) % capacity;

        }

        size--;

    }



    void display() {

        if (isEmpty()) {

            cout << "Deque is empty." << endl;

            return;

        }

        cout << "Deque elements: ";

        int i = front;

        while (i != rear) {

            cout << arr[i] << " ";

            i = (i + 1) % capacity;

        }

        cout << arr[rear] << endl;

    }

};



int main() {

    Deque dq(5);

    dq.addRear(10);

    dq.addRear(20);

    dq.addFront(30);

    dq.display();

    dq.deleteFront();

    dq.display();

    dq.addFront(40);

    dq.deleteRear();

    dq.display();

    return 0;

}



/*



Output

Deque elements: 30 10 20

Deleted from front: 30

Deque elements: 10 20

Deleted from rear: 20

Deque elements: 40 10



*/
