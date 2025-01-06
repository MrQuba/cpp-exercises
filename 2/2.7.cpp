#include "../shared/random.hpp"
#include <algorithm>
#include <array>
#include <iostream>
/*
// First approach:
template <size_t s>
void replace_if_bigger(std::array<int,s>&  arr, const int n){
        int ai{};
            for(int e : arr){
            if(n > e){
                arr[ai] = n;
                break;
            }
            ai++;
        }
}
*/

template <typename T> void replace_if_bigger(std::span<T> &&arr, const T n) {
  *(std::find_if(arr.begin(), arr.end(), [n](int e) { return n > e; })) = n;
  // auto it = std::find_if(arr.begin(), arr.end(), [=](int e){return n > e;});
  // *it = n;
}
int main() {
  std::array<int, 3> biggest{};
  Random r(0, 1000);
  for (int i{}; i < 20; i++) {
    int n = r.get_number();
    replace_if_bigger<int>(std::span(biggest), n);
  }
  for (int b : biggest)
    std::cout << b << "\n";
}