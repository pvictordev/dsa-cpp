#include <iostream>

int add(int a, int b);
int multiply(int a, int b);
void printResult(int value);  

int main() {
    int sum = add(2, 3);
    int product = multiply(2, 3);
    
    std::cout << "Sum: " << sum << std::endl;
    std::cout << "Product: " << product << std::endl;

    printResult(5);
    
    return 0;
}
