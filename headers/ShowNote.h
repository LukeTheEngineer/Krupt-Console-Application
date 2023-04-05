#include<fstream>

void ShowNote() {
  std::ifstream file("notes.txt");
  std::string line;
  while (std::getline(file, line)) {
    std::cout << line << std::endl;
  }
  file.close();
}