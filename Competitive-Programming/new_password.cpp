#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    
   vector<char> characters; 
    char a = 'a';
    for (int i = 0; i < k; ++i) {
        characters.push_back(a + i); 
    }

    string new_password = "";
    for (int i = 0; i < n; ++i) {
        new_password += characters[i % characters.size()];
    }
    
    cout << new_password;
    
	return 0;
}
