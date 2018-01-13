//
// Created by marin on 13/12/17.
//

#ifndef PROJETCPP_ALBUM_H
#define PROJETCPP_ALBUM_H

#include "Book.h"

enum illustration{DRAW, PICTURE, DRAWetPICTURE};
class Album : public Book{
protected:
    illustration type;

public:
    Album(string author, string title, string editor, string isbn, Target target,  illustration type, bool state=1);
    illustration get_illustation(){ return type;}
    string deillustration();
    void affiche();
};

#endif //PROJETCPP_ALBUM_H
