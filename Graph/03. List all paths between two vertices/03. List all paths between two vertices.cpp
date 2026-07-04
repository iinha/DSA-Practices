#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// adj la danh sach ke (da duoc sap xep tang dan trong main).
// Liet ke tat ca duong di don tu a den b theo thu tu DFS.
// In "KHONG CO" neu khong co duong di nao.



int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int> > adj(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 0; i < n; i++) {
        sort(adj[i].begin(), adj[i].end());
    }

    int a, b;
    cin >> a >> b;

    listPaths(adj, n, a, b);

    return 0;
}
