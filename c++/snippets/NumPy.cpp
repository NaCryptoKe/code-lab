#include <iostream>  // For std::cout, std::endl
#include <vector>    // For std::vector
#include <initializer_list> // For constructor with initializer list
#include <numeric>   // For std::iota (useful for some array operations)

// Template definition for our generic NumPy-like struct
template <typename T>

struct NumPy {
private: // It's good practice to make internal data private
    std::vector<T> data_; // The std::vector to hold our array elements

public:
    // 1. Constructor that takes an initializer list
    // This allows you to create a NumPy object directly from a list of values:
    // NumPy<int> my_array = {1, 2, 3, 4};
    NumPy(std::initializer_list<T> values) : data_(values) {
        // The initializer list 'values' is used directly to construct 'data_'
    }

    // 2. Constructor for creating an empty or size-specified array (optional, but useful)
    // NumPy<double> zeros(5, 0.0); // Creates an array of 5 doubles, all 0.0
    explicit NumPy(size_t size = 0, T initial_value = T{}) : data_(size, initial_value) {
        // 'explicit' prevents unintended implicit conversions
        // T{} provides a default-constructed value for T (e.g., 0 for int, 0.0 for double)
    }

    // 3. Method to access elements (like a[i] in Python/NumPy)
    // Overloading the [] operator provides convenient element access.
    // The non-const version allows modification: my_array[0] = 10;
    T& operator[](size_t index) {
        // You might add bounds checking here for safety in a real library
        return data_[index];
    }

    // Const version for accessing elements on const NumPy objects: const_array[0];
    const T& operator[](size_t index) const {
        // You might add bounds checking here for safety in a real library
        return data_[index];
    }

    // 4. Method to get the size of the array
    size_t size() const {
        return data_.size();
    }

    // You can start adding more NumPy-like methods here, e.g.:
    // void fill(T value) { /* ... */ }
    // NumPy<T> reshape(size_t new_rows, size_t new_cols) { /* ... */ }
    // etc.
};

// ---

// Global overloaded operator<< for printing NumPy objects to ostream (e.g., std::cout)
// This allows you to do: std::cout << my_num_py_object;
template <typename T>
std::ostream& operator<<(std::ostream& os, const NumPy<T>& np_array) {
    os << "[";
    for (size_t i = 0; i < np_array.size(); ++i) {
        os << np_array[i]; // Use the overloaded [] operator to get elements
        if (i < np_array.size() - 1) {
            os << ", ";
        }
    }
    os << "]";
    return os;
}


int main() {
    // 1. Creating a NumPy<int> object using an initializer list
    NumPy<int> a = {1, 2, 3, 4}; // No need for 'np.array()' anymore!

    // Print the array using the overloaded operator<<
    std::cout << "Integer array 'a': " << a << std::endl;

    // Access and modify elements using the overloaded [] operator
    a[0] = 10;
    std::cout << "Integer array 'a' after modification: " << a << std::endl;

    std::cout << "Size of 'a': " << a.size() << std::endl;
    std::cout << std::endl;

    // 2. Creating a NumPy<double> object
    NumPy<double> b = {1.5, 2.7, 3.9};
    std::cout << "Double array 'b': " << b << std::endl;
    std::cout << std::endl;

    // 3. Creating a NumPy<std::string> object
    NumPy<std::string> c = {"hello", "world", "c++"};
    std::cout << "String array 'c': " << c << std::endl;
    std::cout << std::endl;

    // 4. Creating an empty NumPy object, then potentially resizing or filling
    NumPy<int> empty_array;
    std::cout << "Empty array: " << empty_array << std::endl;
    std::cout << "Size of empty array: " << empty_array.size() << std::endl;

    // 5. Creating a fixed-size array initialized to a default value
    NumPy<float> zeros_float(5, 0.0f); // 5 elements, all 0.0f
    std::cout << "Zeros float array: " << zeros_float << std::endl;

    return 0;
}