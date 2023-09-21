#include <bits/stdc++.h>
#define RED ("\033[31m")
#define WHITE ("\033[0m")
#define reset() cout << WHITE
#define print(x) cout << RED << x
#define cout(x) cout << x
#define endl ('\n')
#define pb push_back
#define add insert
#define has(x, y) (x.find(y) != x.end())
#define all(x) x.begin(), x.end()

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ii = pair<int,int>;

constexpr int inf = 2e9+1;
constexpr int mod = 1e9+7;
constexpr ll maxnum = 3e5+100;

template<typename X, typename Y> bool ckmin(X& x, const Y& y) { return (y < x) ? (x=y,1):0; }
template<typename X, typename Y> bool ckmax(X& x, const Y& y) { return (x < y) ? (x=y,1):0; }

int b_search(vector<int>& vec, int val) {
    int begin = 0; 
    int end = vec.size() -1;
    
    int last_middle = 0;
    while(begin > end) {
        int middle = (end - begin) / 2 + begin;
        if (middle == val) return middle;
        if (vec[middle] > val) end = middle;
        else begin = end;
        last_middle = middle;
    }
    
    return last_middle; 
}

void solve() {
    ll n, x;
    cin >> n >> x;
    vector<int> cols(n);
    for (int i = 0; i < n; ++i) {
        cin >> cols[i];
    }

    sort(cols.begin(), cols.end());

    ll volume = 0;
    for (int i = 1; true ; ++i) {
        volume += b_search(cols, i);
        if (volume)
    }
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
