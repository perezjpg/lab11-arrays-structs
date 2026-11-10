/*
 * Course: COEN 2210 - Introduction to Programming
 * Name: Johnatanel Perez Lopez
 * Lab: 11 - Arrays and Structs
 * Description: Reads one warehouse dispatch record into a struct and passes a
 *              copy of the complete record to a function that shows its summary.
 * Due Date: November 1, 2026
 */

#include <iostream>
#include <string>
using namespace std;

struct DispatchRecord {
    string destination;
    int boxCount = 0;
};

void displayDispatch(DispatchRecord record);

int main() {
    DispatchRecord shipment = {};
    cout << "Enter shipment destination: ";
    getline(cin, shipment.destination); // Reads a destination that may include spaces
    cout << "Enter number of boxes: ";
    cin >> shipment.boxCount;
    while (shipment.boxCount < 1) {
        cout << "Enter a positive number of boxes: ";
        cin >> shipment.boxCount; // Validates the count before displaying the record
    }
    cout << "Destination recorded: " << shipment.destination << endl;

    displayDispatch(shipment); // Sends a copy of the complete record to the function

    return 0;
}

void displayDispatch(DispatchRecord record) {
    cout << "Dispatch summary" << endl;
    cout << "Destination: " << record.destination << endl;
    cout << "Boxes: " << record.boxCount << endl;
}

/*
 * Analysis:
 * 1. DispatchRecord is a type: it describes the shape of a dispatch (a
 *    destination and a box count) but stores no data by itself. shipment is a
 *    variable of that type, the actual record in memory that holds the
 *    destination and box count entered by the user.
 * 2. Both members are copied: destination and boxCount. The struct is passed
 *    by value, so the parameter record receives a complete copy of shipment.
 * 3. record is a separate local copy that exists only while displayDispatch
 *    runs. Changing record.boxCount would change that copy, not the original
 *    variable in main, so shipment.boxCount would keep its value. Only a
 *    reference parameter (DispatchRecord &record) would modify shipment.
 */
