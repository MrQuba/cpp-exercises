#include "../shared/random.hpp"
#include "../shared/vector_utils.hpp"
#include <vector>

int main() {
  Random r(1, 100);
  std::vector<int> v, s;
  unsigned int c{};

  r.draw_until([&v, &s, &c](int n) {
    c++;
    int sum;
    if (v.size() == 3) {
      auto it = v.begin();
      it = v.erase(v.begin());
      sum = VectorUtils<int>::sum_vector_elements(v);
    }
    v.push_back(n);
    if (s.empty() or n >= s.back())
      s.push_back(n);
    return (sum >= 80 and sum <= 90) and (v.size() == 3);
  });
  
  std::cout << "Amount of draws: " << c << "\n" << s << "\n";
  return 0;
}