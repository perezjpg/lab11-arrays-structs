/*
 * Course: COEN 2210 - Introduction to Programming
 * Name: Johnatanel Perez Lopez
 * Lab: 11 - Arrays and Structs
 * Description: Defines displayObservation, which prints the seven data fields
 *              of one observation as an aligned table row.
 * Due Date: [Date]
 */

#include <iostream> // Provides cout and endl
#include <iomanip> // Provides aligned fields and decimal formatting
#include "display.h" // Checks the definition against its declared prototype
using namespace std;

void displayObservation(Observation observation) {
    cout << left
         << setw(6) << observation.id
         << setw(7) << observation.state
         << setw(24) << observation.county
         << setw(13) << observation.totalVotes
         << setw(11) << observation.democraticVotes
         << setw(11) << observation.republicanVotes
         << fixed << setprecision(2) << observation.democraticShare; // Shows the share with two decimals

    cout << endl; // Ends the row after all its fields have been displayed
}
