#include <bits/stdc++.h>

#ifdef ONLINE_JUDGE
  #define dbg(...) 
#endif

#define endl ('\n')
auto print_values = [](auto&&... args) {
    bool first = true;
    ((std::cout << (first ? "" : ", ") << args, first = false), ...); std::cout << endl;
};
#define print(...) print_values(__VA_ARGS__);  

#define fin(x, y) for(auto& x : y)
#define fint(i, s, n) for(int i = s; i < n; i++)
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


void solve() {
  int n; 
  cin >> n;

  ivec l(n);
  fin(v, l) cin >> v;

  int ans = -1;
  for(int nl = 0; nl <= n; nl++) {
    int snl = 0;

    fin(v, l) {
      if(v > nl) {
        snl++;
      }
    }

    if(nl == snl) {
      ans = nl;
    }
  }

  print(ans);
}

int main() {
  cin.tie(0)->sync_with_stdio(0);

  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
  #endif

  int nt;
  cin >> nt;

  while (nt--) {
      solve();
  }

  return 0;
}
