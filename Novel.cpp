//
// Created by marin on 13/12/17.
//

#include "Novel.h"

Novel::Novel(string author, string title, string editor, string isbn, Target target,  genre type,
             bool state):Book(author,title,editor,isbn,target,state){
    this->type=type;
}

string Novel::detype() {
    string table[]={"Littérature", "Roman noir", "Roman policier", "Roman animalier",
                    "Roman d'amour", "Roman de mœurs", "Roman gothique","Roman courtois","Roman épistolaire"
            ,"Roman-feuilleton","Roman graphique","Roman historique","Roman-photo","Roman picaresque"
            ,"Roman-mémoires","Roman populaire","Roman d'aventures","Roman d'anticipation", "Roman d'espionnage",
                    "Roman d'apprentissage","Roman de chevalerie","Roman autobiographique","Nouveau roman",
                    "Roman chevaleresque","Conte","Nouvelle"};
    return table[type];
}

void Novel::affiche() {
    Book::affiche();
    cout<<"Genre : "<<detype()<<"\n"<<endl;
}
