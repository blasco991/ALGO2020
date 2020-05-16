#include <algorithm>
#include <iostream>
#include <iterator>
#include <cassert>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

string visita(vector<int> &PRE, vector<int> &POST) {
    //assert(PRE.size() == POST.size());

    if (PRE.empty())
        return "";
    else {
        auto preEnd = find(PRE.begin() + 1, PRE.end(), POST[POST.size() - 2]);
        vector<int> vPRE(PRE.begin() + 1, preEnd);

        auto postEnd = find(POST.begin(), POST.end(), PRE[1]);
        vector<int> vPOST(POST.begin(), postEnd + 1);

        //VISITA LEFT
        string s1 = visita(vPRE, vPOST);

        vector<int> vPRER(preEnd, PRE.end());
        vector<int> vPOSTR(postEnd + 1, POST.end() - 1);

        //VISITA RIGHT
        return s1 + " " + to_string(PRE[0]) + " " + visita(vPRER, vPOSTR);
    }

}

void visita(int N, int *PRE, int *POST, int *SIMM) {
    vector<int> vPRE(PRE, PRE + N);
    vector<int> vPOST(POST, POST + N);
    stringstream ssin(visita(vPRE, vPOST));
    for (int i = 0; ssin.good(); i++) {
        ssin >> SIMM[i];
    }
}

