#include "../shared/display.hpp"
#include "../shared/random.hpp"

int main(){
    Random r(5, 12);
    const unsigned int a = r.get_number();
    Display::sq_chars('#', a, a);
    return 0;
}