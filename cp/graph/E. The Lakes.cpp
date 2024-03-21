#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "/home/ullas/Programming/Competitive-Programming/cp/debug.h"
#endif

#define endl ('\n')
#define print(x) cout << x << endl
#define print_s(x) cout << x << ' '

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

int n, m;
vector<ii> adjc(ii c, imat& g) {
  if(g[c.f][c.s] == 0) return {};
  vector<ii> p = {{c.f + 1, c.s}, {c.f - 1, c.s}, {c.f, c.s + 1}, {c.f, c.s - 1}};
  vector<ii> r;
  fin(v, p) {
    if(!(v.f < 0 || v.s < 0 || v.f >= n || v.s >= m) && g[v.f][v.s] != 0) {
      r.push_back(v);
    }
  }
  return r;
}

int dfs(set<ii>& vst, ii c, imat& g) {
  if(has(vst, c)) return 0;

  vst.insert(c);

  int s = g[c.f][c.s];
  auto adj = adjc(c, g);
  fin(a, adj) {
    if(g[a.f][a.s] == 0) continue;
    s += dfs(vst, a, g);
  }

  return s;
}

int mx(imat& g) {
  set<ii> vst;

  int ans = 0;
  fint(i, 0, n) {
    fint(j, 0, m) {
      ii p = {i, j};
      if(!has(vst, p)) {
        ans = max({dfs(vst, p, g), ans});
      }
    }
  }

  return ans;
}

void solve() {
  cin >> n >> m;
  imat g(n, vector<int>(m, 0));      

  fin(r, g) {
    fin(v, r) cin >> v;
  }

  print(mx(g));
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
