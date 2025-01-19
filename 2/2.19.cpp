#include "../shared/display.hpp"
#include "../shared/random.hpp"

int main(){
    Random r(5, 12);
    const unsigned int a = r.get_number();
    Display::rect_triangle('#', a);
    Display::line('=', 2*a);
    Display::rect_triangle('#', a, true);
    return 0;
}