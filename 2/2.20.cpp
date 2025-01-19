#include "../shared/display.hpp"
#include "../shared/random.hpp"

int main(){
    Random r(7, 21);
    const unsigned int a = r.draw_until([](const int a){return a % 2 != 0;});
    Display::pyramid('#',  a);
    Display::line('=', 2*a);
    Display::diamond('#',  a);
    return 0;
}