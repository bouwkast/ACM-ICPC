#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

#ifndef ONLINE_JUDGE
string test_data ="5  10 11 12  3 4 5\n"
        "3   10  10 7  3\n"
        "12  5  -3  1   4  6 7 8 9 12\n"
        "5280 10";
#endif

class CookieFinder {
public:
    vector<int> locs;
    string actual;
    string expected = "Moving from 0 to 10: same.\n"
            "Moving from 10 to 11: colder.\n"
            "Moving from 11 to 12: colder.\n"
            "Moving from 12 to 3: warmer.\n"
            "Moving from 3 to 4: warmer.\n"
            "Moving from 4 to 5: found it!\n"
            " \n"
            "Moving from 0 to 10: colder.\n"
            "Moving from 10 to 10: same.\n"
            "Moving from 10 to 7: warmer.\n"
            "Moving from 7 to 3: found it!\n"
            " \n"
            "Moving from 0 to 5: warmer.\n"
            "Moving from 5 to -3: colder.\n"
            "Moving from -3 to 1: warmer.\n"
            "Moving from 1 to 4: warmer.\n"
            "Moving from 4 to 6: warmer.\n"
            "Moving from 6 to 7: warmer.\n"
            "Moving from 7 to 8: warmer.\n"
            "Moving from 8 to 9: warmer\n"
            "Moving from 9 to 12: found it!";
    int currLoc = 0;
    int cLoc;
    string line;
    int diff = 0;
    int prevDiff = -1;
    bool isStart = true;
    void readData(istream &input) {
        while (getline(input, line)) {
            istringstream text(line);
            text >> cLoc;
            if (cLoc == 5280 || cLoc == -5280) return;
            int i = 0;
            int location;
            int dist = 0, prevDist = 15000;
            while (text >> location) {
                locs.push_back(location);
                i++;
            }
            string result = "";
            for (int j = 0; j < i; ++j) {
                int a = abs(cLoc);
                int b = abs(locs[j]);
                int diff;
                if(cLoc <= 0 && locs[j] <= 0) { // both neg
                    dist = abs(a - b);
                } else if(cLoc >= 0 && locs[j] >= 0) { // both pos
                    dist = abs(cLoc - locs[j]);
                } else if(cLoc <= 0 && locs[j] >= 0) { // cLoc neg, loc pos
                    dist = abs(cLoc - locs[j]);
                } else if(cLoc >= 0 && locs[j] <= 0) { // cLoc pos, loc neg
                    dist = abs(cLoc - locs[j]);
                }
                if(dist == 0)
                    result = "found it!";
                else {
                    if(prevDist == 15000) {
                        if(dist == cLoc)
                            result = "same.";
                        else if(abs(dist) > abs(cLoc))
                            result = "colder.";
                        else
                            result = "warmer.";
                    } else {
                        if(dist == prevDist) {
                            result = "same.";
                        } else if(dist > prevDist) {
                            result = "colder.";
                        } else {
                            result = "warmer.";
                        }
                    }
                    prevDist = dist;
                }

                cout << "Moving from " << currLoc << " to " << locs[j] << ": " << result << endl;
//                actual += "Moving from " + currLoc + " to " + locs[j] + ": " + result + "\n";
                prevDist = dist;
                currLoc = locs[j];
            }
            locs.clear();
//            if(cLoc != 5280)
                cout << " " << endl;
            currLoc = 0;
            prevDiff = -1;
            prevDist = 15000;
                isStart = true;
        }
    }

    void solve() {

    }
};

int main() {
    CookieFinder cf;
#ifndef ONLINE_JUDGE
    istringstream input(test_data);
#else
    istream& input = cin;
#endif

    cf.readData(input);
    return 0;
}