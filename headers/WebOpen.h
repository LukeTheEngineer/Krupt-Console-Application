#include <windows.h>
#include <iostream>
#include<unistd.h>

int Openlink() {
  // URL to open
  std::cout<<"Enter your url: ";
  std::string url;
  std::cin>>url;

  const char* url_cstr = url.c_str();
  
  // Open the URL in the default web browser
  HINSTANCE result = ShellExecute(NULL, "open", url_cstr, NULL, NULL,
 SW_SHOWNORMAL);

  if ((intptr_t)result <= 32) {
    std::cerr << "Error opening URL" << std::endl;
    return 1;
  }

  sleep(5000);
}
