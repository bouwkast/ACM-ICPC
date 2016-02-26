#include <iostream>
#include <map>
#include <sstream>
#include <vector>

using namespace std;

#ifndef ONLINE_JUDGE
string test_data = "This is a simple file of test data, which should\n"
        "not cause your program any trouble. Do note that\n"
        "it contains several punctuation characters. Of course,\n"
        "this is not really a problem, because such characters\n"
        "are treated in the same way as spaces.\n"
        "#\n"
        "Don't use contractions; it isn't nice.\n"
        "#\n"
        "aBc def AbC def dfe ABC\n"
        "#\n"
        "123\n"
        "#";
#endif

class MostValuedWord {
public:
    map<string, int> wordFreq;
    string data;
    void readData(istream &text) {
        string word;
        int count = 0;

        while(getline(text, word)) {
            if(word.empty()) break;
            data += word + "\n";
            word = "";
        }
    }

    void solve() {
        string word = "";
        string mostFreq  = "";
        bool updated = false;
        int freq = 0;
        if(data.size() == 0) {
            return;
        }
        for(int i = 0; i < data.size(); ++i) {
            if(isalpha(data.at(i))) { // is a letter
                word += tolower(data.at(i));
            } else { // not a letter, add to map
                if(!word.empty()) {
                    updated = true;
                    wordFreq[word]++;
                    if(wordFreq[word] > freq) {
                        mostFreq = word;
                        freq = wordFreq[word];
                    }
                    word = "";
                }
            }
            if(data.at(i) == '#') {
                if(updated) {
                    auto it = wordFreq.begin();
                    if(freq < 10) {
                        cout << "   " << freq;
                    } else if (freq < 100) {
                        cout << "  " << freq;
                    } else if (freq < 1000) {
                        cout << " " << freq;
                    } else {
                        cout << freq;
                    }
                    cout << " " << mostFreq << endl;
                    wordFreq.clear();
                    word = "";
                    mostFreq = "";
                    freq = 0;
                    updated = false;
                } else {
                    break;
                }

            }
        }
    }
};

int main() {
    MostValuedWord mvw;
#ifndef ONLINE_JUDGE
    istringstream input(test_data);
#else
    istream& input = cin;
#endif
    mvw.readData(input);
    mvw.solve();
    return 0;
}