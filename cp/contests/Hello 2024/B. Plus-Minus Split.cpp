#include <bits/stdc++.h>

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


void solve() {
  int n;
  cin >> n;
  str ss;      
  cin >> ss;


  for(int i = 0; i < n; i++) {
    if(ss[i] == '+') {
      int pc = 1; 
      for(int j = i + 1; j < n; j++) {
        pc++;
        if(j + 1 < n) {
          if(ss[j + 1] == '-') break;
        }
      }

      int nc = 0;
      int nix; 
      for(int j = i + pc; j < n; j++) {
        if(j + 1 < n) {
          if(ss[j + 1] == '+') break;
        }
        nc++;
        nix = j;
      }

      int tor = pc < nc ? pc : nc;

      for(int j = i; j < i + tor; j++) {
        if(j < n) {
          ss[j] = '*';
        }
      }
       
      for(int j = nix; j < nix + tor; j++) {
        if(j < n) {
          ss[j] = '*';
        }
      }
    }

    else {
      int pc = 1; 
      for(int j = i + 1; j < n; j++) {
        if(j + 1 < n) {
          if(ss[j + 1] == '+') break;
        }
      }
      pc++;

      int nc = 0;
      int nix; 
      for(int j = i + pc; j < n; j++) {
        if(j + 1 < n) {
          if(ss[j + 1] == '-') break;
        }
        nc++;
        nix = j;
      }

      int tor = pc < nc ? pc : nc;

      for(int j = i; j < i + tor; j++) {
        if(j < n) {
          ss[j] = '*';
        }
      }
       
      for(int j = nix; j < nix + tor; j++) {
        if(j < n) {
          ss[j] = '*';
        }
      }
    }
  } 

  int ans = 0;
  fin(v, ss) {
    if(v != '*') {
      ans++;
    }
  }

  print(ans);
}

int main() {
  cin.tie(0)->sync_with_stdio(0);

  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif

  int nt;
  cin >> nt;

  while (nt--) {
      solve();
  }

  return 0;
}
