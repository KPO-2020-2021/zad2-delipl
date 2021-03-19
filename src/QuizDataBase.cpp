#include "QuizDataBase.hpp"
Quiz::Quiz(std::string name){
    std::ifstream file;
    file.open(name + ".dat");
    if(!file.good())
        throw std::logic_error("Can't open file: "+ name+ ".dat");

    Expression temp;
    
    while (!file.eof()){
        try{
            file >> temp >> std::ws;
            questions.push_back(temp); 
        }
        catch (std::logic_error& e){
            std::cerr << "Napotkano bledne wyrazenie. Zostalo ono pominiete." << std::endl;
            file.clear();
            file.ignore(10000, '\n');
        }
        catch (...){
            throw;
        }
    }
    file.close();
}
unsigned int Quiz::size() const{
    return questions.size();
}

Expression Quiz::operator[](unsigned int index) const{
    return questions[index];
}