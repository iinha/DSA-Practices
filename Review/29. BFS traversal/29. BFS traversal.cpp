#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

// Duyet BFS tu dinh s, in thu tu cac dinh tham duoc tren 1 dong.
// Khi dua cac dinh ke vao hang doi, uu tien dinh co so thu tu nho hon.
// adj[i] da duoc sap xep tang dan san trong main.
void solve(int n, const vector<vector<int>>& adj, int s) {
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

    int s;
    cin >> s;

    solve(n, adj, s);

    return 0;
}
