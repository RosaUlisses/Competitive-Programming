#include <bits/stdc++.h>

// Problem: $(PROBLEM)
#define endl ('\n')
#define print(x) cout << x << endl
#define print_s(x) cout << x << ' '

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

constexpr int inf = 3e5 + 100;
constexpr int mod = 1e9 + 7;
constexpr ll maxnum = 2e9 + 1;

bool isPerfectSquare(long long n){
    double guess = sqrt(n);
    long long r = std::floor(guess);
    if(r*r == n) return true;
    else {
        r = std::ceil(guess);
        return r*r == n;
    }
}

void solve() {
  int n; 
  cin >> n;
  ll sum = 0;

  for(int i = 0; i < n; i++) {
    ll val;
    cin >> val;
    sum += val;
  }

  if(isPerfectSquare(sum)) {
    print("YES");
  }
  else print("NO");  
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
