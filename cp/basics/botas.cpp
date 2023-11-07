#include <bits/stdc++.h>

#define endl ('\n')
#define print(x) cout << x << endl
#define print_s(x) cout << x << ' '

#define loop(x, y) for(int x = 0; x < y; x++)
#define fin(x, y) for(auto& x : y)
#define midp(x, y) ((x + y) / 2)
#define has(x, y) (x.find(y) != x.end())
#define all(x) x.begin(), x.end()
#define sz(x) (x.size())
#define minel(x) *min_element(all(x))
#define maxel(x) *max_element(all(x))
#define f first
#define s second


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
    int n;
    cin >> n;
    map<int, map<char,int>> m;
    
    for (int i = 0; i < n; ++i) {
        int sz;     
        char l;
        cin >> sz >> l;
        
        if(!has(m, sz)) {
            m.insert({sz, {{l, 1}}});
        } 
        else if (!has(m[sz], l)) {
            m[sz].insert({l, 1});
        }
        
        else m[sz][l]++;
    }

    int ans = 0;
    fin(p, m) {
        ans += min(p.s['D'], p.s['E']); 
    }

    print(ans);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    solve();

    return 0;
}
