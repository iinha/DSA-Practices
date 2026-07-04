#include <iostream>
#include <vector>
using namespace std;

// adj la ma tran ke kich thuoc n x n.
// Tra ve so dinh co lap (dinh khong co canh noi toi dinh nao khac).



int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int> > adj(n, vector<int>(n, 0));
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    cout << countIsolated(adj, n) << "\n";

    return 0;
}
