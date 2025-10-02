#include <iostream>
#include <cmath>

int main(void){
  int H, M;
  std::cin >> H >> M;
  if(M - 45 < 0) H--;
  H =( H + 24) % 24;
  M =( M - 45 + 60) % 60;
  std::cout << H << ' ' << M;
}