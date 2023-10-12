//
// Created by hloi on 10/10/2023.
//

#include "ManageTeams.h"
#include <fstream>

using namespace std;

void ManageTeams::readFile(string filename) {
    ifstream teamFS;
    string teamName;
    int numWins;
    int numLosses;

    teamFS.open(filename);

    if (!teamFS.is_open()) {
        cout << "Could not open file teams.txt." << endl;
        return;
    }

    // Read first team name
    getline(teamFS, teamName);

    // Read until end-of-file
    while (!teamFS.fail()) {
        // Attempt to read wins
        teamFS >> numWins;

        if (teamFS.fail()) {
            // Win/loss line missing
            cout << teamName << " has no wins or losses" << endl;
        }
        else {
            // Attempt to read losses
            teamFS >> numLosses;

            if (teamFS.fail()) {
                // No losses provided
                cout << teamName << " has " << numWins << " wins" << endl;
            }

            // Remove newline
            teamFS.ignore();
        }

        // Clear the error state
        teamFS.clear();
        Team t1(teamName, numWins, numLosses);
        teams.push_back(t1);
        // Attempt to read next team
        getline(teamFS, teamName);
    }
    teamFS.close();
    sort(teams.begin(), teams.end()); // ascending order
}

void ManageTeams::print() {
    for (size_t i=0; i<teams.size(); i++) {
        teams.at(i).print();
    }
}

void ManageTeams::writeFile(string filename) {
    ofstream outFS;
    outFS.open(filename);
    if (!outFS.is_open()) {
        cout << "Could not open file " << filename << "." << endl;
        return;
    }
    outFS << *this;

//    for (size_t i=0; i<teams.size(); i++) {
//        outFS << teams.at(i) << " " << teams.at(i).calcAvg() << endl;
//    }
    outFS.close();
}

ostream &operator<<(ostream &out, ManageTeams &other) {
    for (size_t i=0; i<other.teams.size(); i++) {
        try {
            out << other.teams.at(i) << " " << other.teams.at(i).calcAvg() << endl;
        }
        catch (const char* e) {
            cout << e << endl;
        }
        catch (int e) {
            out << other.teams.at(i) << " " << "int exception." << endl;
        }
        catch (runtime_error& e) {
            out << other.teams.at(i) << " " << e.what() << endl;
        }
        catch (exception &e){
            out << other.teams.at(i) << " " << e.what() << endl;
        }
        catch (...) {
            out << "Exception throw." << endl;
        }

    }
    return out;
}

vector<Team> &ManageTeams::getTeams() {
    return teams;
}


