#include <iostream>
#include <sstream>

using namespace std;
#ifndef ONLINE_JUDGE
string test_data = "3 \n"
        "5 10 \n"
        "7 23 \n"
        "42 56";
#endif

class LeastGreatest {
public:
    int tests;
    int round = 1;
    int a, b;

    void readAndSolve(istream &input) {
        for(int i = 0; i < tests; ++i) {
            input >> a;
            input >> b;
            cout << round++ << " " << lcm(a, b) << " " << gcd(a, b) << endl;
        }

    }

    /**
     * Finds the GCD of two ints
     * example a = 45 b = 54
     * after the first recursive call a = 54 b = 45
     * after the second recursive call a = 45 b = 9
     * after the third recursive call a = 9 b = 0, it will then return 9
     */
    int gcd(int a, int b) {
        if(b == 0) return a;
        return gcd(b, a % b);
    }

    /**
     * Finds the lcm of two integers
     * It is known that the lcm of two ints is there prime factors all multiplied together
     * a * b / gcd(a, b) is a known formula for lcm
     */
    int lcm(int a, int b) {
        return a * (b / gcd(a, b));
    }
};

int main() {
    LeastGreatest lg;
#ifndef ONLINE_JUDGE
    istringstream input(test_data);
#else
    istream& input = cin;
#endif
    input >> lg.tests;
    lg.readAndSolve(input);
    return 0;
}