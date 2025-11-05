#pragma once
#include <string>
#include <iostream>
#include "User.h"
#include<fstream>
#include<vector>
#include<sstream>
#include"HashTable.h"
#include"Grammar.h"
#include<windows.h>

extern int id;
extern std::string name,password;
extern Vector<User> UserList;
extern HashTable<Word> Dictionary;
extern Vector<Grammar> gList;

void sign_up(Vector<User>&,std::ofstream&, int&);
void log_out();
void option();
void UI();
void readfile(std::ifstream&, Vector<User>&);
void showinfo(Vector<User>&);
void readvocal(HashTable<Word>&, std::ifstream&);
void readGrammar(std::ifstream&, Vector<Grammar>&);
void luu_vocalbulary(HashTable<Word>&, std::ofstream&);
void Search(HashTable<Word>&, std::string&, User*&);
void viewHistory(User*&);
void LoginMenu(User*&, Vector<User>&, int&, std::ofstream&);
void MainMenu(User*&, HashTable<Word>&, Vector<Grammar>&);
void SearchGrammar(Vector<Grammar>&,User*&);
void FindGrammar(Vector<Grammar>&,User*&);
void AllGrammar(Vector<Grammar>&,User*&);
void SearchWord(HashTable<Word>&, User*&);
void clearScreen();
void pauseScreen();
