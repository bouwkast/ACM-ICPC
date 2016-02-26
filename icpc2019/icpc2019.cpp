#include <iostream>
#include <sstream>

using namespace std;

#ifndef ONLINE_JUDGE
string test_data = "ABCDEFG\n"
        "3\n"
        "E\n"
        "C\n"
        "D\n"
        "HIWORLD\n"
        "1\n"
        "H\n"
        "HIWORLD\n"
        "0\n"
        "A\n"
        "1\n"
        "A\n"
        "STOP";
#endif

class Driveway {
public:
    string data;
    string output;
    int dataSet = 1;
    void readData(istream &text) {
        string line;
        while(getline(text,line)) {
            if(line.empty()) break;
            if(line == "STOP") break;
            data += line + "\n";
            line = "";
        }
    }

    void solve() {
        istringstream a(data);
        string line;
        string cars;
        int moves = 0;
        char toMove[26];
        bool newSet = true;
        while(getline(a, line)) {
            if(newSet && isalpha(line.at(0))) {
                cars = line;
                newSet = false;
                if(dataSet != 1) {
                    cout << "" << endl;
                }
                cout << "Dataset #" << dataSet++ << ":  The initial order is " << cars << "." << endl;

            }
            else { // line is size of 1
                if(!isalpha(line.at(0))) {
                    moves = stoi(line);
                    if(moves == 0) {
                        newSet = true;
                    }

                } else { // individual letter
                    string leave = line;
                    long pos = cars.find(line);
                    long middle = 0;
                    if(cars.size() % 2 == 0) {
                        middle = cars.size() / 2 - 1;
                    } else {
                        middle = cars.size() / 2;
                    }
                    if(pos > middle) {
                        string lefthalf = cars.substr(0, pos); // good
                        string righthalf = cars.substr(pos + 1, cars.size() - 1 - pos); // need to flip
                        string rev;
                        for(int i = righthalf.size() - 1; i > -1; --i) {
                            rev += righthalf[i];
                        }
                        string result = lefthalf + rev;
                        cars = result;
                        cout << "After " << leave << " leaves, the order is " << result << "." << endl;
                    } else { // less than or equal
                        string lefthalf = cars.substr(0, pos); // need to reverse
                        string righthalf = cars.substr(pos + 1, cars.size() - 1 - pos); // good
                        string rev;
                        for(int i = lefthalf.size() - 1; i > -1; --i) {
                            rev += lefthalf[i];
                        }
                        string result = rev + righthalf;
                        cars = result;
                        cout << "After " << leave << " leaves, the order is " << result << "." << endl;
                    }
                    --moves;
                    if(moves == 0) {
                            newSet = true;
                    }
                }
            }
        }
    }
};

int main() {
    Driveway d;
#ifndef ONLINE_JUDGE
    istringstream input(test_data);
#else
    istream& input = cin;
#endif
    d.readData(input);
    d.solve();
    return 0;
}