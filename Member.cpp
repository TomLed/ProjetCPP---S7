//
// Created by Thomas Ledar on 15/12/2017.
//

#include "Member.h"


int compteur_membres=0;

Member::Member(string lastname, string firstname, string adress, Library* L, int nb_allowed){
    this->lib=L;
    this->lastname = lastname;
    this->firstname = firstname;
    this->adress = adress;
    compteur_membres++;
    this->member_id=compteur_membres;
    this->nb_allowed = nb_allowed;
    this->detained_books = {};
}

void Member::affiche() {
    cout << "Nom: " << firstname << " " << lastname << endl << "Adresse: " << adress << endl << "Bibliothèque: " << lib->get_name() <<endl<<"Livres détenus :";
    for(Book* book:detained_books){
        book->affiche();
    }
    cout << endl << "Nombre authorisé: " << nb_allowed << endl;
};

void Member::borrow_book(int book_id) {
    if (nb_allowed > 0) {
        if(lib->book_id_in_lib(book_id)){
            for (Book *book:lib->get_book_list()) {
                if (book->get_book_id() == book_id) {
                    if (book->get_state()) {
                        nb_allowed--;
                        book->set_state(0);
                        detained_books.push_back(book);
                        cout << "Le livre a bien été emprunté"
                             << endl;//ça gère pas trop pour l'instant si le livre n'est pas dispo ou pas dans la biblio
                    } else {
                        cout << "Le livre est déjà emprunté" << endl;
                    }
                }
            }
        }
        else{
            cout<<"Le livre n'est pas disponible dans votre bibliothèque"<<endl;
        }
    }
    else{
        cout<<"Vous avez déjà emprunté le nombre maximum de livre"<<endl;
    }
};

bool Member::is_book_detained(int book_id) {
    bool r=0;
    for(Book* book:detained_books){
        if(book->get_book_id()==book_id){
            r=1;
        }
    }
    return r;
}
void Member::return_book(int book_id) {
    int i=0;
    if(is_book_detained(book_id)){
        while(book_id != detained_books[i]->get_book_id()) i++;
        detained_books[i]->set_state(1);
        detained_books.erase(detained_books.begin()+i);
        nb_allowed++;
    }
    else{
        cout<<"Ce livre ne fait pas parti des livres empruntés par l'usager"<<endl;
    }

};