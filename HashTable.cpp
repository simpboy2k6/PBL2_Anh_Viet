#include "HashTable.h"
#include <iostream>
using namespace std;

// Định nghĩa hàm của HashTable có kiểu int
HashTable::HashTable(const int capacity):capacity(capacity)
{
    this->table = new Vector[this->capacity];
}

HashTable::~HashTable()
{}

void HashTable::hash(const int x){
    (this->table + this->getkey(x))->pb(x);
}

int HashTable::getkey(const int x)const{
    return x % this->capacity;
}

Vector& HashTable::operator[](const int i){
    if(0<=i && i<100){
        return *(this->table + i);
    }else{
        cout<<"Out of HashTable\n";
        return *(this->table);
    }

}


// Định nghĩa hàm của HashTable có kiểu class Word

HashTable_Word::HashTable_Word(const int capacity):capacity(capacity)
{
    this->table = new Vector_Word[this->capacity];
}

HashTable_Word::~HashTable_Word()
{}

void HashTable_Word::hash(Word& x){
    (this->table + this->getkey(x.getidword()))->pb(x);
}

int HashTable_Word::getkey(const int x)const{
    return x % this->capacity;
}

Vector_Word& HashTable_Word::operator[](const int i){
    if(0<=i && i<100){
        return *(this->table + i);
    }else{
        cout<<"Out of HashTable\n";
        return *(this->table);
    }

}
/*int main(){
    HashTable_Word H;
    Word W(1,"abandon", "verb", "từ bỏ", "The sailors abandoned the sinking ship", "/əˈbændən/");
    H.hash(W);
    W.SetInfoWord("absence", "noun", "sự vắng mặt", "Her absence was noted by the teacher", "/ˈæbsəns/");
    H.hash(W);
    H[1][1].GetInfoWord();
    H[1][0].GetInfoWord();
    
}*/

