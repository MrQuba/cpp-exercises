#pragma once
#include <type_traits>
template<typename  T, typename  R> requires std::is_arithmetic_v<T> && std::is_floating_point_v<R>
class Functions{
    public:
    static constexpr R linear(const T a, const T x, const T b){
        return static_cast<R>((a*x) + b);
    }
};