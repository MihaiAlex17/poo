#include "Avioane.h"
#include "Pilot.h"
#include "Stewardesa.h"

Avioane::Avioane(const std::string &mod, const std::string &dest, int cap,
        int locuriOcupate,int pret,int med,int nr,const std::vector<Angajati> &ech) {
    this->model=mod;
    this->destinatie=dest;
    this->capacitate=cap;
    this->locuri_ocupate=locuriOcupate;
    this->pret_bilet=pret;
    this->medie_bilete=med;
    this->nr_pers_echipaj=nr;
    this->echipaj=ech;}

Avioane::~Avioane(){
    model.clear();
    destinatie.clear();
    capacitate=0;
    locuri_ocupate=0;
    pret_bilet=0;
    medie_bilete=0;
    nr_pers_echipaj=0;
    echipaj.clear();
}

std::ostream &operator<<(std::ostream &out, const Avioane &avion) {
    out << "Model avion: " << avion.model <<",Destinatie: "
        << avion.destinatie << ",Capacitate: " << avion.capacitate << ",Numarul de locuri ocupate: "
        << avion.locuri_ocupate<<",Pretul unui bilet: "<<avion.pret_bilet
        <<",Media de vanzare a biletelor per zbor: "<<avion.medie_bilete
        << ",Numarul de persoane din echipaj: " << avion.nr_pers_echipaj << "\n" << "Echipajul:" << "\n";
    for(int i=0;i<avion.nr_pers_echipaj;i++)
        out << avion.echipaj[i];
    return out;
}

std::istream &operator>>(std::istream &ci,Avioane &avion) {
    std::cout<<"Introduceti modelul avionului:";
    ci >> avion.model;
    std::cout<<"Introduceti destinatia:";
    ci >> avion.destinatie;
    std::cout<<"Introduceti capacitatea avionului:";
    ci >> avion.capacitate;
    std::cout<<"Introduceti numarul de locuri ocupate:";
    ci >> avion.locuri_ocupate;
    std::cout<<"Introduceti pretul unui bilet:";
    ci>>avion.pret_bilet;
    std::cout<<"Introduceti media de vanzare a biletelor per zbor:";
    ci>>avion.medie_bilete;
    std::cout<<"Introduceti numarul de persoane din echipaj:";
    ci >> avion.nr_pers_echipaj;
    avion.echipaj.clear();
    for (int i = 0; i < avion.nr_pers_echipaj; i++) {
        Angajati angajat;
        std::cout<<"Introduceti persoana "<<i+1<<" din echipaj :"<<"\n";
        ci >> angajat;
        avion.echipaj.push_back(angajat);
    }
    return ci;
}

bool Avioane::operator==(const Avioane &av) const {
    return model == av.model &&
           destinatie == av.destinatie &&
           capacitate == av.capacitate &&
           locuri_ocupate == av.locuri_ocupate &&
           pret_bilet == av.pret_bilet &&
           medie_bilete == av.medie_bilete &&
           nr_pers_echipaj == av.nr_pers_echipaj &&
           echipaj == av.echipaj;
}

bool Avioane::operator!=(const Avioane &rhs) const {
    return !(rhs == *this);
}

const std::string &Avioane::getDestinatie() const {
    return destinatie;
}

int Avioane::getPretBilet() const {
    return pret_bilet;
}

const std::vector<Angajati> &Avioane::getEchipaj() const {
    return echipaj;
}

int Avioane::getMedieBilete() const {
    return medie_bilete;
}

void Avioane::DetaliiGeneraleEchipaj() {
    std::cout << "testing\n";
    std::cout << echipaj.size() << '\n';
    for(Angajati angajat : echipaj){
        angajat.DetaliiRol();
        if(dynamic_cast<Pilot*>(&angajat)){
            std::cout << "E pilot\n";
            Pilot* pilot = dynamic_cast<Pilot*>(&angajat);
            pilot->DetaliiRol();
        }
        if(dynamic_cast<Stewardesa*>(&angajat)){
            std::cout << "E steward\n";
            Stewardesa* steward = dynamic_cast<Stewardesa*>(&angajat);
            steward->DetaliiRol();
        }
    }
}

void Avioane::AdaugaPilot(Pilot pilot) {
    pilot.DetaliiRol();
    Angajati angajat = pilot;
    this->echipaj.push_back(angajat);
}

void Avioane::AdaugaSteward(Stewardesa steward) {
    steward.DetaliiRol();
    Angajati angajat = steward;
    this->echipaj.push_back(angajat);
}
