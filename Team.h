//
// Created by hloi on 10/10/2023.
//

#ifndef CH09_3FA23_TEAM_H
#define CH09_3FA23_TEAM_H
#include <string>
#include <sstream>

using std::string;
using std::ostream;

class Team {
private:
    string teamName;
    int wins;
    int losses;

public:
    Team();
    Team(string teamName, int wins, int losses);
    double calcAvg();
    void print();
    friend ostream& operator<<(ostream& out, const Team& other);
};


#endif //CH09_3FA23_TEAM_H
