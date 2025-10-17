#pragma once
#include <string>
#include <iostream>
#include "User.h"
#include<fstream>
#include"HashTable.h"
#include<sstream>
void welcome();
void sign_up(std::string&, std::string&);
void log_out();
void option();
void readfile(std::ifstream&, Vector_User&);
void showinfo(Vector_User&);
void readvocal();
void Search(HashTable_Word&, std::string&);