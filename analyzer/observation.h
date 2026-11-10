/*
 * Course: COEN 2210 - Introduction to Programming
 * Name: Johnatanel Perez Lopez
 * Lab: 11 - Arrays and Structs
 * Description: Defines the Observation struct that represents one county
 *              election record and the flag that marks its array slot as used.
 * Due Date: November 1, 2026
 */

#ifndef OBSERVATION_H
#define OBSERVATION_H

#include <string>

struct Observation {
    int id = 0;

    std::string state;
    std::string county;

    int totalVotes = 0;
    int democraticVotes = 0;
    int republicanVotes = 0;
    double democraticShare = 0.0; // Stores the Democratic share from 0 to 100

    bool isEmpty = true; // Marks each newly created slot as available
};

#endif
