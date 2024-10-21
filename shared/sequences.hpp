#include "concepts.hpp"
#include "vector_utils.hpp"
#include <cstdlib>
#include <iterator>
#include <vector>
class Sequence {
public:
  Sequence() {}
  template <Invocable_Sequence F>
  void displayNElementsOfSequence(const std::vector<int> &sequence,
                                  const unsigned int n, F sequence_pattern) {
    unsigned int i = 0;
    while (i < n) {
      sequence_pattern(sequence, &i, n);
      i++;
    }
  }
  template <typename... Args>
  static bool is_there_n_element_sequence_in_range(
      std::invocable<const std::vector<int>::iterator,
                     const std::vector<int>::iterator> auto &&sequence_pattern,
      const std::vector<int>::iterator begin,
      const std::vector<int>::iterator end) {
    if (sequence_pattern(begin, end))
      return true;
    else
      return false;
  }
  static std::vector<std::vector<int>> find_all_n_element_subsequences(
      std::vector<int> *s, const unsigned int length_of_subsequence,
      std::invocable<const std::vector<int>::iterator,
                     const std::vector<int>::iterator> auto
          &&sequence_pattern) {
    std::vector<int>::iterator it = s->begin();
    std::vector<std::vector<int>> subsequences;
    while (it + (length_of_subsequence - 1) < s->end()) {
      if (Sequence::is_there_n_element_sequence_in_range(
              sequence_pattern, it, it + (length_of_subsequence - 1))) {
        subsequences.push_back(VectorUtils<int>::createVectorOutOfRange(
            length_of_subsequence, it));
      }
      it++;
    }
    return subsequences;
  }
  static std::vector<int>
  find_longest_sequence(std::vector<int> *s,
                        std::invocable<const std::vector<int>::iterator,
                                       const std::vector<int>::iterator> auto
                            &&sequence_pattern) {
    size_t max_length_of_subsequence = 0;
    auto start = s->begin();
    auto end = s->begin();
    auto longest_start = s->end();
    while (end != s->end()) {
      if (sequence_pattern(start, end + 1)) {
        end++;
      } else {
        start = end;
        end++;
      }
      size_t current_length = std::distance(start, end);
      if (current_length > max_length_of_subsequence) {
        max_length_of_subsequence = current_length;
        longest_start = start;
      }
    }
    return VectorUtils<int>::createVectorOutOfRange(max_length_of_subsequence,
                                                    longest_start);
  }
  ~Sequence() {}

private:
};