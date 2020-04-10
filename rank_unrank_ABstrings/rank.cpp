#include <iostream>
#include <cmath>       /* pow */
#include <algorithm>

using namespace std;

int length, r;
string input;

unsigned long long ABstring2rank(string s){
    long long n = 0;
    for(unsigned long long i=0; i < s.length(); i++)
        n += s[i]-'A' > 0 ? (int) pow(2,length-i-1) : 0;

    return n;
}

string ABstring_of_len_and_rank(int n) {
    string s;
    for (int i = 0; i < length ; i++, n /= 2)
        s += n % 2 == 1 ? 'B' : 'A';
    reverse(s.begin(), s.end());
    return s;
}

int main() {

    if (scanf("%d %d", &length, &r) == 2){
        //cout << bitset<100>(r).to_string();
        cout << ABstring_of_len_and_rank(r) << endl;
    } else {
        cin >> input;
        length = input.size();
        cout << ABstring2rank(input) << endl;
    }

}