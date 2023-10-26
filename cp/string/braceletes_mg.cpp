#include <bits/stdc++.h>

#define endl ('\n')
#define print(x) cout << x << endl
#define print_s(x) cout << x << ' '

#define midp(x, y) ((x + y) / 2)
#define has(x, y) (x.find(y) != x.end())
#define all(x) x.begin(), x.end()
#define sz(x) (x.size())
#define lix(x) (x.size() - 1)

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ii = pair<int, int>;
using ivec = vector<int>;
using imat = vector<vector<int>>;
using str = string;

constexpr int inf = 2e9 + 1;
constexpr int mod = 1e9 + 7;
constexpr ll maxnum = 3e5 + 100;

void solve() {
    string mw, b;
    cin >> mw >> b;

    if (b.find(mw) != string::npos) {
        print("S");
        return;
    }

    string summed = b + b;

    if (summed.find(mw) != string::npos) {
        print("S");
        return;
    }

    string rv = b;
    reverse(all(rv));
    if (rv.find(mw) != string::npos) {
        print("S");
        return;
    }

    print("N");
}

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        solve(); 
    }
    
    return 0;
}
