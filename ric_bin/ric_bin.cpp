#include <iostream>
#include <fstream>

using namespace std;

int main() {
    int x;
    // Read from the text file
    ifstream inputFile("input.txt");
    inputFile >> x;
    ofstream outputFile("output.txt");
    outputFile << x;
    outputFile.close();

    return 0;
}
