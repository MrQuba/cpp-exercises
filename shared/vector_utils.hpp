#include <ostream>
#include <vector>
#include <utility>
#include "concepts.hpp"

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
};