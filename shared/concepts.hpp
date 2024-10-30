#include <concepts>
#include <iostream>
#include <type_traits> 
#include <functional>
#pragma  once
template<typename T>
concept Arithmetic = std::is_arithmetic_v<T>;

template< class F, class... Args >
concept invocable =
    requires(F&& f, Args&&... args) {
        std::invoke(std::forward<F>(f), std::forward<Args>(args)...);
    };
template<typename F>
concept Invocable_Sequence = std::is_invocable_v<F, const std::vector<int>&, unsigned int*, const unsigned int>;

template<class T>
concept displayable = requires(const T& t){
    {std::cout<< t} -> std::same_as<std::ostream&>;
}; 