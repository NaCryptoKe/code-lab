#include <iostream> // For input/output operations
#include <stdexcept> // For std::out_of_range exception

class DynamicArray {
private:
    int* data;        // Pointer to the dynamically allocated array
    int currentSize;  // Current number of elements in the array
    int capacity;     // Maximum number of elements the array can hold before resizing

    // Helper function to resize the array when capacity is reached
    void resize(int newCapacity) {
        if (newCapacity <= currentSize) {
            // New capacity must be greater than current size unless shrinking to current size
            // We'll allow shrinking to currentSize, but generally, resize should expand.
            // For simplicity, we'll only allow expansion or shrinking to exactly currentSize for now.
            if (newCapacity < currentSize) {
                 throw std::invalid_argument("New capacity cannot be less than current size for this simple resize implementation.");
            }
        }
        if (newCapacity == capacity) { // No need to resize if capacity is the same
            return;
        }

        int* newData = new int[newCapacity]; // Allocate new memory

        // Copy existing elements to the new array
        int elementsToCopy = (currentSize < newCapacity) ? currentSize : newCapacity;
        for (int i = 0; i < elementsToCopy; ++i) {
            newData[i] = data[i];
        }

        delete[] data; // Free old memory
        data = newData; // Point to the new memory
        capacity = newCapacity; // Update capacity
        if (currentSize > capacity) { // If capacity shrunk, adjust currentSize
            currentSize = capacity;
        }
    }

public:
    // Constructor: Initializes an empty dynamic array with a default capacity
    DynamicArray(int initialCapacity = 4) : currentSize(0) {
        if (initialCapacity <= 0) {
            initialCapacity = 1; // Ensure a positive initial capacity
        }
        capacity = initialCapacity;
        data = new int[capacity];
        std::cout << "DynamicArray created with initial capacity: " << capacity << std::endl;
    }

    // Destructor: Frees the dynamically allocated memory
    ~DynamicArray() {
        delete[] data;
        data = nullptr; // Good practice to set pointer to nullptr after deallocation
        std::cout << "DynamicArray destroyed." << std::endl;
    }

    // Add an element to the end of the array
    void push_back(int value) {
        if (currentSize == capacity) {
            // If capacity is full, double it
            resize(capacity * 2);
            std::cout << "Resized to new capacity: " << capacity << std::endl;
        }
        data[currentSize] = value;
        currentSize++;
    }

    // Remove the last element from the array
    void pop_back() {
        if (currentSize == 0) {
            throw std::out_of_range("Cannot pop_back from an empty array.");
        }
        currentSize--;
        // Optional: Shrink if currentSize is much smaller than capacity (e.g., 1/4 full)
        if (currentSize > 0 && currentSize == capacity / 4) {
            resize(capacity / 2);
            std::cout << "Shrunk to new capacity: " << capacity << std::endl;
        }
    }

    // Access element by index (read/write)
    int& operator[](int index) {
        if (index < 0 || index >= currentSize) {
            throw std::out_of_range("Index out of bounds.");
        }
        return data[index];
    }

    // Access element by index (read-only)
    const int& operator[](int index) const {
        if (index < 0 || index >= currentSize) {
            throw std::out_of_range("Index out of bounds.");
        }
        return data[index];
    }

    // Get the current number of elements
    int size() const {
        return currentSize;
    }

    // Get the current allocated capacity
    int getCapacity() const {
        return capacity;
    }

    // Check if the array is empty
    bool empty() const {
        return currentSize == 0;
    }

    // Clear all elements (resets size to 0, keeps capacity)
    void clear() {
        currentSize = 0;
        // Optionally, you could resize to initial capacity here if desired:
        // if (capacity > 4) resize(4);
    }

    // Print all elements
    void print() const {
        if (currentSize == 0) {
            std::cout << "Array is empty." << std::endl;
            return;
        }
        std::cout << "Elements: [";
        for (int i = 0; i < currentSize; ++i) {
            std::cout << data[i] << (i == currentSize - 1 ? "" : ", ");
        }
        std::cout << "]" << std::endl;
    }
};

int main() {
    // Create a dynamic array with default initial capacity
    DynamicArray arr;
    arr.print();
    std::cout << "Size: " << arr.size() << ", Capacity: " << arr.getCapacity() << std::endl;

    // Add elements
    arr.push_back(10);
    arr.push_back(20);
    arr.push_back(30);
    arr.push_back(40); // This should trigger a resize
    arr.push_back(50);
    arr.push_back(60);
    arr.print();
    std::cout << "Size: " << arr.size() << ", Capacity: " << arr.getCapacity() << std::endl;

    // Access elements
    std::cout << "Element at index 2: " << arr[2] << std::endl;
    arr[2] = 35; // Modify element
    std::cout << "Modified element at index 2: " << arr[2] << std::endl;
    arr.print();

    // Pop elements
    try {
        arr.pop_back(); // Pop 60
        arr.pop_back(); // Pop 50
        arr.pop_back(); // Pop 40
        arr.pop_back(); // Pop 35 (should trigger shrink)
        arr.print();
        std::cout << "Size: " << arr.size() << ", Capacity: " << arr.getCapacity() << std::endl;
        arr.pop_back(); // Pop 20
        arr.pop_back(); // Pop 10 (should trigger shrink to initial capacity)
        arr.print();
        std::cout << "Size: " << arr.size() << ", Capacity: " << arr.getCapacity() << std::endl;
        arr.pop_back(); // Should throw exception
    } catch (const std::out_of_range& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    // Clear the array
    arr.push_back(100);
    arr.push_back(200);
    std::cout << "Before clear:" << std::endl;
    arr.print();
    std::cout << "Size: " << arr.size() << ", Capacity: " << arr.getCapacity() << std::endl;
    arr.clear();
    std::cout << "After clear:" << std::endl;
    arr.print();
    std::cout << "Size: " << arr.size() << ", Capacity: " << arr.getCapacity() << std::endl;

    // Test with a specific initial capacity
    DynamicArray customArr(2);
    customArr.push_back(1);
    customArr.push_back(2);
    customArr.push_back(3); // Should resize
    customArr.print();
    std::cout << "Size: " << customArr.size() << ", Capacity: " << customArr.getCapacity() << std::endl;

    return 0;
}