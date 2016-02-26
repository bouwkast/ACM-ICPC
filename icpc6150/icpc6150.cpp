#include <iostream>
#include <sstream>
#include <map>

using namespace std;

#ifndef ONLINE_JUDGE
string test_data = "aaaaaaaaaaaaaaaaaaaaaaaaaaa\n"
        "\n"
        "\n"
        "\n"
        "aaaaaaaaaaaaaaaa4aaaaaaaaaaaa\n"
        "\n"
        "\n"
        "aaaaaaaaaaaaaaaaaaaaaaaaaabbbbbbbbbbbbbbb\n"
        "aaaaaaaaaaaaaaaa-a-a-a-a-a4-a-a-a\n"
        "\n"
        "\n"
        "\n"
        "E-N-D";
#endif

class LongestWord {
public:
    string data;

    void readData(istream &input) {
        string line;
        while(getline(input, line)) {
            if(line == "E-N-D") break;
            data += line + "\n";
            line = "";
        }
    }

    void solve() {
        string word = "";
        string longest = "";
        bool updated = false;
        int len = 0;
        for(int i = 0; i < data.size(); ++i) {
            if(isalpha(data.at(i)) || data.at(i) == '-') {
                word += tolower(data.at(i));
            } else {
                if(!word.empty()) {
                    if(word != "e-n-d") {
                        int wordSize = word.size();
                        if(wordSize > len) {
                            len = wordSize;
                            longest = word;
                        }
                        word = "";
                    }
                }
            }
        }
        cout << longest << endl;
    }
};

int main() {
LongestWord lg;
#ifndef ONLINE_JUDGE
    istringstream input(test_data);
#else
    istream& input = cin;
#endif
    lg.readData(input);
    lg.solve();

    return 0;
}