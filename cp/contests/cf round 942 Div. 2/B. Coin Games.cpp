#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
  #include "/home/ullas/Programming/Competitive-Programming/cp/debug.h"
#endif

#ifdef ONLINE_JUDGE
  #define dbg(...) 
#endif

#define endl ('\n')
auto print_values = [](auto&&... args) {
    bool first = true;
    ((std::cout << (first ? "" : " ") << args, first = false), ...); std::cout << endl;
};
#define print(...) print_values(__VA_ARGS__);  

#define fin(x, y) for(auto& x : y)
#define rep(i, s, n) for(auto i = s; i < n; ++i)
#define reprv(i, s, n) for(auto i = s; i >= n; --i)
#define midp(x, y) ((x + y) / 2)
#define has(x, y) (x.find(y) != x.end())
#define addm(x, y) if(!has(x, y)) { x[y] = 1; } else { x[y]++; }
#define all(x) x.begin(), x.end()
#define sz(x) (x.size())
#define minel(x) *min_element(all(x))
#define maxel(x) *max_element(all(x))
#define f first
#define s second
#define int long long


using namespace std;

using ll = long long;
using ull = unsigned long long;
using ii = pair<int, int>;
using ivec = vector<int>;
using imat = vector<vector<int>>;
using str = string;

constexpr int msize = 0;
constexpr int inf = 0x3f3f3f3f;
constexpr int mod = 1e9 + 7;
constexpr ll maxnum = 0x3f3f3f3f3f3f3f3fLL;

int uba(str& s) {
  int mx = -inf;
  int ix = 0;
  for(int i = 0; i < sz(s); i++) {
    if(s[i] == 'U') {
      int c = 0;
      if(i == 0) {
        if(s[i + 1] == 'U') c++;
        if(s[sz(s) - 1] == 'U') c++;
      }
      else if(i == sz(s) - 1) {
        if(s[0] == 'U') c++;
        if(s[i - 1] == 'U') c++;
      }
      else {
        if(s[i + 1] == 'U') c++;
        if(s[i - 1] == 'U') c++;
      }
      if(c > mx) {
        ix = i;
        mx = c;
      }
    }
  }

  return ix;
}

bool hu(str& s) {
  fin(v, s) {
    if(v == 'U') return true;
  }

  return false;
}

char fp(char c) {
  if(c == 'U') return 'D';
  return 'U';
}

void flip(str& s, int ix) {
  if(ix == 0) {
    s[ix + 1] = fp(s[ix + 1]);
    s[sz(s) - 1] = fp(s[sz(s) - 1]);
    return;
  }
  if(ix == sz(s) - 1) {
    s[0] = fp(s[0]);
    s[ix - 1] = fp(s[ix - 1]);
    return;
  }

  s[ix + 1] = fp(s[ix + 1]);
  s[ix - 1] = fp(s[ix - 1]);
}

void solve() {
  int n;
  cin >> n;
  str s;
  cin >> s;

  bool at = true;
  for(int i = 0; i < n; i++) {
    if(!hu(s) or sz(s) == 0) {
      if(at) {
        print("NO");
      } 
      else print("YES");
      return;
    }


    int ix = uba(s);
    if(sz(s) == 2) {
      s.erase(ix, 1);
      dbg(at);
      dbg(s);
      at = !at;
      continue;
    }

    if(sz(s) == 1) {
      if(s[0] == 'U') {
        dbg(at);
        break;
      }
      else {
        break;
      } 
    }

    dbg(s);
    flip(s, ix);
    s.erase(ix, 1);
    dbg(at);
    dbg(ix, s);

    at = !at;
  }
  

  if(at) {
    print("YES");
  }
  else {
    print("NO");
  }
}

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);

  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
  #endif

  int nt;
  cin >> nt;

  while(nt--) {
    solve();
  }

  return 0;
}
