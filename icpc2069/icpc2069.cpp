#include <iostream>
#include <map>
#include <sstream>

using namespace std;
#ifndef ONLINE_JUDGE
string test_data = "4 \n"
        "John dire direct direction \n"
        "Jane direkt \n"
        "Joan direction \n"
        "Janet vondire direction \n"
        "2 \n"
        "john great admired politician \n"
        "Kim great loss poorer \n"
        "2 \n"
        "peter moral choice \n"
        "paul moral choice \n"
        "0";
#endif

class GameThing{
private:
    int players, wordPos[9];
    string line, word;
    string name[9];
    string wordChoices[9][9];
    map<string, int> wordCount;
    double scores[9];
    int round = 1;
public:
    void readAndSolve(istream &input) {
        while(true) {
            input >> players;
            if(players == 0) break; // end case

            getline(input, line); // get the next line
            wordCount.clear(); // empty the map

            for(int i = 0; i < players; ++i) {
                getline(input, line); // get the line for player (i)
                istringstream playerLine(line);

                playerLine >> name[i]; // store the name into the array of names
                wordPos[i] = 0; // looking at the first word after their name

                while(playerLine >> wordChoices[i][wordPos[i]]) {
                    ++wordCount[wordChoices[i][wordPos[i]]];
                    wordPos[i]++;
                }
            }

            double bestScore = -1.0;
            for(int j = 0; j < players; ++j) {
                double currScore = 0;

                for(int k = 0; k < wordPos[j]; ++k) {
                    // the times 2520 is just to ensure that the score works as an int
                    //Further explaination is that 2520 is the smallest # that is divisible by the ints from 1 to 10
                    currScore += wordChoices[j][k].size() * 2520 / wordCount[wordChoices[j][k]];
                }
                bestScore = max(bestScore, currScore);// looking for  the highest score overall
                scores[j] = currScore; // that player's score

            }
            cout << "Round " << round++ << endl;
            bool firstOut = true;
            for(int i = 0; i < players; ++i) {
                if(scores[i] == bestScore) {
                    if(!firstOut) cout << ' ';
                    firstOut = false;
                    cout << name[i];
                }
            }
            cout << "" << endl;
        }
    }
};

int main() {
    GameThing gt;
#ifndef ONLINE_JUDGE
    istringstream input(test_data);
#else
    istream& input = cin;
#endif
    gt.readAndSolve(input);
    return 0;
}