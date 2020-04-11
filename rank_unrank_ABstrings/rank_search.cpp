#include <iostream>
#include <bitset>
#include <algorithm>

using namespace std;
const int MAX = 100;
int length, r;
string input;

unsigned long ABstring2rank(string s){
    replace( s.begin(), s.end(), 'A', '0' );
    replace( s.begin(), s.end(), 'B', '1' );
    return  bitset<MAX>(s).to_ulong();
}

string ABstring_of_len_and_rank(int n) {
    string s = bitset<MAX>(r).to_string().substr(MAX-length);
    replace( s.begin(), s.end(), '0', 'A' );
    replace( s.begin(), s.end(), '1', 'B' );
    return s;
}

int main() {

    if (scanf("%d %d", &length, &r) == 2){
        cout << ABstring_of_len_and_rank(r) << endl;
    } else {
        cin >> input;
        length = input.size();
        cout << ABstring2rank(input) << endl;
    }

}