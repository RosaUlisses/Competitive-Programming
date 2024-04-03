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

  char ss;
  cin >> ss;

  vector<pair<int,char>> tc;
  map<char, vector<pair<int, char>>> cs;


  for(int i = 0; i < n * 2; i++) {
    str s;
    cin >> s;

    int val = (s[0] - '0');

    if(s[1] == ss) {
      tc.push_back({val, s[1]});  
      continue;
    }

    if(!has(cs, s[1])) {
      cs.insert({s[1], {{val, s[1]}}});
    }
    else cs[s[1]].push_back({val, s[1]});
  }



  sort(all(tc));
  int ix = 0;
  vector<pair<pair<int, char>, pair<int, char>>> ans;

  fin(p, cs) {
    sort(all(p.s));
    for(int i = 0; i < sz(p.s); i+=2) {
      if(i + 1 == sz(p.s)) {
        if(ix >= sz(tc)) {
          print("IMPOSSIBLE");
          return;
        }
        ans.push_back({p.s[i], tc[ix]});

        ix++;
      }

      else ans.push_back({p.s[i], p.s[i + 1]});
    }
  }


  if((sz(tc) - ix) % 2 == 0) {
    for(int i = ix; i < sz(tc); i+=2) {
      ans.push_back({tc[i], tc[i+1]});
    }
  }

  else {
    print("IMPOSSIBLE");
    return;
  }


  fin(v, ans) {
    cout << v.f.f << v.f.s << " " << v.s.f << v.s.s << "\n";
  }
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
