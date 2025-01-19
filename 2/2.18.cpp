#include "../shared/display.hpp"
#include "../shared/random.hpp"

int main(){
    Random r(5, 12);
    const unsigned int a = r.get_number();
    Display::hollow_square('#', ' ', a);
    return 0;
}