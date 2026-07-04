#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// adj la danh sach ke. Tra ve so dinh cua thanh phan lien thong lon nhat.


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

    cout << largestComponent(adj, n) << "\n";

    return 0;
}
