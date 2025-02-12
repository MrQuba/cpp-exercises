#include <iostream>
#include <vector>
#include <ranges>
#include <memory>
template<typename T>
using vec = std::vector<T>;

template<typename Container> 
concept is_container_v = requires (Container c){{c.begin()} ->  std::same_as<typename Container::iterator>;};

template<typename C> requires is_container_v<C> 
struct interleave_view: public std::ranges::view_interface<interleave_view<C>>{
    interleave_view() = default;
    interleave_view(const C& c, const C& cc) : cptr(std::make_unique<C>(c)), ccptr(std::make_unique<C>(cc)) {
        container.reserve(c.size() + cc.size() + 1);
    }
    auto begin() const { return container.begin(); }
    auto end() const { return container.end(); }
    void operator() (){
        auto cit = cptr->begin();
        auto ccit = ccptr->rbegin();
        bool isc = true;
        while(cit != cptr->end() || ccit != ccptr->rend()){
            container.push_back((isc) ? *cit : *ccit);
            if(isc){
                cit ++;
            } else ccit++;
            isc = !isc;
        }
        if(cit == cptr->end() && ccit != ccptr->rend()) container.insert(container.end(), ccit, ccptr->rend());
        else if(ccit == ccptr->rend() && cit != cptr->end()) container.insert(container.end(), cit, cptr->end());
    }
    private:
    C container;

    std::unique_ptr<C> cptr;  
    std::unique_ptr<C> ccptr;  
    };

int main(){
    constexpr auto i = std::views::iota(0,100);
    const vec<int> v1(i.begin(), i.end());
    const vec<int> v2 = v1;
    auto iv = interleave_view<std::vector<int>>(v1, v2);
    iv();
    vec<int> v(iv.begin(), iv.end());
    for(auto e : v) std::cout << e << " ";
    std::cout << "\n";



    return 0;
}