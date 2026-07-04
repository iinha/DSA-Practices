#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// adj la danh sach ke: adj[u] chua cac dinh ke voi u.
// Tra ve true neu ton tai duong di tu a den b, nguoc lai tra ve false.


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

    cout << (hasPath(adj, n, a, b) ? "YES" : "NO") << "\n";

    return 0;
}
