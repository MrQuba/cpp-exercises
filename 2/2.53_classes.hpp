#include <cctype>
#include <memory>
#include <type_traits>
#include <unordered_map>
#pragma once
template <typename T> class MathExpression {
public:
  virtual constexpr bool expects_before(const T c) const = 0;
  virtual constexpr bool expects_after(const T c) const = 0;
  MathExpression(const char c = '\0', const bool pn = false,
                 const bool nn = false)
      : symbol(c), can_previous_be_null(pn), can_next_be_null(nn) {}
  virtual ~MathExpression() = default;
  char symbol;
  bool can_previous_be_null;
  bool can_next_be_null;
};

template <typename T = char> class Operator : public MathExpression<T> {
public:
  Operator(const char c, const bool pn = false)
      : MathExpression<T>(c, pn, false) {}
  virtual constexpr bool expects_before(const T c) const override {
    if constexpr (std::is_convertible_v<T, char>)
      return std::isalnum(c);
    return false;
  }
  virtual constexpr bool expects_after(const T c) const override {
    if constexpr (std::is_convertible_v<T, char>)
      return std::isalnum(c) || c == '(';
    return false;
  }
  virtual ~Operator() = default;
};

template <typename T> class PlusOperator : public Operator<T> {
public:
  PlusOperator() : Operator<T>('+') {}
};

template <typename T> class MinusOperator : public Operator<T> {
public:
  MinusOperator() : Operator<T>('-', true) {}
  virtual constexpr bool expects_before(const T c) const override {
    if constexpr (std::is_convertible_v<T, char>)
      return std::isalnum(c) || c == '(';
    return false;
  }
};

template <typename T> class DivisionOperator : public Operator<T> {
public:
  DivisionOperator() : Operator<T>('/') {}
};

template <typename T> class MultiplicationOperator : public Operator<T> {
public:
  MultiplicationOperator() : Operator<T>('*') {}
};

template <typename T> class PowerOperator : public Operator<T> {
public:
  PowerOperator() : Operator<T>('^') {}
};

template <typename T> class ModuloOperator : public Operator<T> {
public:
  ModuloOperator() : Operator<T>('%') {}
};
template <typename T> class Bracket : public MathExpression<T> {
public:
  Bracket(const char c, const bool pn, const bool nn)
      : MathExpression<T>(c, pn, nn) {}
  virtual constexpr bool expects_before(const T c) const override {
    if constexpr (std::is_convertible_v<T, char>)
      return c == this->symbol || c == '=';
    return std::is_base_of_v<Operator<char>, decltype(c)>;
  }
  virtual constexpr bool expects_after(const T c) const override {
    if constexpr (std::is_convertible_v<T, char>)
      return std::isalnum(c) || c == this->symbol || c == '=';
    return false;
  }
};
template <typename T> class OpeningBracket : public Bracket<T> {
public:
  OpeningBracket() : Bracket<T>('(', true, false) {}
  virtual constexpr bool expects_before(const T c) const override {
    if (Bracket<T>::expects_before(c))
      return true;
    if constexpr (std::is_same_v<MinusOperator<char>, decltype(c)>)
      return true;
    if constexpr (std::is_convertible_v<T, char>)
      return c == '-';
    return false;
  }
  virtual constexpr bool expects_after(const T c) const override {
    if (Bracket<T>::expects_after(c))
      return true;
    if constexpr (std::is_convertible_v<T, char>)
      return (c == '-');
    return false;
  }
};

template <typename T> class ClosingBracket : public Bracket<T> {
public:
  ClosingBracket() : Bracket<T>(')', false, true) {}
  virtual constexpr bool expects_before(const T c) const override {
    return Bracket<T>::expects_after(c);
  }

  virtual constexpr bool expects_after(const T c) const override {
    return Bracket<T>::expects_before(c);
  }
};
template <typename T> class EqualSign : public MathExpression<T> {
public:
  EqualSign() : MathExpression<T>('=', false, false) {}
  virtual constexpr bool expects_before(const T c) const override {
    if constexpr (std::is_convertible_v<T, char>)
      return std::isalnum(c);
    return false;
  }
  virtual constexpr bool expects_after(const T c) const override {
    if constexpr (std::is_convertible_v<T, char>) {
      return std::isalnum(c) || c == '(';
    }
    return false;
  }
};
template <typename T> class Character : public MathExpression<T> {
public:
  Character(const char c) : MathExpression<T>(c, true, true) {}
  virtual constexpr bool expects_before(const T c) const override {
    if constexpr (std::is_base_of_v<Operator<>, decltype(c)>)
      return true;
    if constexpr (std::is_convertible_v<T, char>)
      return c == '(' || c == '=';
    return false;
  }
  virtual constexpr bool expects_after(const T c) const override {
    if constexpr (std::is_base_of_v<Operator<>, decltype(c)>)
      return true;
    if constexpr (std::is_convertible_v<T, char>)
      return c == '=' || c == ')';
    return false;
  }
};
template <typename T> class Number : public Character<T> {
public:
  Number(const char c) : Character<T>(c) {}
  virtual constexpr bool expects_before(const T c) const override {

    if (Character<T>::expects_before(c))
      return true;
    else if constexpr (std::is_convertible_v<T, char>)
      return std::isdigit(c);
    return false;
  }
  virtual constexpr bool expects_after(const T c) const override {
    return Character<T>::expects_after(c) || expects_before(c);
  }
};
namespace expressions {
template <typename T>
const std::unordered_map<char, std::shared_ptr<MathExpression<T>>>
generate_expression_map() {
  std::unordered_map<char, std::shared_ptr<MathExpression<T>>> m = {
      {'+', std::make_shared<PlusOperator<T>>()},
      {'-', std::make_shared<MinusOperator<T>>()},
      {'*', std::make_shared<MultiplicationOperator<T>>()},
      {'/', std::make_shared<DivisionOperator<T>>()},
      {'^', std::make_shared<PowerOperator<T>>()},
      {'%', std::make_shared<ModuloOperator<T>>()},
      {'=', std::make_shared<EqualSign<T>>()},
      {'(', std::make_shared<OpeningBracket<T>>()},
      {')', std::make_shared<ClosingBracket<T>>()}};
  for (int i{}; i < 10; i++)
    m[i + '0'] = std::make_shared<Number<T>>(i + '0');
  for (int i{}; i <= 'z' - 'a'; i++)
    m[i + 'a'] = std::make_shared<Character<T>>(i + 'a');
  return std::move(m);
}
template <typename T>
const std::unordered_map<char, std::shared_ptr<MathExpression<T>>>
    math_expressions = generate_expression_map<T>();
} // namespace expressions
