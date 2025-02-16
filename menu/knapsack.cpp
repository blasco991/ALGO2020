#include <iostream>
#include <vector>

using namespace std;
vector<int> val;

void printknapSack(int W, int wt[], int val[], int n) {
    int i, w;
    int K[n + 1][W + 1];

    for (i = 0; i <= n; i++) {
        for (w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (wt[i - 1] <= w)
                K[i][w] = max(val[i - 1] +
                              K[i - 1][w - wt[i - 1]], K[i - 1][w]);
            else
                K[i][w] = K[i - 1][w];
        }
    }

    int res = K[n][W];

    w = W;
    for (i = n; i > 0 && res > 0; i--) {

        // either the result comes from the top
        // (K[i-1][w]) or from (val[i-1] + K[i-1]
        // [w-wt[i-1]]) as in Knapsack table. If
        // it comes from the latter one/ it means
        // the item is included.
        if (res == K[i - 1][w])
            continue;
        else {

            // This item is included.
            printf("%d\n", wt[i - 1]);

            // Since this weight is included its value is deducted
            res = res - val[i - 1];
            w = w - wt[i - 1];
        }
    }
}

int main() {
    int N, B;
    cin >> N >> B;
    val.resize(N);
    for (int i = 0; i < N; i++) cin >> val[i];

    printknapSack(B, val.data(), val.data(), N);

    return 0;
}