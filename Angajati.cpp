#include "Angajati.h"


Angajati::Angajati(const std::string &n, const std::string &pre, int sal)
{this->nume = n;
    this->prenume=pre;
    this->salariu=sal;}
Angajati::~Angajati() {
    nume.clear();
    salariu=0;
    prenume.clear();
}

Angajati::Angajati(const Angajati &aux){
    this->nume=aux.nume;
    this->salariu=aux.salariu;
    this->prenume=aux.prenume;

}

bool Angajati::operator==(const Angajati &angajat) const {
    return nume == angajat.nume &&
           prenume == angajat.prenume &&
           salariu == angajat.salariu;
}

bool Angajati:: operator!=(const Angajati &angajat) const {
    return !(angajat == *this);
}

std::ostream &operator<<(std::ostream &out, const Angajati &angajat) {
    out<< "Nume: " << angajat.nume << ",Prenume: " << angajat.prenume << ",Salariu lunar: " << angajat.salariu
       << ",Functie: " <<"\n";
    return out;
}

std::istream &operator>>(std::istream &ci, Angajati &angajat){
    std::cout<<"Introduceti numele angajatului:";
    ci >> angajat.nume ;
    std::cout<<"Introduceti prenumele angajatului:";
    ci >> angajat.prenume;
    std::cout<<"Introduceti salariul lunar angajatului:";
    ci >>angajat.salariu;
    return ci;
}

int Angajati::getSalariu() const {
    return salariu;
}

const std::string &Angajati::getNume() const {
    return nume;
}

const std::string &Angajati::getPrenume() const {
    return prenume;
}


