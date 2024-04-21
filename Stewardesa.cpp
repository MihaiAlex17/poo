//
// Created by Alex on 21.04.2024.
//

#include "Stewardesa.h"



Stewardesa::Stewardesa(std::string limba,const std::string &n, const std::string &pre, int sal )
{this->nume = n;
    this->functie= "Stewardesa";
    this->prenume=pre;
    this->salariu=sal;
    this->limbaVorbita = limba;
}
Stewardesa::~Stewardesa() {
    nume.clear();
    functie.clear();
    salariu=0;
    prenume.clear();
}

Stewardesa::Stewardesa(const Stewardesa &aux){
    this->nume=aux.nume;
    this->functie=aux.functie;
    this->salariu=aux.salariu;
    this->prenume=aux.prenume;

}

bool Stewardesa::operator==(const Stewardesa &angajat) const {
    return nume == angajat.nume &&
           prenume == angajat.prenume &&
           salariu == angajat.salariu &&
           functie == angajat.functie;
}

bool Stewardesa:: operator!=(const Stewardesa &angajat) const {
    return !(angajat == *this);
}

std::ostream &operator<<(std::ostream &out, const Stewardesa &angajat) {
    out<< "Nume: " << angajat.nume << ",Prenume: " << angajat.prenume << ",Salariu lunar: " << angajat.salariu
       << ",Functie: " << angajat.functie<<"\n";
    return out;
}

std::istream &operator>>(std::istream &ci, Stewardesa &angajat){
    std::cout<<"Introduceti numele angajatului:";
    ci >> angajat.nume ;
    std::cout<<"Introduceti prenumele angajatului:";
    ci >> angajat.prenume;
    std::cout<<"Introduceti salariul lunar angajatului:";
    ci >>angajat.salariu;
    std::cout<<"Introduceti functia angajatului:";
    ci >>angajat.functie;
    return ci;
}

int Stewardesa::getSalariu() const {
    return salariu;
}

void Stewardesa::DetaliiRol() {
    std::cout << "Stewardesa: " << this->nume << ' ' << this->prenume << '\n';
    std::cout << "Vorbeste: ";
    std::cout << this->limbaVorbita;
    std::cout << "\n";
}
