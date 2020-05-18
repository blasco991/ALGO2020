#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

int N;
<<<<<<< HEAD
vector<int> inc;

int count_consec(int i, int j){
    return *max_element(inc.begin() + i, inc.end());
}

void update_inc(){
    for (int i = 0, prev = 0; i < N; i++){
        inc[i] = inc[i] != 0 ? inc[i] + prev : 0;
        prev=inc[i]; 
    }
=======
vector<int> org;
vector<int> inc;

int count_consec(int i, int j){
    return *max_element(inc.begin() + i, inc.end() - j );
}

void update_inc(){
    for (int i = 0, prev = 0; i < N; prev=inc[i], i++)
        inc[i] = org[i] != 0 ? org[i] + prev : 0;  
>>>>>>> b4e00c79d7292cf242cddccf6b12847a2ea5bcaa
}

void flipBits(int i, int j){
    for(; i<j; i++)
<<<<<<< HEAD
        inc[i] = inc[i] == 0 ? 1 : 0;
=======
        org[i] = org[i] == 0 ? 1 : 0;
>>>>>>> b4e00c79d7292cf242cddccf6b12847a2ea5bcaa

    update_inc();
}


int main() {
    cin >> N;
<<<<<<< HEAD
    inc.resize(N);
    for (int i = 0; i < N; i++) 
        cin >> inc[i];
    update_inc();
    
    int M;
    cin >> M;
    
    for(int k=0, t, i, j; k < M; k++){
        cin >> t >> i >> j;
        if(t==0) 
            cout << count_consec(i-1,j) << endl;
        /*else flipBits(i-1,j); 
        /
        copy(inc.begin(), inc.end(), ostream_iterator<int>(cout, " "));
        cout << endl;
        copy(inc.begin(), inc.end(), ostream_iterator<int>(cout, " "));
        cout << endl << endl;
        */
    }

=======
    org.resize(N);
    inc.resize(N);
    for (int i = 0; i < N; i++) 
        cin >> org[i];
    update_inc();

    copy(org.begin(), org.end(), ostream_iterator<int>(cout, " "));  
    cout << endl;
    copy(inc.begin(), inc.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    
>>>>>>> b4e00c79d7292cf242cddccf6b12847a2ea5bcaa
}