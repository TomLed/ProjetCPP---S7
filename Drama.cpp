//
// Created by marin on 13/12/17.
//
#include "Drama.h"

Drama::Drama(string author, string title, string editor, string isbn, Target target, century siecle,
             bool state):Book(author,title,editor,isbn,target,state){
    this->siecle=siecle;
}

string Drama::decentury() {
    string table[]={"-X","-IX","-VIII","-VII","-VI","-V","-IV","-III","-II","-I","0","I","II","III",
                    "IV","V","VI","VII","VIII","IX","X","XI","XII","XIII","XIV","XV","XVI","XVII","XVIII",
                    "XIX","XX","XXI"};
    return table[siecle];
}

void Drama::affiche() {
    Book::affiche();
    cout<<"Siècle : "<<decentury()<<"\n"<<endl;
}
