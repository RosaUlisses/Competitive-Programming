#include <bits/stdc++.h>

#define endl ('\n')
#define print(x) cout << x << endl

#define midp(x, y) ((x + y) / 2)
#define has(x, y) (x.find(y) != x.end())
#define all(x) (x.begin(), x.end())

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ii = pair<int, int>;
using ivec = vector<int>;
using str = string;

constexpr int inf = 2e9 + 1;
constexpr int mod = 1e9 + 7;
constexpr ll maxnum = 3e5 + 100;

int vabs(int v) {
    if(v < 0) {
        return v * -1;
    } 
    
    return v;
}

int to_int(char c) {
    return c - '0';
}

void solve() {
    str string;
    cin >> string;
    
    int acc = 0;
    int curr = 1;
    
    for (int i = 0; i < string.size(); ++i) {
        if(string[i] == '0' && curr != 0) {
            acc += (10 - curr); 
        }
        
        else if(curr == 0 && string[i] != '0') {
            acc += (10 - to_int(string[i])); 
        }
        
        else {
            acc += vabs(to_int(string[i]) - curr);
        }
        
        acc++;
        curr = to_int(string[i]);
    }

    print(acc);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int nt;
    cin >> nt;

    while (nt--) {
        solve();
    }

    return 0;
}
