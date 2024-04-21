//
// Created by Alex on 21.04.2024.
//

#include "Pilot.h"



Pilot::Pilot(const std::string &n, const std::string &pre, int sal, int vechime)
{this->nume = n;
    this->functie= "Pilot";
    this->prenume=pre;
    this->vechime = vechime;
    this->salariu=sal;}
Pilot::~Pilot() {
    nume.clear();
    functie.clear();
    salariu=0;
    prenume.clear();
}

Pilot::Pilot(const Pilot &aux){
    this->nume=aux.nume;
    this->functie=aux.functie;
    this->salariu=aux.salariu;
    this->prenume=aux.prenume;

}

bool Pilot::operator==(const Pilot &angajat) const {
    return nume == angajat.nume &&
           prenume == angajat.prenume &&
           salariu == angajat.salariu &&
           functie == angajat.functie;
}

bool Pilot:: operator!=(const Pilot &angajat) const {
    return !(angajat == *this);
}

std::ostream &operator<<(std::ostream &out, const Pilot &angajat) {
    out<< "Nume: " << angajat.nume << ",Prenume: " << angajat.prenume << ",Salariu lunar: " << angajat.salariu
       << ",Functie: " << angajat.functie<<"\n";
    return out;
}

std::istream &operator>>(std::istream &ci, Pilot &angajat){
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

int Pilot::getSalariu() const {
    return salariu;
}

void Pilot::DetaliiRol() {
    std::cout << "Pilotul: " << this->nume << ' ' << this->prenume << '\n';
    std::cout << "Are vechimea " << this->vechime << '\n';
}
