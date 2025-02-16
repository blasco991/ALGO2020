#include <vector>
#include <iostream>
#include <sstream>

void checkCode(int attempt[], int result[]);
void pensoCheCodiceSia(int risposta[]);

using namespace std;

void solve() {
    int res[2];

    string num[] = {"0", "1", "2", "3", "4", "5"};

    for (auto &i1 : num)
        for (auto &i2 : num)
            for (auto &i3 : num)
                for (auto &i4 : num) {
                    int sol[4];
                    ostringstream stringStream;
                    stringStream << i1 << i2 << i3 << i4;
                    string copyOfStr = stringStream.str();
                    for (int i = 0; i < copyOfStr.length(); i++)
                        sol[i] = copyOfStr[i] - '0';

                    checkCode(sol, res);
                    if (res[0] == 4)
                        pensoCheCodiceSia(sol);
                }
}