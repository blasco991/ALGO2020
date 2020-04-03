#include <iostream>
#include <limits>

using namespace std;

int main() {
    long n = 3116285494907301262;

    printf("MAX int:\t\t\t\t%25d\n", numeric_limits<int>::max());
    printf("MAX unsigned int:\t\t\t%25u\n", numeric_limits<unsigned int>::max());
    printf("MAX long:\t\t\t\t%25ld\n", numeric_limits<long>::max());
    printf("MAX long int:\t\t\t\t%25ld\n", numeric_limits<long int>::max());
    printf("MAX long long:\t\t\t\t%25lld\n", numeric_limits<long long>::max());
    printf("MAX long long int:\t\t\t%25lld\n", numeric_limits<long long int>::max());
    printf("MAX unsigned long long:\t\t\t%25llu\n", numeric_limits<unsigned long long>::max());
    printf("MAX unsigned long long int:\t\t%25llu\n", numeric_limits<unsigned long long int>::max());

    printf("can int contain 35th catalan?  \t\t\t\t%3d\n", numeric_limits<int>::max() > n);
    printf("can unsigned int contain 35th catalan?  \t\t%3d\n", numeric_limits<unsigned int>::max() > n);
    printf("can long contain 35th catalan?  \t\t\t%3d\n", numeric_limits<long>::max() > n);
    printf("can long int contain 35th catalan?  \t\t\t%3d\n", numeric_limits<long int>::max() > n);
    printf("can long long contain 35th catalan?  \t\t\t%3d\n", numeric_limits<long long>::max() > n);
    printf("can long long int contain 35th catalan?  \t\t%3d\n", numeric_limits<long long int>::max() > n);
    printf("can unsigned long long contain 35th catalan?  \t\t%3d\n", numeric_limits<unsigned long long>::max() > n);
    printf("can unsigned long long int contain 35th catalan?  \t%3d\n", numeric_limits<unsigned long long int>::max() > n);

}