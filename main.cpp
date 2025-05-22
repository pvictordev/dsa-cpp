#include <iostream>
#include "math.h" 
#include "utils.h"

int main() {
    int sum = add(2, 3);
    int product = multiply(2, 3);
    
    std::cout << "Sum: " << sum << std::endl;
    std::cout << "Product: " << product << std::endl;

    printResult(5);
    
    return 0;
}
