#include "../shared/input.hpp"
#include <vector>
#include "../shared/characters.hpp"
#include "../shared/vector_utils.hpp"
int main(){
    Input* input = new Input();
    auto condition = [](Input* in, std::vector<char>* v){
        const char cc = in->as_char();

        if(Characters::characters.contains(cc) and Characters::characters.at(cc) == type::vowel) v->insert(v->begin(), cc);
        else if(Characters::characters.contains(cc) and (Characters::characters.at(cc) == type::number or Characters::characters.at(cc) == type::consonant)) v->push_back(cc);
        else if(cc == '*') v->erase(v->begin());
        else if(cc == '#') v->pop_back();
        else if(cc == '!') return true;
        std::cout << "Vector status: "<< *v << std::endl;
        return false;
        };
    std::vector<char> characters;

    input->update_text("Input character: \n")->take_until(condition, &characters);

    std::cout << "Final Vector: "<< characters << std::endl;

    delete input;
    return 0;
}