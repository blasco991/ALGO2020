#include <algorithm>
#include <vector>
#include <cassert>

using namespace std;

void visita(int N, vector<int> &PRE, vector<int> &POST, int *SIMM) {
    assert(PRE.size() == POST.size());
    if (PRE.size() == 1 && POST.size() == 1) {
        *find(SIMM, SIMM + N, 0) = PRE[0];
    } else {
        auto preEnd = find(PRE.begin() + 1, PRE.end(), POST[POST.size() - 2]);
        vector<int> vPRE(PRE.begin() + 1, preEnd);

        auto postEnd = find(POST.begin(), POST.end(), PRE[1]);
        vector<int> vPOST(POST.begin(), postEnd + 1);

        //VISITA LEFT
        visita(N, vPRE, vPOST, SIMM);

        *find(SIMM, SIMM + N, 0) = PRE[0];

        vector<int> vPRER(preEnd, PRE.end());
        vector<int> vPOSTR(postEnd + 1, POST.end() - 1);

        //VISITA RIGHT
        visita(N, vPRER, vPOSTR, SIMM);
    }

}

void visita(int N, int *PRE, int *POST, int *SIMM) {
    vector<int> vPRE(PRE, PRE + N);
    vector<int> vPOST(POST, POST + N);
    vector<int> vSIMM(SIMM, SIMM + N);
    visita(N, vPRE, vPOST, SIMM);
}