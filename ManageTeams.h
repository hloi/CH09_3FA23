//
// Created by hloi on 10/10/2023.
//

#ifndef CH09_3FA23_MANAGETEAMS_H
#define CH09_3FA23_MANAGETEAMS_H

#include "Team.h"
#include <vector>
#include <iostream>
#include <algorithm>

using std::ostream;
using std::vector;

class ManageTeams {
private:
    vector<Team> teams;
public:
    ManageTeams() {}
    void readFile(string filename);
    void writeFile(string filename);
    void print();
    friend ostream& operator<<(ostream& out, ManageTeams& other);
    vector<Team>& getTeams();
};


#endif //CH09_3FA23_MANAGETEAMS_H
