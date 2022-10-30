#include <iostream>
#include "random.h"

int main() {
    std::cout << "A boost random number: " << math::random(1, 0.3) << std::endl;
    return 0;
}