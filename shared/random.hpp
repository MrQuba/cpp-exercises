#include <random>
#pragma once
class Random{
    public:
        Random(int begin, int end) : dist(begin, end) { }
        ~Random() = default;
        int get_number(){
        std::mt19937 mt{rnd_device()};
        return dist(mt);
        }
    private:
        std::random_device rnd_device;
        std::uniform_int_distribution<int> dist;
};