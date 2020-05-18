#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

int N;
vector<int> org;
vector<int> inc;

int count_consec(int i, int j){
    return *max_element(inc.begin() + i, inc.end() - j );
}

void update_inc(){
    for (int i = 0, prev = 0; i < N; prev=inc[i], i++)
        inc[i] = org[i] != 0 ? org[i] + prev : 0;  
}

void flipBits(int i, int j){
    for(; i<j; i++)
        org[i] = org[i] == 0 ? 1 : 0;

    update_inc();
}


int main() {
    cin >> N;
    org.resize(N);
    inc.resize(N);
    for (int i = 0; i < N; i++) 
        cin >> org[i];
    update_inc();

    copy(org.begin(), org.end(), ostream_iterator<int>(cout, " "));  
    cout << endl;
    copy(inc.begin(), inc.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    
}