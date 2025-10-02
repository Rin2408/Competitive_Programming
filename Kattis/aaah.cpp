#include <iostream>
#include <string>

int main(void){
    std::string Jon, Doctor;
    std::cin >> Jon >> Doctor;
    if(Jon.size()>=Doctor.size()) std::cout << "go";
    else std::cout << "no";
}