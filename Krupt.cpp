#include<stdlib.h>
#include<iostream>
#include<string>
#include<unordered_map>
#include<map>
#include<sstream>
#include<vector>
#include<fstream>
#include<stdio.h>
#include<winsock2.h>
#include<windows.h>
#include<winnt.h>
#include<cstdlib>
#include<wingdi.h>
#include"headers/NoteTaker.h"
#include"headers/WebOpen.h"
#include"headers/ShowNote.h"

using namespace std;



int main() {
  cout<<"-------------------------------";
  cout<<"\n*** Krupt ConsoleHelper ***\n";
  cout<<"-------------------------------";
  cout<<"\n Enter a command or type --Help for help:";
  while (true){
    cout<<"> ";
    std::map<std::string, char> consoleCommand;

    string line;
    getline(cin, line);

    stringstream ss(line);
    string word;
    vector<string> words;
    while (ss>>word){
      words.push_back(word);
    }
    if (words.empty()){
      
    }else if(words[0] == "--Help"){
      cout<<"Available Commands:"<<endl;
      cout<<" --Help ->Show this help message\n"<<endl;
      cout<<" --Exit -->Exit the program"<<endl;
      cout<<" --OpenFile -->Open File or Application"<<endl;
      cout<<" --CreateNote -->Creates note inside console\n"<<endl;
      cout<<" --OpenUrl -->Open a link in your browser"<<endl;
      cout<<" --ShowNote -->Open your notes if they are created\n"<<endl;
      cout<<" --AddrInfo -->Returns the ip address of a url"<<endl;
    }
    else if (words[0] == "--Exit"){
      break;
    }
    else if(words[0] == "--OpenFile"){
      string input;
      cout<<"Enter File: >";
      getline(cin, input);

      int result = system(("start "+ input).c_str());
      cout<<"Result: "<<result;
      if(result == 0){
        cout<<"Successfully opened " << input<<endl;
      }
    }
    else if(words[0] == "--CreateNote"){
      cout<<"Enter your text: ";
      string note;
      cin>>note;
      CreateNote(note);
      cout << "Note saved successfully!" << endl;
      }
    else if(words[0] == "--ShowNote") {
      ShowNote();
      cout<<"**You can also use the --OpenFile command to open the note text file.**";
    }
    else if(words[0] == "--OpenUrl"){
      Openlink();
    }
    else if(words[0] == "--AddrInfo"){
    }
    else if (words[0] == "--History")
    {
        if (history::commandCounter == 0)
        {
            std::cout << "No previous commands used" << std::endl;
        }
        else
        {
            int commandIndex = atoi(words[1].c_str());
            if (commandIndex > history::commandCounter || commandIndex < 1) {
                std::cout<<"Invalid Command."<<std::endl;

            }
            else {
                line = history::PreviousHistory[commandIndex - 1];
                cout << ">" << line << std::endl;
            }
        }
    }

    else{
      cout<<"Invalid Command. Type --Help for a list of commands"<<endl;
    }
    if (words[0] != "--History") {
        history::PreviousHistory[history::commandCounter % 10] = line;

        history::commandCounter++;
    }
  }
  
}
