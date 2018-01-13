//
// Created by marin on 13/12/17.
//

#ifndef PROJETCPP_NOVEL_H
#define PROJETCPP_NOVEL_H

#include "Book.h"

enum genre{Litterature, Roman_noir, Roman_policier, Roman_animalier,
    Roman_d_amour, Roman_de_moeurs, Roman_gothique, Roman_courtois, Roman_epistolaire,
    Roman_feuilleton, Roman_graphique, Roman_historique, Roman_photo, Roman_picaresque,
    Roman_memoires, Roman_populaire, Roman_d_aventures, Roman_d_anticipation,
    Roman_d_espionnage, Roman_d_apprentissage, Roman_de_chevalerie, Roman_autobiographique,
    Nouveau_roman, Roman_chevaleresque, Conte, Nouvelle};
class Novel : public Book{
protected:
    genre type;

public:
    Novel(string author, string title, string editor, string isbn, Target target,  genre indic, bool state=1);
    genre get_type(){ return type;}
    string detype();
    void affiche();
};



#endif //PROJETCPP_NOVEL_H
