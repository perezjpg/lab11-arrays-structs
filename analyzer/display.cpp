/*
 * Course: COEN 2210 - Introduction to Programming
 * Name: Johnatanel Perez Lopez
 * Lab: 11 - Arrays and Structs
 * Description: Defines displayObservation, which prints the seven data fields
 *              of one observation as an aligned table row.
 * Due Date: November 1, 2026
 */

#include <iostream>
#include <iomanip>
#include "display.h"
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

    cout << endl;
}
