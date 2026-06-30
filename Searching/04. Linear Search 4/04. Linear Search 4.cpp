#include <iostream>
#include <climits>   //De dung LLONG_MIN va LLONG_MAX
#include <algorithm> //De dung ham max()

using namespace std;

void solve() {
    int n;
    cin >> n;
    long long max1 = LLONG_MIN, max2 = LLONG_MIN;
    long long min1 = LLONG_MAX, min2 = LLONG_MAX;
    for (int i = 0; i < n; ++i) {
        long long x;
        cin >> x;
        if (x > max1) {
            max2 = max1; 
            max1 = x;
        }
        else if (x > max2) {
            max2 = x;    
        }
        if (x < min1) {
            min2 = min1; 
            min1 = x;    
        }
        else if (x < min2) {
            min2 = x;  
        }
    }

    
    long long case1 = max1 - min1;

  
    long long case2 = (max1 + max2) - (min1 + min2);

 
    cout << max(case1, case2) << "\n";
}

int main() {
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}