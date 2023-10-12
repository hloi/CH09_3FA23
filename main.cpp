#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
using namespace std;

//int main() {
//   string  userInfo; // = "Amy Smith 19"; // Input string
//   getline(cin, userInfo);
//   istringstream inSS(userInfo);      // Input string stream
//   string firstName;                  // First name
//   string lastName;                   // Last name
//   int userAge;                       // Age
//   // Parse name and age values from input string
//   inSS >> firstName;
//   inSS >> lastName;
//   inSS >> userAge;
//   // Output parsed values
//   cout << "First name: " << firstName << endl;
//   cout << "Last  name: " << lastName << endl;
//   cout << "Age: "        << userAge << endl;
//   ostringstream out;
//   out << lastName << ", " << firstName << ", " << userAge << endl;
//   string fullName = out.str();
//   cout << fullName << endl;
//   return 0;
//}

//int main() {
//    ifstream inFS;
//    ofstream outFS;
//    int num;
//    string numberstr;
//
//    cout << "Opening input file." << endl;
//    inFS.open("inputfile.txt");
//    if (!inFS.is_open()) {
//        cout << "Could not open file." << endl;
//        return 1;
//    }
//
//    cout << "Opening output file." << endl;
//    outFS.open("outputfile.txt");
//    if (!outFS.is_open()) {
//        cout << "Could not open output file." << endl;
//        return 1;
//    }
//
//    cout << "Reading file..." << endl;
//    inFS >> num;
//    while (!inFS.fail()) {
//        inFS >> numberstr;
//        // cout << num << " " << numberstr << endl;
//        outFS << numberstr << " " << num << endl;
//        inFS >> num;
//    }
//    cout << "closing file." << endl;
//    inFS.close();
//    outFS.close();
//
//    return 0;
//
//}

#include "ManageTeams.h"
int main() {
    ManageTeams teamList;
    teamList.readFile("teams.txt");
    cout << teamList;
    teamList.writeFile("teasmavg1.out");
}