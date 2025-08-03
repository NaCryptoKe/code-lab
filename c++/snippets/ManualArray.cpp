#include <iostream>

class ManualArray {
private:
    int* data;
    int size;

public:
    ManualArray(int size) {
        this->size = size;
        data = new int[size];
    }

    ~ManualArray() {
        delete[] data;
        data = nullptr;
    }

    void set(int index, int value) {
        if (index < 0 || index >= size) {
            std::cout << "Index out of bounds!\n";
            return;
        }
        data[index] = value;
    }

    int get(int index) const {
        if (index < 0 || index >= size) {
            std::cout << "Index out of bounds!\n";
            return -1;
        }
        return data[index];
    }

    void print() const {
        for (int i = 0; i < size; ++i) {
            std::cout << data[i] << " ";
        }
        std::cout << "\n";
    }
};


int main() {
    ManualArray arr(5);
    arr.set(0, 10);
    arr.set(1, 20);
    arr.set(2, 30);
    arr.set(3, 40);
    arr.set(4, 50);
    arr.print(); // 10 20 30 40 50

    std::cout << "Value at index 3: " << arr.get(3) << "\n";

    return 0;
}
