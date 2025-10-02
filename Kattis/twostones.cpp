#include <iostream>
#include <cmath>

int main(void){
    int x;
    std::cin >> x;
    std::cout << (x % 2 ? "Alice" : "Bob");
}