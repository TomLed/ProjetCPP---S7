#include "Library.h"

//
// Created by marin on 13/12/17.
//
int compteur_lib=0;
void presenter(Book &b) {
    b.affiche();
}

Library::Library(string name, string adress) {
    this->name=name;
    this->adress=adress;
    this->book_list={};
    ++compteur_lib;
    this->lib_id=compteur_lib;
}


bool Library::book_in_lib(string isbn, Library* L) {
    bool indic=0;
    for(Book* book : L->book_list){
        if(book->get_isbn()==isbn) indic =1;
    }
    return indic;
}

void Library::buy_book(Book* book) {

    book_list.push_back(book);
    book->set_lib_id(lib_id);
}

void Library::delete_book(Book* book) {
    //book_list.erase(remove(book_list.begin(), book_list.end(),book),book_list.end());
    int i=0;
    while(book->get_book_id() != book_list[i]->get_book_id()) i++;
    book_list.erase(book_list.begin()+i);
    //book_list.pop_back();
}


void Library::ask_book(string isbn, Library* L) {
    int i=0;
    if(book_in_lib(isbn, L)){
        while(L->book_list[i]->get_isbn()!=isbn) i=i+1;
        get_book(L->book_list[i]);
        L->delete_book(L->book_list[i]);
        cout<<"Le livre a été transféré"<<endl;
    }

}

void Library::print_book_list() {
    for(Book* book:book_list){
        book->affiche();
    }}

void Library::get_book(Book *book) {
    book_list.push_back(book);
}

Library get_lib_from_id(int id){


}

void Library::send_back(Book* book, Library L) {
    if(book->get_lib_id()!=L.lib_id){
        cout<<"Le livre n'appartient pas à la biblitothèque demandée, essayez une autre"<<endl;
    }
    else{
        if(book->get_state()==0){
            cout<<"Le livre est emprunté, revenez plus tard"<<endl;
        }
        else{
            L.get_book(book);
            delete_book(book);
            cout<<"Le livre a été rendu"<<endl;
        }
    }

}

bool Library::book_id_in_lib(int book_id) {
    bool a=0;
    for(Book* book:book_list){
        if(book->get_book_id()==book_id){
            a=1;
        }
    }
    return a;
}

