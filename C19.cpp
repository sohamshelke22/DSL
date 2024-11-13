/*Name: Soham Shelke 

Class: SE2

Roll Number: 72

PRN Number: F23112151



Problem Statement

Department of Computer Engineering has student's club named

'pinnacle club’. Students of second, third and final year of department can be granted

membership on request. Similarly on may cancel the membership of club .First node is

reserved for the president of the club and last node is reserved for the secretary of club .write

C++ program to maintain club members information using singly linked list .store student PRN

and Name .Write function to:

a) Add and Delete the members as well as the president or even secretary.

b) Compute total numbers of members of club.

c) Display members.z

d) Display list in reverse order using recursion.zz

e) Two linked lists exizzsts for two divisions .Concatenate two lists. 

*/



#include <iostream>

#include <string>

using namespace std;



struct Node {

    string name;

    int PRN;

    Node* next;

};



class PinnacleClub {

    Node* head;



public:

    PinnacleClub() {

        head = nullptr;

    }



    void addMember(string name, int PRN, string position) {

        Node* newNode = new Node;

        newNode->name = name;

        newNode->PRN = PRN;

        newNode->next = nullptr;



        if (position == "president") {

            newNode->next = head;

            head = newNode;

        } 

        else if (position == "secretary") {

            if (head == nullptr) {

                head = newNode;

            } else {

                Node* temp = head;

                while (temp->next != nullptr) {

                    temp = temp->next;

                }

                temp->next = newNode;

            }

        } 

        else {

            if (head == nullptr) {

                cout << "Please add a president first!" << endl;

            } else {

                Node* temp = head;

                while (temp->next != nullptr && temp->next->next != nullptr) {

                    temp = temp->next;

                }

                newNode->next = temp->next;

                temp->next = newNode;

            }

        }

    }



    void deleteMember(int PRN) {

        if (head == nullptr) {

            cout << "Club is empty!" << endl;

            return;

        }

        if (head->PRN == PRN) {

            Node* temp = head;

            head = head->next;

            delete temp;

            return;

        }



        Node* temp = head;

        Node* prev = nullptr;

        while (temp != nullptr && temp->PRN != PRN) {

            prev = temp;

            temp = temp->next;

        }



        if (temp == nullptr) {

            cout << "Member not found!" << endl;

            return;

        }

        prev->next = temp->next;

        delete temp;

    }



    int countMembers() {

        int count = 0;

        Node* temp = head;

        while (temp != nullptr) {

            count++;

            temp = temp->next;

        }

        return count;

    }



    void displayMembers() {

        if (head == nullptr) {

            cout << "No members in the club." << endl;

            return;

        }

        Node* temp = head;

        while (temp != nullptr) {

            cout << "PRN: " << temp->PRN << ", Name: " << temp->name << endl;

            temp = temp->next;

        }

    }



    void displayReverse(Node* node) {

        if (node == nullptr) {

            return;

        }

        displayReverse(node->next);

        cout << "PRN: " << node->PRN << ", Name: " << node->name << endl;

    }



    void reverseDisplay() {

        displayReverse(head);

    }



    void concatenate(PinnacleClub& otherList) {

        if (head == nullptr) {

            head = otherList.head;

            return;

        }

        Node* temp = head;

        while (temp->next != nullptr) {

            temp = temp->next;

        }

        temp->next = otherList.head;

    }



    Node* getHead() {

        return head;

    }

};



int main() {

    PinnacleClub clubA, clubB;

    int choice, PRN;

    string name, position;



    while (true) {

        cout << "\n--- Pinnacle Club Menu ---\n";

        cout << "1. Add member\n";

        cout << "2. Delete member\n";

        cout << "3. Display members\n";

        cout << "4. Display members in reverse\n";

        cout << "5. Count members\n";

        cout << "6. Concatenate Club B to Club A\n";

        cout << "7. Exit\n";

        cout << "Enter your choice: ";

        cin >> choice;



        switch (choice) {

            case 1:

                cout << "Enter name: ";

                cin >> name;

                cout << "Enter PRN: ";

                cin >> PRN;

                cout << "Enter position (president/member/secretary): ";

                cin >> position;

                clubA.addMember(name, PRN, position);

                break;



            case 2:

                cout << "Enter PRN to delete: ";

                cin >> PRN;

                clubA.deleteMember(PRN);

                break;



            case 3:

                cout << "Members of Club A:\n";

                clubA.displayMembers();

                break;



            case 4:

                cout << "Members of Club A in reverse:\n";

                clubA.reverseDisplay();

                break;



            case 5:

                cout << "Total members in Club A: " << clubA.countMembers() << endl;

                break;



            case 6:

                clubB.addMember("David", 201, "president");

                clubB.addMember("Eve", 202, "member");

                clubB.addMember("Frank", 203, "secretary");

                cout << "Concatenating Club B into Club A...\n";

                clubA.concatenate(clubB);

                break;



            case 7:

                cout << "Exiting the program." << endl;

                return 0;



            default:

                cout << "Invalid choice, please try again." << endl;

        }

    }



    return 0;

}



/*

Output

--- Pinnacle Club Menu ---

1. Add member

2. Delete member

3. Display members

4. Display members in reverse

5. Count members

6. Concatenate Club B to Club A

7. Exit

Enter your choice: 1

Enter name: Anuj

Enter position (president/member/secretary): president

1. Add member

2. Delete member

3. Display members

4. Display members in reverse

5. Count members

6. Concatenate Club B to Club A

7. Exit

Enter your choice: 1

Enter name: Chinmay

Enter position (president/member/secretary): member

1. Add member

2. Delete member

3. Display members

4. Display members in reverse

5. Count members

6. Concatenate Club B to Club A

7. Exit

Enter your choice: 1

Enter name: Husain

Enter position (president/member/secretary): secretary

1. Add member

2. Delete member

3. Display members

4. Display members in reverse

5. Count members

6. Concatenate Club B to Club A

7. Exit

1. Add member

2. Delete member

3. Display members

4. Display members in reverse

5. Count members

6. Concatenate Club B to Club A

7. Exit

Enter your choice: 2

Enter PRN to delete: 102

--- Pinnacle Club Menu ---

1. Add member

2. Delete member

3. Display members

4. Display members in reverse

5. Count members

6. Concatenate Club B to Club A

7. Exit

Enter your choice: 3

Members of Club A:

PRN: 101, Name: Anuj

PRN: 103, Name: Husain

1. Add member

2. Delete member

3. Display members

4. Display members in reverse

5. Count members

6. Concatenate Club B to Club A

7. Exit

Enter your choice: 4

Members of Club A in reverse:

PRN: 103, Name: Husain

PRN: 101, Name: Anuj

1. Add member

2. Delete member

3. Display members

4. Display members in reverse

5. Count members

6. Concatenate Club B to Club A

7. Exit

Enter your choice: 5

Total members in Club A: 2

--- Pinnacle Club Menu ---

1. Add member

2. Delete member

3. Display members

4. Display members in reverse

5. Count members

6. Concatenate Club B to Club A

7. Exit

Enter your choice: 6

Concatenating Club B into Club A...

1. Add member

2. Delete member

3. Display members

4. Display members in reverse

5. Count members

6. Concatenate Club B to Club A

7. Exit

1. Add member

2. Delete member

3. Display members

4. Display members in reverse

5. Count members

6. Concatenate Club B to Club A

7. Exit

Enter your choice: 7

Exiting the program. 

*/
