#include "Poetry.h"

//
// Created by marin on 12/12/17.
//
Poetry::Poetry(string author, string title, string editor, string isbn, Target target, type indic,
               bool state):Book(author,title,editor,isbn,target,state){
    this->indic=indic;
}

string Poetry::detype() {
    string table[]={"Prose","Vers","Prose et vers"};
    return table[indic];
}

void Poetry::affiche() {
    Book::affiche();
    cout<<"Type : "<<detype()<<"\n"<<endl;
}
