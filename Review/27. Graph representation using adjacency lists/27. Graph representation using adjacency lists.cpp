

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

// In ra danh sach ke cua tung dinh (1..n).
// adj[i] da duoc xay dung va sap xep tang dan san trong main.
// Yeu cau: n dong, dong i la cac dinh ke cua dinh i cach nhau 1 khoang trang;
// dinh khong co dinh ke nao -> in mot dong trong.
void solve(int n, const vector<vector<int>>& adj) {
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

    solve(n, adj);

    return 0;
}
