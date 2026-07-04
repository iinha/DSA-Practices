#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// adj la danh sach ke. Tra ve so dinh thuoc thanh phan lien thong chua dinh a.


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

    int a;
    cin >> a;

    cout << componentSize(adj, n, a) << "\n";

    return 0;
}
