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
    int n, k; 
    cin >> n >> k;
    
    map<int,int> occ;
    set<int> k_occ;

    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;
        if (!has(occ, val)) {
            occ[val] = 1;
        } 
        else occ[val]++;
        
        if(occ[val] == k) {
            k_occ.insert(val);
        }
        else if(occ[val] != k && has(k_occ, val)) {
            k_occ.erase(val);
        }
    }

    ivec vec;
    fin(val, k_occ) vec.push_back(val);
    
    int l_max = -1, r_max = -1;
    int l = vec[0], r = -1;

    for (int i = 1; i < n; ++i) {
        if(vec[i] == vec[i - 1] + 1) {
            r = i;
        } 
        else {
            if(vec[r] - vec[l] > r_max - l_max) {
                l_max = vec[l];
                r_max = vec[r];
            }
            l = i;
        }
    }

    print_s(l_max);
    print_s(r_max);
    print("");
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif

    int nt;
    cin >> nt;

    while (nt--) {
        solve();
    }

    return 0;
}
