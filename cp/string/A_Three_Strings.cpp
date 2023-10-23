#include <bits/stdc++.h>

#define endl ('\n')
#define print(x) cout << x << endl

#define midp(x, y) ((x + y) / 2)
#define has(x, y) (x.find(y) != x.end())
#define all(x) (x.begin(), x.end())

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ii = pair<int, int>;
using ivec = vector<int>;
using str = string;

constexpr int inf = 2e9 + 1;
constexpr int mod = 1e9 + 7;
constexpr ll maxnum = 3e5 + 100;

void solve() {
    str a, b, c;
    cin >> a >> b >> c;
    
    set<int> diffs;
    for (int i = 0; i < a.size(); ++i) {
        if (a[i] != b[i]) diffs.insert(i); 
    }

    for (int i = 0; i < a.size(); ++i) {
        if (a[i] != b[i]) {
            if(c[i] != b[i] && c[i] != a[i]) {
                print("NO");
                return;
            }
        }
        
        else {
            if(c[i] != a[i]) {
                print("NO");
                return;
            }
        }
    }

    print("YES");
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int nt;
    cin >> nt;

    while (nt--) {
        solve();
    }

    return 0;
}
