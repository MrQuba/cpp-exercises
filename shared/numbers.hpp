#include <iostream>
#include <functional>
class Numbers{
    public:
    template<typename Lambda>
      static  void displayNumbersInRange(const int beginning, const int end, Lambda lambda, bool descending = false, int step = 1){
            reset();
            for(int i = ((descending) ? end : beginning); ((descending) ? i >= beginning : i <= end);  i += ((descending) ? -step : step)){
                if(std::invoke(lambda, i)){
                    std::cout << i << " ";
                    displayed_numbers++;
                }
                else skipped_numbers++;
            }
            std::cout << std::endl;
        }
        static void reset(){
            skipped_numbers = 0;
            displayed_numbers = 0;
        }
        static void get(){
            std::cout << "Displayed: " << displayed_numbers << " numbers. Skipped: " << skipped_numbers << " numbers" << std::endl;
        }
    private:
    static unsigned int skipped_numbers;
    static unsigned int displayed_numbers;
};