#include <iostream>
#include <sstream>

using namespace std;

int main() {
    string num[] = {"0", "1", "2", "3", "4", "5"};

    for (auto &i1 : num) {
        for (auto &i2 : num) {
            for (auto &i3 : num) {
                for (auto &i4 : num) {
                    int sol[4];
                    ostringstream stringStream;
                    stringStream << i1 << i2 << i3 << i4;
                    string copyOfStr = stringStream.str();
                    for (int i = 0; i < copyOfStr.length(); i++) {
                        sol[i] = copyOfStr[i] - '0';
                    }
                }
            }
        }
    }
    return 0;
}
