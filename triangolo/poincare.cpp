#include<stdio.h>
#include<math.h>

void serie(int n) {

    int element[(int) pow(2, n - 1)];
    int i, j, k;

    element[0] = 0;
    printf("0\n");
    j = 0;
    for (i = 1; i < n; i++) {
        for (k = 0; k <= j; k++)
            element[j + 1 + k] = element[k] + 1;
        j = j * 2 + 1;
        for (k = 0; k <= j; k++)
            printf("%d", element[k]);
        printf("\n");
    }
}

int main() {
    int n;
    scanf("%d", &n);
    serie(n);

    return 0;
}