#include <algorithm>
#include <ostream>
#include <vector>
#include <utility>
#include "concepts.hpp"
#include "random.hpp"

// overloading << operator for std::vector<T> for convenience
template<Arithmetic T>
std::ostream& operator<<(std::ostream& os, std::vector<T> v)  {
	os << "{ ";
	typename std::vector<T>::iterator it;
	for(it = v.begin(); it <= v.end(); it++) {
		if(it+1 == v.end()) {
		     os << *it << " ";
			 break;
		}
		os << *it << ", ";
	}   
	os << "} \n";
	return os;
}

template<Arithmetic T>
class VectorUtils{
    public:

// O(n) algorithm for finding biggest number, where n is amount of elements in vector
static std::pair<typename std::vector<T>::iterator, T> find_biggest_number_in_vector(std::vector<T>* numbers) {
	typename std::vector<T>::iterator it;
	typename std::vector<T>::iterator biggest = numbers->begin();
	for(it = numbers->begin(); it <= numbers->end(); it++) {
		if(*it > *biggest) biggest = it;
	}
	return std::make_pair(biggest, *biggest);
}
// O(n) algorithm for summing every vector element, where n is amount of elements in vector
static T sum_vector_elements(std::vector<T> n) {
	T sum = 0;
	for(auto a : n) {
		sum += a;
	}
	return sum;
}
static std::vector<int> generate_random_vector(const unsigned int size, const int min, const int max){
	std::vector<int> v(size);
	Random rnd(min, max);
	auto rnd_gen = [&](){
		return rnd.get_number();
	};
	std::generate(v.begin(), v.end(), rnd_gen);
	return v;
}
static void add_vector_at_the_end_of_other(std::vector<T>* adding_to, std::vector<T>* adding_from){
    for(auto it = adding_from->begin() = adding_from->begin(); it < adding_from->end(); it++){
        adding_to->push_back(*it);
    }
}
};