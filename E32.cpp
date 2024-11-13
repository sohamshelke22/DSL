/*Name: Soham Shelke 

Class: SE2

Roll Number: 72

PRN Number: F23112151



Problem Statement

Pizza parlor accepting maximum M orders. Orders are

served in first come first served basis. Order once placed cannot be cancelled. Write C++ program to simulate the

system using circular queue using array

*/



#include <iostream>

using namespace std;



#define SIZE 5



class Pizza {

    int porder[SIZE];

    int front, rear;



public:

    Pizza() {

        front = rear = -1;

    }



    int qfull() {

        return front == (rear + 1) % SIZE;

    }



    int qempty() {

        return front == -1;

    }



    void accept_order(int item) {

        if (qfull()) {

            cout << "\nVery Sorry !!!! No more orders. ... \n";

        } else {

            if (front == -1) {

                front = rear = 0;

            } else {

                rear = (rear + 1) % SIZE;

            }

            porder[rear] = item;

        }

    }



    void make_payment(int n) {

        if (qempty()) {

            cout << "\nSorry !!! order is not there. \n";

        } else {

            cout << "\nDelivered orders as follows: \n";

            for (int i = 0; i < n; i++) {

                int item = porder[front];

                if (front == rear) {

                    front = rear = -1;

                } else {

                    front = (front + 1) % SIZE;

                }

                cout << "\t" << item;

            }

            cout << "\nTotal amount to pay: " << n * 100;

            cout << "\nThank you, visit again...\n";

        }

    }



    void order_in_queue() {

        if (qempty()) {

            cout << "\nSorry !! There is no pending order...\n";

        } else {

            cout << "\nPending Orders as follows:\n";

            int temp = front;

            while (temp != rear) {

                cout << "\t" << porder[temp];

                temp = (temp + 1) % SIZE;

            }

            cout << "\t" << porder[temp];

        }

    }

};



int main() {

    Pizza p1;

    int ch, k, n;



    do {

        cout << "\n\t***** Welcome To Pizza Parlor *******\n";

        cout << "\n1. Accept order\n2. Make payment\n3. Pending Orders\n4. Exit\n";

        cout << "Enter your choice: ";

        cin >> ch;



        switch (ch) {

            case 1:

                cout << "\nWhich Pizza would you like to have today?\n";

                cout << "1. Veg Soya Pizza\n2. Veg Butter Pizza\n3. Egg Pizza\n";

                cout << "Please enter your order: ";

                cin >> k;

                p1.accept_order(k);

                break;



            case 2:

                cout << "\nHow many Pizzas? ";

                cin >> n;

                p1.make_payment(n);

                break;



            case 3:

                cout << "\nFollowing orders are in queue to deliver...\n";

                p1.order_in_queue();

                break;



            case 4:

                cout << "\nEnd of program\n";

                break;



            default:

                cout << "\nInvalid choice! Please try again.\n";

                break;

        }

    } while (ch != 4);



    return 0;

}



/*

Output

***** Welcome To Pizza Parlor *******

1.Accept order

2.Make_payment

3.Pending Orders 4.Exit

Enter u r choice:1

Which Pizza would do u like to have today

1.Veg Soya Pizza

2.Veg butter Pizza 3.Egg_Pizza

Please enter your order: 1

***** Welcome To Pizza Parlor *******

1.Accept order

2.Make_payment

3.Pending Orders 4.Exit

Enter u r choice:1

Which Pizza would do u like to have today

1.Veg Soya Pizza

2.Veg butter Pizza 3.Egg_Pizza

Please enter your order: 2

***** Welcome To Pizza Parlor *******

1.Accept order

2.Make_payment

3.Pending Orders 4.Exit

Enter u r choice:1

Which Pizza would do u like to have today

1.Veg Soya Pizza

2.Veg butter Pizza 3.Egg_Pizza

Please enter your order: 3

***** Welcome To Pizza Parlor *******

1.Accept order

2.Make_payment

3.Pending Orders 4.Exit

Enter u r choice:2 How many Pizza ?3

Deliverd orders as follows...

1 2 3

Total amount to pay : 300 Thank you visit

Again....

***** Welcome To Pizza Parlor *******

1.Accept order

2.Make_payment

3.Pending Orders 4.Exit

Enter u r choice:3

Following orders are in queue to deliver ... as follows..

Sorry !! There is no pending order...

***** Welcome To Pizza Parlor *******

1.Accept order

2.Make_payment

3.Pending Orders 4.Exit

Enter u r choice:4 End of program 



*/
