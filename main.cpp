
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
    Book* B1=new Novel("Victor Hugo", "Les Misérables", "Folio Classique","9792070409228", TOUS,Litterature); //Book_Id = 1
    Book* B2=new Novel("Stendhal", "Le Rouge et le Noir", "Folio Classique", "9792070412396", TOUS,Litterature); //Book_Id = 2
    Book* B3=new Comic("Hergé","Tintin Objectif Lune","Casterman","2203001151",JEUNESSE,"Hergé"); //Book_Id = 3
    Book* B4=new Poetry("Baudelaire","Les Fleurs du Mal", "Folio Classique", "2070466655",TOUS,PROSE); //Book_Id = 4
    Book* B5=new Drama("Eschyle","Les Perses","Belles Lettres","2251799567",TOUS,AV_IV); //Book_Id = 5
    Book* B6=new Album("Chris Van Allsburg","L'épave du Zéphyr","L'Ecole Des Loisirs", "9782211211567 ",JEUNESSE,DRAW); //Book_Id = 6
    Library* L1=new Library("Alcazar","Belsunce");
    Library* L2=new Library("Castellane","Castellane");
    vector <Library*> lib_list;
    lib_list.push_back(L1);
    lib_list.push_back(L2);
    L1->buy_book(B1);
    L2->buy_book(B2);
    vector <Book*> book_list;
    book_list.push_back(B1);
    book_list.push_back(B2);
    book_list.push_back(B3);
    book_list.push_back(B4);
    book_list.push_back(B5);
    book_list.push_back(B6);
    Member M1=Member("Ledar", "Thomas", "117 boulevard de la Libération",L1,5);
    Member M2=Member("LeGuillou", "Marin", "117 boulevard de la Libération",L2,5);
    vector <Member> member_list;
    member_list.push_back(M1);
    member_list.push_back(M2);

    /* De base les bibliothèques ne possèdent qu'un seul livre, il faut les acheter via l'interface */

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
            	choix_menu_bibliotheque=0;
            	choix_menu_livre=0;
                cout << "1. Bibliothèque\n2. Livre\n3. Retour" << endl;
                cin >> choix_menu_principal;
                if (choix_menu_principal==1){
                    while (choix_menu_bibliotheque !=1) {
                        choix_menu_principal=0;
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
                        cout << "Menu livre\n---------------------" << endl;
                        cout << "1. Retour\n2. Acheter\n3. Supprimer\n4. Livres possédés" << endl;
                        cin >> choix_menu_livre;
                        if (choix_menu_livre == 2){
                        	int BOOK;
                            cout << "Vous voulez acheter un livre\n" << endl;
                            cout << "Quel est le livre que vous voulez acheter ? \n" << endl;
                            int i=0;
                            for (Book* book : book_list){
                            	cout<<i<<"  "<<endl;
                                book->affiche();
                                i+=1;
                            }
                            cout << "Rentrez le numéro qui précède le livre que vous souhaitez acheter  \n" << endl;
                            cin >>BOOK;
                            lib_list[LIB]->buy_book(book_list[BOOK]);
                            book_list.erase(book_list.begin()+BOOK);
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
                            cout << "Rentrez le numéro qui précède le livre que vous souhaitez supprimer  \n" << endl;
                            cin >>BOOK;
                            lib_list[LIB]->delete_book(lib_list[LIB]->get_book_list()[BOOK]);
                        }
                        if (choix_menu_livre == 4){
                        	if (lib_list[LIB]->get_book_list().size()==0){
                        		cout<<"La bibliothèque ne possède aucun livre"<<endl;
                        	}
                            for (Book* book: lib_list[LIB]->get_book_list()){
                                book->affiche();
                            }
                        }
                    }
                }
            }
        }
        if (menu_1 == 2){
			string LastName;
			menu_1 = 0;
			int adherent;
			cout << "Quel est votre NomPrénom (sans espace entre les deux) ?/n Si le nom n'est pas trouvé vous serez renvoyé à ce menu"<<endl;
			cin >> LastName;
			unsigned int i;
			for (i=0; i<member_list.size(); i++){
				if (member_list[i].get_lastname()+member_list[i].get_firstname() == LastName && member_list[i].get_lib()==lib_list[LIB]){
                    adherent = i;
					cout<<"L'adhérent a été trouvé dans la base de données de cette bibliothèque"<<endl;
					int choix_menu_adherent;
					while (choix_menu_adherent != 1 ){
						choix_menu_adherent = 0;
						cout << "Vous souhaitez ?\n"<<endl;
						cout << "1. Retour\n2. Emprunter un livre ?\n3. Rendre un livre emprunté ?\n4. Savoir combien de livres vous pouvez emprunter ?\n5. Livres en votre possession" <<endl;
						cin >> choix_menu_adherent;
						if (choix_menu_adherent == 4){
							if (member_list[adherent].get_nb_allowed() > 0){
								cout << "Vous pouvez encore emprunter "<<member_list[adherent].get_nb_allowed()<<" livres"<<endl;
							}
							else {
								cout<<"Vous ne pouvez plus emprunter de livres. Vous devez en rendre un"<<endl;
							}
						}
						if (choix_menu_adherent == 2){
							int BookId;
							choix_menu_adherent=0;
							cout<<"Vous souhaitez emprunter un livre"<<endl;
							cout<<"Quel est l'ID du livre que vous souhaitez emprunter ?"<<endl;
							cin >> BookId;
							member_list[adherent].borrow_book(BookId);
						}
						if (choix_menu_adherent == 3){
							int BookId;
							choix_menu_adherent=0;
							cout<<"Vous souhaitez rendre un livre"<<endl;
							cout<<"Quel est l'ID du livre que vous souhaitez rendre ?"<<endl;
							cin >> BookId;
							member_list[adherent].return_book(BookId);
						}
						if (choix_menu_adherent == 5){
							cout <<"Les livres que vous avez empruntés: "<<endl;
							for (Book* book : member_list[adherent].get_detained_books()){
								book -> affiche();
							}
						}
					}
				}
			}


		}


};




    return 0;
}

