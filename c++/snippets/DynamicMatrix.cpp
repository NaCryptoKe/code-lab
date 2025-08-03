#include <iostream>

// A matrix is basically a row of arrays.
class DynamicMatrix {
private:
    int columns;
    int rows;
    int** data;

public:
    DynamicMatrix(int rows, int columns) {
        this->rows = rows;
        this->columns = columns;

        data = new int*[rows];
        for (int i = 0; i < rows; ++i) {
            data[i] = new int[columns];
        }
    }

    ~DynamicMatrix() {
        for (int i = 0; i < rows; ++i) {
            delete[] data[i];
        }
        delete[] data;
    }


    void set(int row, int col, int value) {
        if (row < 0 || row >= rows || col < 0 || col >= columns) {
            std::cout << "Index out of bounds!\n";
            return;
        }
        data[row][col] = value;
    }

    int get(int row, int col) const {
        if (row < 0 || row >= rows || col < 0 || col >= columns) {
            std::cout << "Index out of bounds!\n";
            return -1;
        }
        return data[row][col];
    }

    void print() const {
        for (int i = 0; i < rows; ++i) {
            std::cout << "Row " << i+1;
            for (int j = 0; j < columns; ++j) {
                std::cout << data[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }
};