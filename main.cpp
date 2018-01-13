
#include <iostream>
#include "Book.h"
#include "Comic.h"
#include "Poetry.h"
#include "Novel.h"
#include "Drama.h"
#include "Album.h"
#include "Library.h"
#include "Member.h"
using namespace std;


int main() {
    Book* B1=new Novel("Victor Hugo", "Les Misérables", "Folio Classique","9792070409228", TOUS,Litterature);
    Book* B2=new Novel("Stendhal", "Le Rouge et le Noir", "Folio Classique", "9792070412396", TOUS,Litterature);
    Book* B3=new Comic("Hergé","Tintin Objectif Lune","Casterman","2203001151",JEUNESSE,"Hergé");
    Book* B4=new Poetry("Baudelaire","Les Fleurs du Mal", "Folio Classique", "2070466655",TOUS,PROSE);
    Book* B5=new Drama("Eschyle","Les Perses","Belles Lettres","2251799567",TOUS,AV_IV);
    Book* B6=new Album("Chris Van Allsburg","L'épave du Zéphyr","L'Ecole Des Loisirs", "9782211211567 ",JEUNESSE,DRAW);
    Library* L1=new Library("Alcazar","Belsunce");
    Library* L2=new Library("Castellane","Castellane");
    L2->buy_book(B1);
    L2->buy_book(B2);
    L1->buy_book(B5);
    L1->buy_book(B6);
    L1->buy_book(B3);
    L1->buy_book(B4);
    vector <Library*> lib_list;
    lib_list.push_back(L1);
    lib_list.push_back(L2);
    Member M1=Member("Ledar", "Thomas", "117 boulevard de la Libération",L1,5);

    int menu_1;
    while(menu_1!=3){
        menu_1=0;
        int LIB;
        cout << "Dans quelle bibliothèque êtes-vous ?\n";
        for (Library* i : lib_list){
            cout<<i->get_lib_id()<<" "<<i->get_name()<<endl;
        }
        cin >> LIB;
        LIB-=1;
        cout << "Vous êtes..." << endl;
        cout << "1. De l'administration ?\n2. Un adhérent ?\n3. Quitter" << endl;
        cin >> menu_1;
        if (menu_1==1){
            int choix_menu_principal, choix_menu_bibliotheque, choix_menu_livre;
            cout << "Administration de bibliothèques\n---------------------" << endl;
            while (choix_menu_principal != 3){
                choix_menu_principal=0;
                cout << "1. Bibliothèque\n2. Livre\n3. Retour" << endl;
                cin >> choix_menu_principal;
                if (choix_menu_principal==1){
                    while (choix_menu_bibliotheque !=1) {
                        choix_menu_bibliotheque=0;
                        cout << "Menu bibliothèque\n---------------------" << endl;
                        cout << "1. Retour\n2. Emprunt\n3. Rendre" << endl;
                        cin >> choix_menu_bibliotheque;
                        if (choix_menu_bibliotheque ==2){
                            string ISBN;
                            int LIB_2;
                            cout << "Vous voulez emprunter un livre à une autre bibliothèque\n" << endl;
                            cout << "Quel est l'ISBN du livre que vous voulez emprunter ?\n" << endl;
                            cin >> ISBN;
                            cout << "A quelle bibliothèque voulez-vous l'emprunter ?\n" << endl;
                            for (Library* i : lib_list){
                                cout<<i->get_lib_id()<<" "<<i->get_name()<<endl;
                            }
                            cin >> LIB_2;
                            LIB_2-=1;
                            lib_list[LIB]->ask_book(ISBN, lib_list[LIB_2]);
                        }
                        if (choix_menu_bibliotheque == 3){
                            int BOOK;
                            int LIB_2;
                            cout << "Vous voulez rendre un livre emprunté à une autre bibliothèque\n" << endl;
                            cout << "Quel est le livre que vous voulez rendre ? Rentrez le numéro \n" << endl;
                            int i=0;
                            for (Book* book: lib_list[LIB]->get_book_list()){
                                 if(lib_list[LIB]->get_lib_id() != book->get_lib_id()) {
                                    cout<<i<<"  "<<endl;
                                    book->affiche();}
                                i+=1;
                            }
                            cin >> BOOK;
                            cout << "Quel est le numéro de la bibliothèque à qui vous devez le rendre ?\n" << endl;
                            cin>>LIB_2;
                            LIB_2-=1;
                            lib_list[LIB]->send_back(lib_list[LIB]->get_book_list()[BOOK],*lib_list[LIB_2]);

                        }
                    }

                }
                if (choix_menu_principal==2){
                    while (choix_menu_livre != 1){
                        choix_menu_livre=0;
                        cout << "Menu bibliothèque\n---------------------" << endl;
                        cout << "1. Retour\n2. Acheter\n3. Supprimer\n4. Livres possédés" << endl;
                        cin >> choix_menu_livre;
                        if (choix_menu_livre == 2){
                            int BOOK;
                            cout << "Vous voulez acheter un livre\n" << endl;
                            cout << "Quel est le livre que vous voulez acheter ? \n" << endl;
                        }
                        if (choix_menu_livre == 3){
                            int BOOK;
                            cout << "Vous voulez supprimer un livre\n" << endl;
                            cout << "Quel est le livre que vous voulez supprimer ?  \n" << endl;
                            int i=0;
                            for (Book* book: lib_list[LIB]->get_book_list()){
                                cout<<i<<"  "<<endl;
                                book->affiche();
                                i+=1;
                            }
                            cin >> BOOK;
                            lib_list[LIB]->delete_book(lib_list[LIB]->get_book_list()[BOOK]);
                        }
                        if (choix_menu_livre == 4){
                            for (Book* book: lib_list[LIB]->get_book_list()){
                                book->affiche();
                            }
                        }
                    }
                }
            }
        }
        if (menu_1 == 2){
            int choix_menu_adherent;
            while (choix_menu_adherent != 1 ){
                choix_menu_adherent=0;
                cout << "Vous souhaitez ?\n"<<endl;
                cout << "1. Retour\n2. Emprunter un livre ?\n3. Rendre un livre emprunté ?\n4. Savoir combien de livres vous pouvez emprunter ?" <<endl;
                cin >> choix_menu_adherent;
            }
        }

    };




    return 0;
}

    /*}
     *                  if (lib_list[LIB]->get_lib_id() != book->get_book_id_buyer()){
                    cin >> ISBN;
                    cout << "A quelle bibliothèque l'avez-vous emprunté ?\n" << endl;
                    for (Library* i : lib_list){
                        cout<<i->get_lib_id()<<" "<<i->get_name()<<endl;
                    }
                    cin >> LIB_2;
                    LIB_2-=1;
                    lib_list[LIB]->send_back(, lib_list[LIB_2])*/