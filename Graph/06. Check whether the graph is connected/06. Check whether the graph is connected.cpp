#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// adj la ma tran ke kich thuoc n x n.
// Tra ve true neu do thi lien thong (chi co mot thanh phan lien thong).


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

    cout << (isConnected(adj, n) ? "YES" : "NO") << "\n";

    return 0;
}
