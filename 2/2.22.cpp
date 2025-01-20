#include "../shared/display.hpp"
#include "../shared/random.hpp"

int main() {
  Random r(3, 5);
  const unsigned int height = r.get_number() + 3;
  unsigned int width = 5;
  unsigned int margin = width + (2 * height);
  for (int i = 0; i < height; i++){
    Display::pyramid('#',  width, false, true, margin);
    width += 2;
    margin--;
  }
  return 0;
}