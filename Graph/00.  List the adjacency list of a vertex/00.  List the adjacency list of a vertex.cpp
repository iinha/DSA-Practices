#include <iostream>
#include <vector>
using namespace std;

// adj la ma tran ke kich thuoc n x n, adj[i][j] = 1 neu co canh noi i va j
// In ra cac dinh ke voi u theo thu tu tang dan, hoac "KHONG CO" neu khong co.


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

    int u;
    cin >> u;

    printNeighbors(adj, n, u);

    return 0;
}
