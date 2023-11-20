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
using ivec = vector<ll>;
using imat = vector<vector<int>>;
using str = string;

constexpr int inf = 2e9 + 1;
constexpr int mod = 1e9 + 7;
constexpr ll maxnum = LONG_LONG_MAX;

ll build(ivec& st, ivec& arr, int p, int l, int r) {
    if(l == r) {
       st[p] = arr[l];
        return st[p];
    } 
    
    int mid = midp(l, r);
    st[p] = build(st, arr, p * 2, l, mid) + build(st, arr, p * 2 + 1, mid + 1, r);
    
    return st[p];
}

ll query(ivec& st, int a, int b, int p,  int l, int r) {
    if(b < l || r < a) return 0;
    if(a <= l && r <= b) {
        return st[p];
    } 
   
    int m = midp(l, r);
    
    return query(st, a, b, 2 * p, l, m) + query(st, a, b, 2 * p + 1, m + 1, r);
}

void solve() {
    int n;
    cin >> n;
    ivec weights(n);
    ivec prefix(n);

    ll sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> weights[i];
        sum += weights[i]; 
        prefix[i] = sum; 
    }
    
//    ivec st(4 * n + 1);
//    build(st, weights, 1, 0, n - 1);

    ll maxdiff = LONG_LONG_MIN;
    for (int i = 1; i <= n; ++i) {
        if(n % i != 0) continue;
        ll lmax = LONG_LONG_MIN, lmin = LONG_LONG_MAX;
        for (int j = 0; j < n; j += i) {
            ll val;
            if(j - 1 >= 0) {
                val = prefix[j + i - 1] - prefix[j - 1];
            } 
            else val = prefix[j + i - 1];
            
            if(val > lmax) {
                lmax = val;
            }
            if(val < lmin) {
                lmin = val;
            }
        }

        ll diff = lmax - lmin;
        if(maxdiff < diff) {
            maxdiff = diff;
        }
    }
    
    print(maxdiff);
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
