#include <iostream>
#include <vector>
using namespace std;

// adj la danh sach ke. Dem so duong di don (khong lap dinh) tu a den b.


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

    int a, b;
    cin >> a >> b;

    cout << countPaths(adj, n, a, b) << "\n";

    return 0;
}
