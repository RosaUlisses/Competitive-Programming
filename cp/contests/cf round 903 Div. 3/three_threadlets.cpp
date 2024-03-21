#include <bits/stdc++.h>
#define RED ("\033[31m")
#define WHITE ("\033[0m")
#define reset() cout << WHITE
#define print(x) cout << RED << x
#define cout(x) cout << x
#define endl ('\n')
#define pb push_back
#define add insert
#define has(x, y) (x.find(y) != x.end())
#define all(x) x.begin(), x.end()

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ii = pair<int,int>;

constexpr int inf = 2e9+1;
constexpr int mod = 1e9+7;
constexpr ll maxnum = 3e5+100;

template<typename X, typename Y> bool ckmin(X& x, const Y& y) { return (y < x) ? (x=y,1):0; }
template<typename X, typename Y> bool ckmax(X& x, const Y& y) { return (x < y) ? (x=y,1):0; }

void solve() {
    vector<int> nums(3);
    for (int i = 0; i < 3; ++i) {
        cin >> nums[i];
    }
    
    int min = *min_element(all(nums)); 
    vector<int> bigger;
    for (int i = 0; i < 3; ++i) {
        if (nums[i] > min) bigger.push_back(nums[i]); 
    }


    int ops = 3;

    for (int j = 0; j < 3; ++j) {
        for (int i = 0; i < bigger.size(); ++i) {
            if (bigger[i] != min) {
                bigger[i] -= min;
                ops--;
                if (bigger[i] < min) {
                    cout("NO\n");
                    return;
                }
            }
        }       
    }
    
    if (ops >= 0) {
        for (int i = 0; i < bigger.size(); ++i) {
            if (bigger[i] != min) {
                cout("NO\n");
                return;
            } 
        }
        cout("YES\n");
    }
    else cout("NO\n");
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int nt;
	cin >> nt;

	while(nt--) {
//		reset();
		solve();
	}

	return 0;
}
