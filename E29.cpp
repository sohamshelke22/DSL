/*Name: Soham Shelke 

Class: SE2

Roll Number: 72

PRN Number: F23112151



Problem Statement

Queues are frequently used in computer programming, and

a typical example is the creation of a job queue by an operating system. If the operating system does not use

priorities, then the jobs are processed in the order they enter the system. Write C++ program for simulating job

queue. Write functions to add job and delete job from queue. 

*/



#include <iostream>

#include <string>

using namespace std;



struct Job {

    int jobId;

    string jobName;

    Job* next;

};



class JobQueue {

private:

    Job* front;

    Job* rear;



public:

    JobQueue() : front(nullptr), rear(nullptr) {}



    void addJob(int id, const string& name) {

        Job* newJob = new Job();

        newJob->jobId = id;

        newJob->jobName = name;

        newJob->next = nullptr;



        if (rear == nullptr) {

            front = rear = newJob;

        } else {

            rear->next = newJob;

            rear = newJob;

        }

        cout << "Job added: " << name << " (ID: " << id << ")\n";

    }



    void deleteJob() {

        if (front == nullptr) {

            cout << "No jobs to delete. The queue is empty.\n";

            return;

        }

        Job* temp = front;

        front = front->next;

        if (front == nullptr) {

            rear = nullptr;

        }

        cout << "Job deleted: " << temp->jobName << " (ID: " << temp->jobId << ")\n";

        delete temp;

    }



    void displayJobs() {

        if (front == nullptr) {

            cout << "No jobs in the queue.\n";

            return;

        }

        Job* current = front;

        cout << "Jobs in the queue:\n";

        while (current != nullptr) {

            cout << "Job ID: " << current->jobId << ", Job Name: " << current->jobName << "\n";

            current = current->next;

        }

    }



    ~JobQueue() {

        while (front != nullptr) {

            deleteJob();

        }

    }

};



int main() {

    JobQueue queue;

    int choice, id;

    string name;



    do {

        cout << "\nJob Queue Menu:\n";

        cout << "1. Add Job\n";

        cout << "2. Delete Job\n";

        cout << "3. Display Jobs\n";

        cout << "4. Exit\n";

        cout << "Enter your choice: ";

        cin >> choice;



        switch (choice) {

            case 1:

                cout << "Enter Job ID: ";

                cin >> id;

                cout << "Enter Job Name: ";

                cin.ignore();

                getline(cin, name);

                queue.addJob(id, name);

                break;



            case 2:

                queue.deleteJob();

                break;



            case 3:

                queue.displayJobs();

                break;



            case 4:

                cout << "Exiting...\n";

                break;



            default:

                cout << "Invalid choice. Please try again.\n";

        }

    } while (choice != 4);



    return 0;

}



/*

Output



Job Queue Menu:

1. Add Job

2. Delete Job

3. Display Jobs

4. Exit

Enter your choice: 1 Enter Job ID: 101

Enter Job Name: developer Job added:

developer (ID: 101)

Job Queue Menu:

1. Add Job

2. Delete Job

3. Display Jobs

4. Exit

Enter your choice: 1 Enter Job ID: 102

Enter Job Name: tester Job added: tester

(ID: 102)

Job Queue Menu:

1. Add Job

2. Delete Job

3. Display Jobs

4. Exit

Enter your choice: 1 Enter Job ID: 103

Enter Job Name: manager Job added: manager

(ID: 103)

Job Queue Menu:

1. Add Job

2. Delete Job

3. Display Jobs

4. Exit

Enter your choice: 2

Job deleted: developer (ID: 101)

Job Queue Menu:

1. Add Job

2. Delete Job

3. Display Jobs

4. Exit

Enter your choice: 3 Jobs in the queue:

Job ID: 102, Job Name: tester

Job ID: 103, Job Name: manager

Job Queue Menu:

1. Add Job

2. Delete Job

3. Display Jobs

4. Exit

Enter your choice: 4 

Exiting... 



*/
