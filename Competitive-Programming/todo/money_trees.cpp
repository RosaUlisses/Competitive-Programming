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

int N = 200'000;

bool get(vector<int>& prefixes, vector<int>& lengths, int dist, int k) {
    if (dist > prefixes.size()) return false;

    for (int i = 0; i < lengths.size() - dist + 1; ++i) {
        if (lengths[i] < dist) continue; 
        int sum = prefixes[i + dist] - prefixes[i];
        if (sum <= k) {
            return true;
        }
    }
    
    return false;
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<ii> array;
    for (int i = 0; i < n; ++i) {
        int ai; 
        cin >> ai;
        array.push_back({0, ai});
    }
    for (int i = 0; i < n; ++i) {
        cin >> array[i].first;
    }
    
    vector<int> prefixes(n);
    int accumulator = 0;
    for (int i = 0; i < array.size(); ++i) {
        prefixes[i] = array[i].second + accumulator;
        accumulator += array[i].second;
    }
    
    vector<int> lengths(n);
    lengths[n] = 1;
    for (int i = n - 2; i >= 0; --i) {
        if (array[i].first % array[i].second == 0) {
            lengths[i] = lengths[i + 1] + 1;
        }
        else lengths[i] = 1;
    }
   
    int l = 1, r = N; 
    while(l < r) {
        int mid = (r + l) / 2;
        if (get(prefixes, lengths, mid, k)) {
            
        }
    }

}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int nt;
	cin >> nt;

	while(nt--) {
//        reset();
		solve();
	}

	return 0;
}
