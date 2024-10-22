#include "concepts.hpp"
#include "random.hpp"
#include <algorithm>
#include <ostream>
#include <utility>
#include <vector>
#pragma once
// overloading << operator for std::vector<T> for convenience
template <Arithmetic T>
std::ostream &operator<<(std::ostream &os, std::vector<T> v) {
  os << "{ ";
  typename std::vector<T>::iterator it;
  for (it = v.begin(); it <= v.end(); it++) {
    if (it + 1 == v.end()) {
      os << *it << " ";
      break;
    }
    os << *it << ", ";
  }
  os << "} \n";
  return os;
}
template <Arithmetic T>
std::unordered_map<T, size_t> &operator+=(std::unordered_map<T, size_t>& f1, std::unordered_map<T, size_t> f2) {
    for(auto f : f2){
        f1[f.first]++;
    }
    return f1;
}
template <Arithmetic T> class VectorUtils {
public:
  // O(n) algorithm for finding biggest number, where n is amount of elements in
  // vector
  static std::pair<typename std::vector<T>::iterator, T>
  find_biggest_number_in_vector(std::vector<T> *numbers) {
    typename std::vector<T>::iterator it;
    typename std::vector<T>::iterator biggest = numbers->begin();
    for (it = numbers->begin(); it <= numbers->end(); it++) {
      if (*it > *biggest)
        biggest = it;
    }
    return std::make_pair(biggest, *biggest);
  }
  // O(n) algorithm for summing every vector element, where n is amount of
  // elements in vector
  static T sum_vector_elements(std::vector<T> n) {
    T sum = 0;
    for (auto a : n) {
      sum += a;
    }
    return sum;
  }
  static std::vector<int> generate_random_vector(const unsigned int size,
                                                 const int min, const int max) {
    std::vector<int> v(size);
    Random rnd(min, max);
    auto rnd_gen = [&]() { return rnd.get_number(); };
    std::generate(v.begin(), v.end(), rnd_gen);
    return v;
  }
  static void add_vector_at_the_end_of_other(std::vector<T> *adding_to,
                                             std::vector<T> *adding_from) {
    for (auto it = adding_from->begin() = adding_from->begin();
         it < adding_from->end(); it++) {
      adding_to->push_back(*it);
    }
  }
  static std::vector<T> createVectorOutOfRange(const unsigned int length,
                                               std::vector<T>::iterator it) {
    std::vector<T> v;
    for (int i = 0; i < length; i++) {
      v.push_back(*(it + i));
    }
	return v;
  }
  static std::unordered_map<T, size_t> calculate_frequency(const std::vector<T>* v){
    std::unordered_map<T, size_t> frequency;
    for(auto a : *v){
      frequency[a]++;
    }
    return frequency;
  }
  static std::vector<T> common_part_of_vectors(std::vector<T>* v1,  std::vector<T>* v2){
    std::vector<T> result;
    std::unordered_map<T, size_t> f1 = calculate_frequency(v1);
    f1 += calculate_frequency(v2);
    for(auto f : f1){
      if(f.second > 1) result.push_back(f.first);
    }
    return result;
  }
static std::vector<T> sum_vectors(const std::vector<T>& v1, const std::vector<T>& v2) {
    std::vector<T> result;
    std::unordered_map<T, size_t> f1 = VectorUtils<T>::calculate_frequency(&v1);
    f1 += VectorUtils<T>::calculate_frequency(&v2);
    for (auto f : f1) {
        result.push_back(f.first);
    }
    return result;
}static std::vector<T> difference_of_vectors(const std::vector<T>& v1, const std::vector<T>& v2) {
    std::vector<T> result;
    std::unordered_map<T, size_t> f1 = VectorUtils<T>::calculate_frequency(&v1);
    f1 += VectorUtils<T>::calculate_frequency(&v2);
    for (auto f : f1) {
        if(f.second == 1)
        result.push_back(f.first);
    }
    return result;
}
};
template <Arithmetic T>
std::vector<T> operator+=(std::vector<T>& v1, const std::vector<T>& v2) {
    v1 = VectorUtils<T>::sum_vectors(v1, v2);
    return v1;
}
template <Arithmetic T>
std::vector<T> operator+(const std::vector<T>& v1, const std::vector<T>& v2) {
    return VectorUtils<T>::sum_vectors(v1, v2);
}
template <Arithmetic T>
std::vector<T> operator+(std::vector<T>&& v1, std::vector<T>&& v2) {
    return VectorUtils<T>::sum_vectors(std::move(v1), std::move(v2));
}
template <Arithmetic T>
std::vector<T> operator-(std::vector<T>& v1, std::vector<T>& v2) {
    return VectorUtils<T>::difference_of_vectors(std::move(v1), std::move(v2));
}