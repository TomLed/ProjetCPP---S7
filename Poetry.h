//
// Created by marin on 12/12/17.
//

#ifndef PROJET_POETRY_H
#define PROJET_POETRY_H
#include "Book.h"


enum type{PROSE, VERS, PROSEetVERS};
class Poetry : public Book{
protected:
    type indic;

public:
    Poetry(string author, string title, string editor, string isbn, Target target, type indic, bool state=1);
    type get_indic(){ return indic;}
    string detype();
    void affiche();
};

#endif //PROJET_POETRY_H
