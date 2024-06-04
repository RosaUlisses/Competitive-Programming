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
#define f first
#define s second
#define pb push_back
#define int long long


using namespace std;

using ll = long long;
using ii = pair<int, int>;
using ivec = vector<int>;
using imat = vector<vector<int>>;
using str = string;

constexpr int msize = 0;
constexpr int inf = 0x3f3f3f3f;
constexpr int mod = 1e9 + 7;
constexpr ll maxnum = 0x3f3f3f3f3f3f3f3fLL;

bool snok(map<char, int>& ic) {
  if(ic['S'] % 2 == 0 and ic['N'] % 2 == 0) {
    return true;
  }

  if(ic['S'] % 2 != 0 and ic['N'] % 2 != 0) {
    return true;
  }

  return false;
}

bool weok(map<char, int>& ic) {
  if(ic['W'] % 2 == 0 and ic['E'] % 2 == 0) {
    return true;
  }

  if(ic['W'] % 2 != 0 and ic['E'] % 2 != 0) {
    return true;
  }

  return false;
}

void solve() {
  int n;  
  cin >> n;

  str is;
  cin >> is;


  map<char, int> ic;
  fin(v, is) {
    addm(ic, v);
  }


  if(n == 2 and sz(ic) == 2) {
    print("NO");
    return;
  }


  if(!snok(ic) or !weok(ic)) {
    print("NO");
    return;
  }

  str out(n, '0');  


  if(ic['S'] == ic['N'] and ic['W'] == ic['E'] and ic['S'] > 0 and ic['N'] > 0 and ic['W'] > 0 and ic['E'] > 0) {
      for(int i = 0; i < n; i++) {
        if(is[i] == 'S' or is[i] == 'N') {
          out[i] = 'R';
        }
      }

      for(int i = 0; i < n; i++) {
        if(is[i] == 'W' or is[i] == 'E') {
          out[i] = 'H';
        }
      }

      print(out);
      return;
  }

  bool rov = true;
  for(int i = 0; i < n; i++) {
    if(is[i] == 'S') {
      if(rov) {
        out[i] = 'R';
      }
      else {
        out[i] = 'H';
      }
      rov = !rov;
    }
  }

  rov = true;
  for(int i = 0; i < n; i++) {
    if(is[i] == 'N') {
      if(rov) {
        out[i] = 'R';
      }
      else {
        out[i] = 'H';
      }
      rov = !rov;
    }
  }

  rov = true;
  for(int i = 0; i < n; i++) {
    if(is[i] == 'W') {
      if(rov) {
        out[i] = 'R';
      }
      else {
        out[i] = 'H';
      }
      rov = !rov;
    }
  }

  rov = true;
  for(int i = 0; i < n; i++) {
    if(is[i] == 'E') {
      if(rov) {
        out[i] = 'R';
      }
      else {
        out[i] = 'H';
      }
      rov = !rov;
    }
  }

  print(out);
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
