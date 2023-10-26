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
    str s;
    cin >> s;
    map<char, int> m;
    for(auto& c : s) {
        if(has(m,c)) {
            m[c]++;
        }
        else m.insert({c, 1});
    }

    while(m['o'] > 0 && m['n'] > 0 && m['e'] > 0) {
        m['o']--;
        m['n']--;
        m['e']--;

        print_s("1");
    }

    while(m['z'] > 0 && m['e'] > 0 && m['r'] > 0 && m['o'] > 0) {
        m['z']--;
        m['e']--;
        m['r']--;
        m['o']--;

        print_s("0");
    }
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
