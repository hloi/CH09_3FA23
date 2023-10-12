//
// Created by hloi on 10/10/2023.
//
#include <iostream>
#include "Team.h"
#include <stdexcept>

using namespace std;

Team::Team() {
    teamName = "";
    wins = 0;
    losses = 0;
}

Team::Team(string teamName, int wins, int losses) {
    this->teamName = teamName;
    this->wins = wins;
    this->losses = losses;
}

double Team::calcAvg() {
    if (wins + losses == 0) {
         throw runtime_error("0/0 error.");
        // throw "0/0 error";

    }
    return wins / ((double) wins + losses);
}

void Team::print() {
    cout << teamName << " " << wins << " " << losses << endl;
}

ostream &operator<<(ostream &out, const Team &other) {
    out << other.teamName << " " << other.wins << " " << other.losses;
    return out;
}

bool Team::operator<(Team &t) {
    return this->teamName < t.teamName;
    // return this->calcAvg() > t.calcAvg();
}

bool Team::operator==(Team &t) {
    return this->teamName == t.teamName &&
    this->wins == t.wins &&
    this->losses == t.losses;
}
