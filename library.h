#pragma once
#include <string>
#include <iostream>
#include "User.h"
#include<fstream>
#include<vector>
#include<sstream>
#include"HashTable.h"
#include<windows.h>
#include"Vector_User.h"

extern int id;
extern std::string name,password;
extern Vector_User UserList;
extern HashTable_Word Dictionary;

void sign_up(Vector_User&,std::ofstream&, int&);
void log_out();
void option();
void UI();
void readfile(std::ifstream&, Vector_User&);
void showinfo(Vector_User&);
void readvocal(HashTable_Word&, std::ifstream&);
void luu_vocalbulary(HashTable_Word&, std::ofstream&);
void Search(HashTable_Word&, std::string&, User*&);
void viewHistory(User*&);
void LoginMenu(User*&, Vector_User&, int&, std::ofstream&);
void MainMenu(User*&, HashTable_Word&);
void clearScreen();
void pauseScreen();
