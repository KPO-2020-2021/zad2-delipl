#include "Quiz.h"
#include <limits>
#include <fstream>
Quiz::Quiz(std::string name){
    std::ifstream file;
    file.open("dat/"+ name + ".dat");
    if(!file.good())
        throw std::runtime_error("Can't open file: "+ name + ".dat");

    Expression temp;
    
    while (!file.eof()){
        try{
            file >> temp >> std::ws;
            this->questions.push_back(temp); 
        }
        catch (std::logic_error& e){
            std::cerr << "Napotkano bledne wyrazenie. Zostalo ono pominiete." << std::endl;
            file.clear();
            file.ignore(std::numeric_limits<int>::max(), '\n');
        }
        catch (...){
            throw;
        }
    }
    file.close();
}
unsigned int Quiz::size() const{
    return this->questions.size();
}

Expression Quiz::operator[](unsigned int index) const{
    return this->questions[index];
}