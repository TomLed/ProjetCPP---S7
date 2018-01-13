//
// Created by marin on 12/12/17.
//

#ifndef PROJET_COMIC_H
#define PROJET_COMIC_H
#include "Book.h"
class Comic : public Book{
protected:
    string drawer;

public:
    Comic(string author, string title, string editor, string isbn, Target target, string drawer, bool state=1);
    string get_drawer(){ return drawer;}
    void affiche();
};
#endif //PROJET_COMIC_H
