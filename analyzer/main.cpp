/*
 * Course: COEN 2210 - Introduction to Programming
 * Name: Johnatanel Perez Lopez
 * Lab: 11 - Arrays and Structs
 * Description: Stores up to 100 observations in an array of structs, reads one
 *              to three validated records, and runs the prototype menu that
 *              displays only the occupied slots.
 * Due Date: [Date]
 */

#include <iostream> // Provides console input and output
#include <iomanip> // Provides table formatting
#include <limits> // Supports discarding invalid numeric input
#include "observation.h" // Provides the record type and initial member values
#include "display.h" // Provides the single-observation display prototype
using namespace std;

int main() {
    const int CAPACITY = 100; // Preserves the capacity required by the final project
    int requestedObservations = 0;
    int menuChoice = 0;

    Observation observations[CAPACITY] = {}; // Every slot starts with isEmpty == true

    cout << "How many observations will you enter (1-3)? ";
    while (!(cin >> requestedObservations) || requestedObservations < 1 || requestedObservations > 3) {
        cin.clear(); // Recovers the stream after a failed extraction
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discards the rest of the invalid line
        cout << "Enter a whole number from 1 to 3: ";
    }

    for (int index = 0; index < requestedObservations; index++) {
        cout << "\nObservation " << index + 1 << endl;

        cout << "Enter ID: ";
        while (!(cin >> observations[index].id) || observations[index].id < 1) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Enter a positive whole number for the ID: ";
        }

        cout << "Enter state abbreviation: ";
        cin >> observations[index].state;

        cout << "Enter county name: ";
        getline(cin >> ws, observations[index].county); // Reads a county name that may include spaces

        cout << "Enter total votes: ";
        while (!(cin >> observations[index].totalVotes) || observations[index].totalVotes < 0) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Enter a non-negative whole number for total votes: ";
        }

        cout << "Enter Democratic votes: ";
        while (!(cin >> observations[index].democraticVotes) || observations[index].democraticVotes < 0) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Enter a non-negative whole number for Democratic votes: ";
        }

        cout << "Enter Republican votes: ";
        while (!(cin >> observations[index].republicanVotes) || observations[index].republicanVotes < 0) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Enter a non-negative whole number for Republican votes: ";
        }

        cout << "Enter Democratic share (0-100): ";
        while (!(cin >> observations[index].democraticShare)
               || observations[index].democraticShare < 0.0 || observations[index].democraticShare > 100.0) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Enter a number from 0 to 100 for Democratic share: ";
        }

        observations[index].isEmpty = false; // Marks the slot occupied only after all fields are complete
    }

    do { // Repeats the prototype menu without repeating the initial data entry
        cout << "\nCoRe Data Analyzer - Lab 11 prototype\n";
        cout << "1. Display Data Frame\n11. Exit application\n";
        cout << "Enter option number: ";

        if (!(cin >> menuChoice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            menuChoice = 0; // Sends non-numeric input to the invalid-option case
        }

        switch (menuChoice) {
            case 1: {
                int displayedCount = 0;
                cout << left
                     << setw(6) << "ID"
                     << setw(7) << "State"
                     << setw(24) << "County"
                     << setw(13) << "Total Votes"
                     << setw(11) << "Dem Votes"
                     << setw(11) << "Rep Votes"
                     << "Dem Share" << endl;

                for (int index = 0; index < CAPACITY; index++) {
                    if (!observations[index].isEmpty) {
                        displayObservation(observations[index]); // Sends a copy of one occupied record
                        displayedCount++;
                    }
                }

                if (displayedCount == 0) {
                    cout << "The dataset is empty." << endl;
                } else {
                    cout << "Observations displayed: " << displayedCount << endl;
                }

                break;
            }
            case 11:
                cout << "Session ended." << endl; // Confirms the selected exit action
                break;
            default:
                cout << "Invalid option." << endl; // Handles a numeric option outside the prototype menu
                break;
        }
    } while (menuChoice != 11);

    return 0;
}

/*
 * Analysis:
 * 1. The ID is data stored inside the record, while the index is the position
 *    of that record in the array. The first observation entered goes into the
 *    first free position, index 0, whatever its ID is. ID 151 is saved in the
 *    id member of observations[0]; the program never uses 151 as a position.
 * 2. The default member initializer bool isEmpty = true in observation.h,
 *    together with the {} initialization of the array, makes all 100 slots
 *    start empty. A slot becomes occupied only when the input loop has read
 *    all seven fields for it and sets isEmpty to false.
 * 3. Occupied slots do not have to be the first ones forever (a future Delete
 *    could free a slot in the middle), so Display checks every position up to
 *    CAPACITY. The isEmpty flag then filters out the unused slots, so the
 *    table shows only real data instead of 97 or 99 rows of zeros.
 * 4. Each call receives observations[index] for one occupied slot. Because the
 *    parameter is passed by value, displayObservation works with a copy of that
 *    record, so it cannot change the data stored in the array.
 * 5. Only .cpp files contain definitions that must be compiled and linked into
 *    the executable. The headers are not separate programs: the preprocessor
 *    copies them into main.cpp and display.cpp through #include, so naming
 *    them in the command is unnecessary.
 */
