#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int is_sorted_decreascing_until(vector<int>& array) {
    for (int i = array.size() - 1; i > 0 ; --i) {
        if (array[i] > array[i - 1]) return i - 1;
    }
    
    return -1;
}

int is_sorted_creasceasing_until(vector<int>& array, int begin) {
    for (int i = begin; i > 0 ; --i) {
        if (array[i] < array[i - 1]) return i - 1;
    }

    return -1;   
}

int shortest_prefix_of_elements_to_remove2(vector<int>& array) {
    int decreascing_index = is_sorted_decreascing_until(array);
    int creascising_index = is_sorted_creasceasing_until(array, decreascing_index);
    
    return creascising_index + 1;
}

int main() {
    int number_of_inputs;
    cin >> number_of_inputs;
    vector<int> outputs(number_of_inputs);
    
    for (int i = 0; i < number_of_inputs; ++i) {
        int size; 
        cin >> size;
        vector<int> array(size);
        for (int j = 0; j < size; ++j) {
            cin >> array[j]; 
        }
        outputs[i] = shortest_prefix_of_elements_to_remove2(array);
    }
    
    std::for_each(outputs.begin(), outputs.end(), [](auto v) { cout << v << "\n"; });
    
	return 0;
}
