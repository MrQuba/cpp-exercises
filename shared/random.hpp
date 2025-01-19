#include <random>
#include <type_traits>
#pragma once
class Random{
    public:
        Random(int begin, int end) : dist(begin, end) { }
        ~Random() = default;
        int get_number(){
        std::mt19937 mt{rnd_device()};
        return dist(mt);
        }
        template<typename C> requires std::is_invocable_v<C, int>
        int draw_until(C condition){
        std::mt19937 mt{rnd_device()};
        int n{};
        do{
            n = dist(mt);
        }
        while(!condition(n));
        return n;
        }
        void change_range(int begin, int end) { dist = std::uniform_int_distribution<int>(begin, end);}
    private:
        std::random_device rnd_device;
        std::uniform_int_distribution<int> dist;
};
namespace rng {
inline double randd(const int begin = 0, const int end = 1, const unsigned int precision = 0){
    const int d = std::pow(10, precision);
    double r = rand() % (end * d -  begin * d + 1) + begin * d;
    return r / (double)d;
}
};