// including all the c++ standard library
#include <bits/stdc++.h>

// colors to avoid confusion in the console output
#define RED "\033[31m"
#define WHITE "\033[0m"

// end line
#define endl ('\n')

// output macros
#define reset() cout << WHITE
#define print(x) cout << RED << x
#define cout(x) cout << x

// containers macros
#define pb push_back
#define add insert
#define has(x, y) x.find(y) != x.end()
#define all(x) x.begin(), x.end()

using namespace std;

// numerical types
using ll = long long;
using ull = unsigned long long;
using ii = pair<int,int>;

// numerical constants 
constexpr int inf = 2e9+1;
constexpr int mod = 1e9+7;
constexpr ll maxnum = 3e5+100;

// swap functions
template<typename X, typename Y> bool ckmin(X& x, const Y& y) { return (y < x) ? (x=y,1):0; }
template<typename X, typename Y> bool ckmax(X& x, const Y& y) { return (x < y) ? (x=y,1):0; }

void solve() {

}

int main() {
    // desynching cin with stio
	cin.tie(0)->sync_with_stdio(0);
	int nt;
	cin >> nt;

	while(nt--) {
        // here I change the color of the terminal to white again
		reset;
		solve();
	}

	return 0;
}