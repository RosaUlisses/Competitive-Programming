#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


struct element {
    int value;
    bool is_red;
    
    element() {
        value = 0;
        is_red = true;
    }
    
    element(int value) {
        this->value = value; 
    }
};

void perform_operation(vector<element>& array, int index, int operation_number) {
    
    if (array[index].is_red) {
        array[index].value += operation_number;
        array[index].is_red = false;
    } 
    else {
        array[index].value -= operation_number;
        array[index].is_red = true;
    }
}

int get_minimum_value_after_operations(vector<element> array, int number_of_operations) {
    std::sort(array.begin(), array.end(),
              [] (element const& a, element const& b) { return a.value < b.value; });
    
    if (number_of_operations <= array.size()) {
        int first_index = number_of_operations - 1;
        int current_operation = 1;
        for (int i = first_index; i >= 0; --i) {
            perform_operation(array, i, current_operation);
            current_operation++;
        }

        return std::min_element(array.begin(), array.end(),
                  [] (element const& a, element const& b) { return a.value < b.value; })->value;
    } 
    
    int bigger_value_index = array.size() - 1;
    int current_operation = 1;  
    for (int i = 0; i < (number_of_operations  - array.size() + 1); ++i) {
        perform_operation(array, bigger_value_index, current_operation);
        current_operation++;
    }

    std::sort(array.begin(), array.end(),
              [] (element const& a, element const& b) { return a.value < b.value; });
    for (int i = array.size() - 2; i >= 0 ; --i) {
        perform_operation(array, i, current_operation);
        current_operation++;
    }

    return std::min_element(array.begin(), array.end(),
                            [] (element const& a, element const& b) { return a.value < b.value; })->value;
}


int main() {
    int array_size, number_of_queries;
    cin >> array_size >> number_of_queries;
    vector<element> elements;
    vector<int> outputs;
    
    for (int i = 0; i < array_size; ++i) {
        int value;
        cin >> value;
        elements.push_back(value);    
    }
    
    for (int i = 0; i < number_of_queries; ++i) {
        int number_of_operations;
        cin >> number_of_operations;
        outputs.push_back(get_minimum_value_after_operations(elements, number_of_operations)); 
    }

        outputs.push_back(get_minimum_value_after_operations(elements, 9)); 
    
    for (int value : outputs) {
        cout << value << " ";
    }
    
	return 0;
}
