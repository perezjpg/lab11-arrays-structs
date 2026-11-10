/*
 * Course: COEN 2210 - Introduction to Programming
 * Name: Johnatanel Perez Lopez
 * Lab: 11 - Arrays and Structs
 * Description: Defines the Observation struct that represents one county
 *              election record and the flag that marks its array slot as used.
 * Due Date: [Date]
 */

#ifndef OBSERVATION_H
#define OBSERVATION_H

#include <string> // Provides the string fields used by each observation

struct Observation {
    int id = 0; // Initializes the identifier before data is entered

    std::string state; // Stores the state abbreviation
    std::string county; // Stores the full county name

    int totalVotes = 0; // Stores the total votes cast in the county
    int democraticVotes = 0; // Stores the Democratic votes
    int republicanVotes = 0; // Stores the Republican votes
    double democraticShare = 0.0; // Stores the Democratic share from 0 to 100

    bool isEmpty = true; // Marks each newly created slot as available
};

#endif
