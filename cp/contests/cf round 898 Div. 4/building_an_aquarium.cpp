#include <bits/stdc++.h>
#define cout(x) cout << x
#define endl ('\n')

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ii = pair<int,int>;

constexpr int inf = 2e9+1;
constexpr int mod = 1e9+7;
constexpr ll maxnum = 3e5+100;

template<typename X, typename Y> bool ckmin(X& x, const Y& y) { return (y < x) ? (x=y,1):0; }
template<typename X, typename Y> bool ckmax(X& x, const Y& y) { return (x < y) ? (x=y,1):0; }

ll volume(vector<ll>& cols, ll height) {
    ll sum = 0;
    for (int i = 0; i < cols.size(); ++i) {
         
        sum += max(height - cols[i], 0LL);
    }
    return sum;
}

void solve() {
    ll n, x;
    cin >> n >> x;
    vector<ll> cols(n);
    for (int i = 0; i < n; ++i) {
        cin >> cols[i];
    }
    
    ll lowest = 0;
    ll highest = 2'000'000'007;
    
    while(lowest < highest) {
        ll middle = (highest - lowest + 1) / 2 + lowest;
        ll vol = volume(cols, middle);
        if (vol <= x) {
            lowest = middle;
        }
        else highest = middle - 1;
    }

    cout(lowest) << endl;
    
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int nt;
	cin >> nt;

	while(nt--) {
		solve();
	}

	return 0;
}
