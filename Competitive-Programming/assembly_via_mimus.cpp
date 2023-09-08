#include <bits/stdc++.h>
#define RED "\033[31m"
#define RESET "\033[0m"
#define print cout << RED
#define reset cout << RESET

#define cout(x) cout << x
#define pb push_back
#define add insert
#define has(x, y) x.find(y) != x.end()
#define sz(x) ((int) x.size())
#define all(x) x.begin(), x.end()

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ii = pair<int,int>;

const int inf = 2e9+1;
const int mod = 1e9+7;
const ll maxnum = 3e5+100;

template<typename X, typename Y> bool ckmin(X& x, const Y& y) { return (y < x) ? (x=y,1):0; }
template<typename X, typename Y> bool ckmax(X& x, const Y& y) { return (x < y) ? (x=y,1):0; }


void solve() {
   int a; 
   cin >> a;
   int b = a * (a - 1) / 2;
   vector<int> array(b);
    for (int i = 0; i < b; ++i) {
        cin >> array[i]; 
    }
    sort(all(array));
    vector<int> result;

    int index = 0;
    for (int i = 0; i < a - 1; ++i) {
        result.push_back(array[index]);
        index += (a - 1) - i;
    }

    if (array[array.size() - 1] <  1000000000) {
        result.push_back(array[array.size() - 1] + 1);
    }
    else result.push_back(array[array.size() - 1]);

    for_each(all(result), [](auto v) { print << v << " ";});
    cout("\n");
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int nt;
    cin >> nt;
    while(nt--) {
        reset;
        solve();
    } 
    
	return 0;
}
