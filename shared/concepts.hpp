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