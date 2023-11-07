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
    ivec arr(n);
    map<int, set<int>> m;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i]; 
        if(!has(m, arr[i])) {
            m.insert({arr[i], {i}}); 
        }
        else {
            m[arr[i]].insert(i);
        }
    }
    
    vector<ii> swaps;
    int curr = n - 1;
    for (int i = 0; i < n; ++i) {
        auto p = maxel(m);
        
        int max_val = p.f;
        set<int> ixs = p.s;
        
        fin(ix, ixs) {
            if (ix == curr) continue;
            int val = arr[curr];
            m[val].erase(curr);
            m[val].insert(ix);
            arr[curr] = max_val;
            arr[ix] = val;
            swaps.push_back({ix, curr});
            curr--;
        }
    }
    
    
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    solve();

    return 0;
}
