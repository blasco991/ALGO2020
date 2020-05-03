#include<iostream>
#include<fstream>
#include<string>
#include<vector>

 
using namespace std;

uint32_t findPos(uint32_t start, uint32_t end, uint32_t& newNumber, vector<uint32_t>& vec) {
  if(start == end) return start;
  if(vec[end - 1] > newNumber) return end;
  if(end - start == 1) return start;

  uint32_t mid = (start + end) / 2;
  if(vec[mid] > newNumber) {
    return findPos(mid + 1, end, newNumber, vec);
  } else if (vec[mid] < newNumber) {
    return findPos(start, mid, newNumber, vec);
  } else {
    return mid;
  }
}

void solve(uint32_t& newNumber, vector<uint32_t>& vec) {
  uint32_t pos = findPos(0,vec.size(),newNumber, vec);
  if(pos == vec.size())
    vec.push_back(newNumber);
  else
    vec[pos] = newNumber;
}

int main(int argc, char** argv)
{
    #ifdef EVAL
    //==========================
    //PARTE OBBLIGATORIA UTILITY
    //==========================
    ifstream fileIn;
    fileIn.open("input.txt");
    ofstream fileOut;
    fileOut.open("output.txt");

    if(!fileIn.is_open() || !fileOut.is_open()) return -1;

    cin.rdbuf(fileIn.rdbuf());
    cout.rdbuf(fileOut.rdbuf());
    #endif

    uint32_t n;
    cin >> n;

    auto sVect = vector<uint32_t>();

    uint32_t temp;
    for(uint32_t i = 0; i < n; i++) {
        cin >> temp;
        solve(temp,sVect);
    }
    cout << sVect.size();
    return 0;
}
