#include <iostream>

int add(int x, int y) { return x + y; }
int subtract(int x, int y) { return x - y; }
int multiply(int x, int y) { return x * y; }
int divide(int x, int y) {
    if (y == 0) {
        std::cout << "Dumbass, why you trying to divide by 0!\n";
        return 0;
    }
    return x / y;
}

int main() {
    bool flag = true;
	int carryThrough = 0;
	bool afterFirst = false;
	bool newRoad = false;

    while (flag) {
        char option;
        int num1, num2;
        int (*operation)(int, int) = nullptr;

        std::cout << "Choose operation (+ - * /), or x to exit: ";
        std::cin >> option;

        switch (option) {
            case '+': operation = add; break;
            case '-': operation = subtract; break;
            case '*': operation = multiply; break;
            case '/': operation = divide; break;
            default:
                flag = false;
                continue;
        }

		if (newRoad) {
        	std::cout << "Enter num2: ";
			std::cin >> num2;
			num1 = carryThrough
		} else {
			std::cout << "Enter num1: ";
			std::cin >> num1;
			std::cout << "Enter num2: ";
			std::cin >> num2;
		}
		
        std::cout << "Result: " << operation(num1, num2) << "\n";

		carryThrough = operation(num1, num2);

		std::cout << "Do you want to use the result as next input. 0 for no, others for yes.";
		int carry;
		std::cin >> carry;

		if (carry && afterFirst) {
			newRoad = true;
		}
		else {
			newRoad = false;
		}
    }

    return 0;
}
