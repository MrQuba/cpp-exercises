#include <iostream>
class Log{
  public:
  void info(const std::string log_msg) const{
      std::cout << "[info] " << log_msg << " \n";
  }
  void error(const std::string log_msg) const{
      std::cout << "[error] " << log_msg << " \n";
  }
  
};