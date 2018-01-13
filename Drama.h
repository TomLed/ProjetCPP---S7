//
// Created by marin on 13/12/17.
//

#ifndef PROJETCPP_DRAMA_H
#define PROJETCPP_DRAMA_H

#include "Book.h"

enum century{AV_X,AV_IX,AV_VIII,AV_VII,AV_VI,AV_V,AV_IV,AV_III,AV_II,AV_I,Zero,I,II,III,IV,V,VI,VII,VIII,IX,X,XI,XII,XIII,XIV,XV,XVI,XVII,XVIII,XIX,XX,XXI};
class Drama: public Book{
protected:
    century siecle;

public:
    Drama(string author, string title, string editor, string isbn, Target target, century siecle, bool state=1);
    century get_siecle(){ return siecle;}
    string decentury();
    void affiche();
};





#endif //PROJETCPP_DRAMA_H
