#include <iostream>
#include <vector>

using namespace std;

vector<int> adj[1000000];

void search(int n) {
    for (int i = 0; i < adj[n].size(); i++)
        if (adj[n][i] >= 0) {
            int x = adj[n][i];
            adj[n][i] = -1;
            for (int &k : adj[x])
                if (k == n) {
                    k = -1;
                    break;
                }

            searc(x);
            printf("%d %d\n", x, n);
        }
}

int main() {
#ifdef    EVAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int N, M, A, B;
    cin >> N >> M >> A >> B;
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a;
        cin >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    search(B);
}