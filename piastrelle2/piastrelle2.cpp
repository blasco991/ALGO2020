#include <iostream>
#include <fstream>

using namespace std;

string possible1(int n, string p);

string possible2(int n, string p);

string possible1(int n, string p) {

    if (n == 1)
        return p + "[O]\n";

    if (n > 1)
        return possible1(n - 1, p + "[O]") + possible2(n - 1, p + "[O]");

    return "";

}

string possible2(int n, string p) {

    if (n == 2)
        return p + "[OOOO]\n";

    if (n > 2)
        return possible1(n - 2, p + "[OOOO]") + possible2(n - 2, p + "[OOOO]");

    return "";
}

int main() {
    int n;

    ifstream inputFile("input.txt");
    ofstream outputFile("output.txt");
    inputFile >> n;
    outputFile << possible1(n, "");
    outputFile << possible2(n, "");
    outputFile.close();
    inputFile.close();
    return 0;
}