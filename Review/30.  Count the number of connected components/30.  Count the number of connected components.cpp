#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Dem so thanh phan lien thong cua do thi vo huong.
// Goi y: duyet moi dinh, moi khi gap dinh chua tham thi tang bien dem
// roi DFS/BFS danh dau toan bo dinh cung thanh phan. Tra ve so dem.
// adj[i] da duoc sap xep tang dan san trong main.
int solve(int n, const vector<vector<int>>& adj) {
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) {
        sort(adj[i].begin(), adj[i].end());
    }

    cout << solve(n, adj) << "\n";

    return 0;
}

