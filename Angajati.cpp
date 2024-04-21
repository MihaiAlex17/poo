#include "Angajati.h"


Angajati::Angajati(const std::string &n, const std::string &pre, int sal, const std::string &func)
{this->nume = n;
    this->functie= func;
    this->prenume=pre;
    this->salariu=sal;}
Angajati::~Angajati() {
    nume.clear();
    functie.clear();
    salariu=0;
    prenume.clear();
}

Angajati::Angajati(const Angajati &aux){
    this->nume=aux.nume;
    this->functie=aux.functie;
    this->salariu=aux.salariu;
    this->prenume=aux.prenume;

}

bool Angajati::operator==(const Angajati &angajat) const {
    return nume == angajat.nume &&
           prenume == angajat.prenume &&
           salariu == angajat.salariu &&
           functie == angajat.functie;
}

bool Angajati:: operator!=(const Angajati &angajat) const {
    return !(angajat == *this);
}

std::ostream &operator<<(std::ostream &out, const Angajati &angajat) {
    out<< "Nume: " << angajat.nume << ",Prenume: " << angajat.prenume << ",Salariu lunar: " << angajat.salariu
       << ",Functie: " << angajat.functie<<"\n";
    return out;
}

std::istream &operator>>(std::istream &ci, Angajati &angajat){
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

int Angajati::getSalariu() const {
    return salariu;
}

void Angajati::DetaliiRol() {
    std::cout << "Angajatul: " <<this->nume << ' ' << this->prenume << '\n';
    std::cout << "Are functia " << this->functie << '\n';
}
