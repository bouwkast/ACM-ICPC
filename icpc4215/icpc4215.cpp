#include <iostream>
#include <sstream>

using namespace std;
/**
 * Answer comes out to the summation of all the squares from
 * 1 to n.
 *
 * So if n = 3 it would be 1^2 + 2^2 + 3^3
 *
 * From here we have it equal to the summation from i = 1 to n
 * We can then either just do this in a loop or find an equation to solve
 * it even quicker. However this is a fairly popular formula and we also
 * went over what it is in MTH 225
 *
 * Formula = n(n+1)(2n+1) / 6
 * Examples:
 * n = 2 there are 5 squares
 * 2(3)(5) / 6 = 30 / 6 = 5
 * 8(9)(17) / 6 = 1224 / 6 = 204
 *
 * Proof by mathematical induction, trying to prove true for n+1
 * Base Case: n = 1, 1(2)(3) / 6 = 1; 1 = 1, so it is true
 * Induction Hypo = for some positive int k, 1^2+2^2+3^2+...k^2 = k(k+1)(2k+1) / 6
 * Prove that for k+1, 1^2+2^2+3^2+...k^2 + (k+1)^2 = (k+1)(k+2)(2k+3) / 6
 *
 * We know that 1^2+2^2+3^2+...k^2 = k(k+1)(2k+1), so we can use the right in our
 * statement that we are trying to prove, giving us the left hand side of:
 * k(k+1)(2k+1) / 6 + (k+1)^2
 * We now want to take this and simplify it down, so first we multiply (k+1)^2 by 6
 * giving us k(k+1)(2k+1) + 6(k+1)^2 / 6
 * Pull out a (k+1) giving us: (k+1)(k(2k+1) + 6(k+1) / 6
 * Simplify and combine like terms:
 * ((k+1)(2k^2+7k+6))/6 which factors down to
 * (k+1)(k+2)(2k+3) / 6 which proves the formula
 *
 */

#ifndef ONLINE_JUDGE
string test_data = "2\n"
        "1\n"
        "8\n"
        "0";
#endif

class FeynmanSquares {
public:
    void readAndSove(istream &input) {
        int k = 0;
        while(input >> k){
            if(k == 0) return;

            int solution = k * (k + 1) * (2*k+1) / 6;
            cout << solution << endl;
            k = 0;
        }
    }
};

int main() {
    FeynmanSquares fs;
#ifndef ONLINE_JUDGE
    istringstream input(test_data);
#else
    istream& input = cin;
#endif
    fs.readAndSove(input);
    return 0;
}