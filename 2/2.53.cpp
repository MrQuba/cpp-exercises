#include "2.53_classes.hpp"
#include <cassert>
#include <cctype>
#include <iostream>
#include <optional>
#include <vector>
using namespace expressions;
std::vector<char> tokenize(const std::string &str) {
  return {str.begin(), str.end()};
}
constexpr bool is_operator(const char c) {
  return std::string("+-*/^%").contains(c);
}
template <typename M = MathExpression<char>>
constexpr bool neighbours_good(M m, const std::optional<bool> p,
                               const std::optional<bool> n) {
  return (m.can_previous_be_null) ? (!p.has_value() || p.value() != false)
         : (p.has_value() && p.value() == true) && (m.can_next_be_null)
             ? (!n.has_value() || n.value() != false)
             : (n.has_value() && n.value() == true);
}
using Iterator = std::vector<char>::const_iterator;
constexpr bool is_expression_correct(const std::vector<char> &exp, Iterator p,
                                     Iterator c, Iterator n,
                                     const bool first = true) {
  if (first) {
    c = exp.begin();
    n = c + 1;
    p = c;
  }
  std::optional<bool> bp, bn;
  auto e = math_expressions<char>.find(*c);
  auto e_op = math_expressions<Operator<>>.find(*c);
  if (p != c) {
    if ((std::isalnum(*c) || *c == '(') && is_operator(*p))
      bp = e_op->second->expects_before(*p);
    else
      bp = e->second->expects_before(*p);
  } else
    bp = std::nullopt;
  if (n != exp.end()) {
    if ((std::isalnum(*c) || *c == ')') && is_operator(*n))
      bn = e_op->second->expects_after(*n);
    else
      bn = e->second->expects_after(*n);
  } else
    bn = std::nullopt;
  bool ng = neighbours_good<decltype(*(e->second))>(*(e->second), bp, bn);
  if (c + 1 == exp.end() && ng)
    return true;
  else if (c + 1 != exp.end() && ng)
    return is_expression_correct(exp, (first) ? p : p + 1, c + 1, n + 1, false);
  return false;
}
int main() {

  std::vector<std::string> exs{"(12*x+3*(3*d-a)^3)/11=z",
                               "-(-12^a*b*c/12-(-5-a*b))",
                               "10/0",
                               "---a",
                               "a+b=c=d=",
                               "(a--))=2+3*(4)",
                               "a=",
                               "abc",
                               "a**2",
                               "2a"};
  for (auto s : exs) {
    auto tokens = tokenize(s);
    std::cout << "expression " << s << " is "
              << ((is_expression_correct(tokens, tokens.cbegin(),
                                         tokens.cbegin(), tokens.cbegin()))
                      ? ""
                      : "not ")
              << "correct \n";
  }

  return 0;
}