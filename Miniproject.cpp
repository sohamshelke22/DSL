/*Mini Project: Parking Management
Language used: C++
Data Structure used: Linked List
Group Members: 1. Sahil N Dhanwade (63)
               2. Soham A Shelke (72)
Code:
*/
#include <iostream>
#include <string>
#include <ctime>

using namespace std;

struct VehicleNode // Node to represent a parked vehicle
{
    string licensePlate;
    time_t parkingTime; // Time the vehicle was parked
    VehicleNode* next;
};

class ParkingLot // Creating class for parking lot
{
private:
    VehicleNode* head; // Pointer to the head of the linked list
    const double hourlyRate = 100.0; // Define hourly rate in rupees

public:
    ParkingLot() : head(nullptr) {}

    void addVehicle(const string& licensePlate) // Adding vehicle
    {
        VehicleNode* newVehicle = new VehicleNode{licensePlate, time(nullptr), head};
        head = newVehicle;
        cout << "Vehicle with license plate " << licensePlate << " parked." << endl;
    }

    void removeVehicle(const string& licensePlate) // Removing vehicle
    {
        VehicleNode* current = head;
        VehicleNode* previous = nullptr;

        while (current != nullptr) {
            if (current->licensePlate == licensePlate) {
                double bill = calculateBill(current->parkingTime);
                if (previous == nullptr) { 
                    head = current->next;
                } else {
                    previous->next = current->next;
                }
                delete current;
                cout << "Vehicle with license plate " << licensePlate << " removed." << endl;
                cout << "Total bill: ₹" << bill << endl; // Display bill in rupees
                return;
            }
            previous = current;
            current = current->next;
        }
        cout << "Vehicle with license plate " << licensePlate << " not found." << endl;
    }

    double calculateBill(time_t parkingTime) // Calculate parking fee based on user input
    {
        double hoursParked;
        cout << "Enter the number of hours parked: ";
        cin >> hoursParked; // User input for hours

        // Ensure valid input
        if (hoursParked < 0) {
            cout << "Invalid number of hours. Setting bill to zero." << endl;
            return 0.0;
        }
        return hoursParked * hourlyRate; // Calculate bill
    }

    void displayVehicles() // Display all parked vehicles
    {
        if (head == nullptr) {
            cout << "No vehicles parked." << endl;
            return;
        }
        cout << "Currently parked vehicles:" << endl;
        VehicleNode* current = head;
        while (current != nullptr) {
            cout << "- " << current->licensePlate << endl;
            current = current->next;
        }
    }

    void createBill(const string& licensePlate) // Create bill for a specific vehicle
    {
        VehicleNode* current = head;
        while (current != nullptr) {
            if (current->licensePlate == licensePlate) {
                double bill = calculateBill(current->parkingTime);
                cout << "Bill for vehicle with license plate " << licensePlate << ": ₹" << bill << endl; // Display bill in rupees
                return;
            }
            current = current->next;
        }
        cout << "Vehicle with license plate " << licensePlate << " not found." << endl;
    }

    ~ParkingLot() // Destructor to free memory
    {
        while (head != nullptr) {
            VehicleNode* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    ParkingLot lot;
    int choice;
    string licensePlate;

    do {
        cout << "\nParking Management System\n";
        cout << "1. Add Vehicle\n";
        cout << "2. Remove Vehicle\n";
        cout << "3. Display Vehicles\n";
        cout << "4. Create Bill\n";
        cout << "5. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter license plate: ";
                cin >> licensePlate;
                lot.addVehicle(licensePlate);
                break;
            case 2:
                cout << "Enter license plate to remove: ";
                cin >> licensePlate;
                lot.removeVehicle(licensePlate);
                break;
            case 3:
                lot.displayVehicles();
                break;
            case 4:
                cout << "Enter license plate to create bill: ";
                cin >> licensePlate;
                lot.createBill(licensePlate);
                break;
            case 5:
                cout << "Exiting the system." << endl;
                break;
            default:
                cout << "Invalid option. Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}
