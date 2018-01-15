//
// Created by Thomas Ledar on 15/12/2017.
//

#ifndef PROJETCPP_MEMBER_H
#define PROJETCPP_MEMBER_H
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "Book.h"
#include "Library.h"
using namespace std ;

class Member {
protected :
    int member_id;
    string lastname;
    string firstname;
    string adress;
    Library* lib;
    vector<Book*> detained_books;
    int nb_allowed;
public:
    Member(string lastname, string firstname, string adress, Library* L, int nb_allowed);
    int get_member_id() { return member_id; }
    string get_lastname() { return lastname; }
    void set_lastname(string new_lastname) { lastname = new_lastname; }
    string get_firstname() { return firstname; }
    void set_firstname(string new_firstname) { firstname = new_firstname; }
    string get_adress() { return adress; }
    void set_adress(string new_adress) { adress = new_adress; }
    Library* get_lib() { return lib; }
    void set_lib(Library* L) { lib = L; }
    vector<Book*> get_detained_books() { return detained_books; }
    int get_nb_allowed() { return nb_allowed; }
    void affiche();
    void borrow_book(int book_id);
    bool is_book_detained(int book_id);
    void return_book(int book_id);

};

#endif //PROJETCPP_MEMBER_H
