 #include<fstream>
#include<string>
#include<iostream>
#include<ios>

int CreateNote(std::string note) {
    std::ofstream file("notes.txt", std::ios::app);
    file << note << std::endl;
    file.close();
    return 0;
    }