#include <iostream>
#include <vector>

using namespace std;

int mod(int n) {
    return n < 0 ? n * -1 : n;
}

int main() {
    int n;
    cin >> n;
    
    vector<int> array(n);
    for (int i = 0; i < n; ++i) {
        cin >> array[i]; 
    }
    
    int min = mod(array[0]);

    for (int i = 1; i < array.size(); ++i) {
        int value = mod(array[i]);
        if (value < min) {
            min = value;
        } 
    }
    
    cout << min; 
    
	return 0;
}
