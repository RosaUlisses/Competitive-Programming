#include <iostream>
#include <vector>

using namespace std;

int get_min_width(vector<int>& heights, int fence_height) {
    int min_width = 0;
    
    for (int height : heights) {
       min_width += height > fence_height ? 2 : 1;      
    } 
    
    return min_width;
}

int main() {
    int number_of_friends, fence_height;
    cin >> number_of_friends >> fence_height;
    
    vector<int> heights(number_of_friends);

    for (int i = 0; i < number_of_friends; i++) {
        cin >> heights[i]; 
    }
    
    cout << get_min_width(heights, fence_height);
    
	return 0;
}