#include <string>
#include <iostream>
#include "User.h"
#include<fstream>
#include<vector>
#include<sstream>
void welcome();
void sign_up(std::string&, std::string&);
void log_out();
void option();
void readfile(std::ifstream&, std::vector<User>&);
void showinfo(std::vector<User>&);
void readvocal();
void UI();