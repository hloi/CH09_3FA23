/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   newCxxTest.h
 * Author: hloi
 *
 * Created on January 26, 2018, 3:52 PM
 */

#ifndef NEWCXXTEST_H
#define NEWCXXTEST_H

#include <cxxtest/TestSuite.h>
//Include your classes header file(s) below and uncomment.
//#include "myClass.h"
#include <vector>
#include <fstream>

#include "Team.h"
#include "ManageTeams.h"

using std::vector;
using std::ifstream;

class newCxxTest : public CxxTest::TestSuite {
public:

    //All tests should start with the word 'test' followed by
    //the name of the function being tested.

    void testReadFile() {
        //Use TS_ASSERT_EQUALS(Result, ExpResult) to test your functions.
        Team t1("Arkansas Travelers", 5, 11);
        Team t2("Bruin Boston", 0, 0);
        Team t3("Columbus Clippers", 0, 3);
        Team t4("Norfolk Tides", 6, 0);
        Team t5("Rocky Mountain Vibes", 8, 8);
        Team t6("Vancouver Canadians", 10, 3);
        vector<Team> testTeams;
        testTeams.push_back(t1);
        testTeams.push_back(t2);
        testTeams.push_back(t3);
        testTeams.push_back(t4);
        testTeams.push_back(t5);
        testTeams.push_back(t6);

        ManageTeams mt;
        mt.readFile("teams.txt");
        vector<Team> myTeams = mt.getTeams();
        for (int i=0; i<myTeams.size(); i++) {
            TS_ASSERT_EQUALS(myTeams.at(i), testTeams.at(i));
        }
    }

    void testWriteFile() {
        ManageTeams mt;
        mt.readFile("teams.txt");
        mt.writeFile("myTeams.txt");
        ifstream f1;
        ifstream f2;
        f1.open("myTeams.txt");
        if (!f1.is_open()) {
            TS_FAIL("can't open write file.");
        }
        f2.open("checkFile.txt");
        if (!f2.is_open()) {
            TS_FAIL("can't open instructor file.");
        }

        string s1, s2;
        getline(f1, s1);
        getline(f2, s2);
        while (!f1.fail() && !f2.fail()) {

            TS_ASSERT_EQUALS(s1, s2);
            getline(f1, s1);
            getline(f2, s2);

        }

        if (f1.fail() && !f2.fail()) {
            TS_FAIL("f1 terminated before f2");
        }

        if (f2.fail() && !f1.fail()) {
            TS_FAIL("f2 terminated before f1");
        }

        f1.close();
        f2.close();
    }
};
#endif /* NEWCXXTEST_H */
