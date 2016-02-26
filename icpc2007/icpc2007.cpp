#include <iostream>
#include <sstream>
#include <deque>

using namespace std;

#ifndef ONLINE_JUDGE
string test_data = "The following text<C><B>is centred and in boldface</B></C>#\n"
        "<B>This <\\g>is <B>boldface</B> in <<*> a</B> <\\6> <<d>sentence#\n"
        "<B><C> This should be centred and in boldface, but the\n"
        "tags are wrongly nested </B></C>#\n"
        "<B>This should be in boldface, but there is an extra closing\n"
        "tag</B></C>#\n"
        "<B><C>This should be centred and in boldface, but there is\n"
        "a missing closing tag</C>#\n"
        "#\n"
        "<A></A>#";
#endif

class TagChecker {
public:
    void readAndSolve(istream &input) {
        string line;
        int pos;

        while(true) {
            getline(input, line);
            if(line == "#")
                break;
            deque<string> tags;
            bool proceed = true;
            string toCheck = line;
            while(line.find("#") == string::npos) {
                getline(input, line);
                toCheck += line;
            }
            pos = toCheck.find("<");
            while(proceed && pos != string::npos) {
                if(pos < toCheck.size() - 2 && isupper(toCheck[pos+1]) && toCheck[pos+2] == '>') {
                    tags.push_front(toCheck.substr(pos+1,1));
                } else {
                    if(pos < toCheck.size() - 3 && toCheck[pos+1] == '/' && isupper(toCheck[pos+2]) && toCheck[pos+3] == '>') {
                        if(tags.empty()) {
                            cout << "Expected # found </" << toCheck.substr(pos+2, 1) << ">" << endl;
                            proceed = false;
                        } else {
                            string curr = tags.front();
                            string actual = toCheck.substr(pos+2, 1);
                            tags.pop_front();
                            if(curr != actual) {
                                cout << "Expected </" << curr << "> found </" << actual << ">" << endl;
                                proceed = false;
                            }
                        }
                    }
                }
                pos = toCheck.find("<", pos+1);
            }
            if(proceed) {
                if(tags.size() > 0) {
                    cout << "Expected </" << tags.front() << "> found #" << endl;
                } else {
                    cout << "Correctly tagged paragraph" << endl;
                }
            }
        }
    }
};

int main() {
    TagChecker tc;
#ifndef ONLINE_JUDGE
    istringstream input(test_data);
#else
    istream& input = cin;
#endif
    tc.readAndSolve(input);


    return 0;
}