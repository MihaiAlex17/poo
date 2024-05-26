#include "Aeroport.h"

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wc++11-extensions"
Aeroport::Aeroport(const std::string &n, const std::string &t, const std::string &o,int nr,const std::vector<Avioane>& av)
{this->nume=n;
    this->tara=t;
    this->oras=o;
    this->nrAvioane=nr;
    this->avioane=av;
    }

Aeroport::Aeroport(const Aeroport& other){
    this->nume = other.nume;
    this->tara = other.tara;
    this->oras = other.oras;
    this->nrAvioane = other.nrAvioane;
    this->avioane = other.avioane;
}
Aeroport::~Aeroport()
{   nume.clear();
    tara.clear();
    oras.clear();
    nrAvioane=0;
    avioane.clear();

}


std::ostream &operator<<(std::ostream &out, const Aeroport &aeroport) {
    out << "Numele aeroportului: " << aeroport.nume << ",Tara: " << aeroport.tara
        << ",Oras: " << aeroport.oras <<"\n"<< "Numarul de avioane: " << aeroport.nrAvioane<<"\n";
    for(int i=0;i<aeroport.nrAvioane;i++)
        out <<"Avionul "<<i+1<<": "<<"\n"<<aeroport.avioane[i];
    return out;
}
std::istream &operator>>(std::istream &ci,Aeroport &aer) {
    std::cout<<"Introduceti numarul de avioane aflate pe aeroport:";
    ci>> aer.nrAvioane;
    aer.avioane.clear();
    for (int i = 0; i < aer.nrAvioane; i++) {
        Avioane av;
        std::cout<<"Introduceti avionul "<<i+1<<" :"<<"\n";
        ci >> av;
        aer.avioane.push_back(av);
    }

    return ci;

}

bool Aeroport::operator==(const Aeroport &aer) const {
    return nume == aer.nume &&
           tara == aer.tara &&
           oras == aer.oras &&
           nrAvioane == aer.nrAvioane &&
           avioane == aer.avioane;
}

bool Aeroport::operator!=(const Aeroport &obj) const {
    return !(obj == *this);
}
Aeroport& operator+(const Aeroport &a1,const Aeroport &a2){
    Aeroport *a3;
    a3 = new Aeroport(a1.nume, a1.tara, a1.oras, a1.nrAvioane + a2.nrAvioane,a1.avioane);
    for(int j=0;j<a2.nrAvioane;j++)
        a3->avioane.push_back(a2.avioane[j]);
    return *a3;
}

void Aeroport::AvionAterizat(const Avioane& avion) {
    nrAvioane++;
    avioane.push_back(avion);
}
void Aeroport::DecolareAvion(const std::string& destinatieAvion){
    for(int i=0;i!=nrAvioane;i++)
        if (avioane[i].getDestinatie() == destinatieAvion) {
            avioane.erase(avioane.begin() + i);
            nrAvioane--;
            break;
        }
}

void Aeroport::Destinatii(){
    std::cout<<"Avioane de pe aeroport au destinatiile:"<<"\n";
    for(int i=0;i!=nrAvioane;i++)
        std::cout<<avioane[i].getDestinatie()<<"\n";
}

void Aeroport::ProfitAeroport(){
    int cheltuieli=0,incasari=0,profit;
    for(int i=0;i!=nrAvioane;i++)
        incasari+=avioane[i].getMedieBilete()*avioane[i].getPretBilet()*30;
    for(int i=0;i!=nrAvioane;i++){
        std::vector<Angajati>ech=avioane[i].getEchipaj();
        unsigned long long nr=ech.size();
        for(int j = 0; j < nr; j++)
            cheltuieli += ech[j].getSalariu();
    }
    profit=incasari-cheltuieli;
    if(profit>0)
        std::cout<<"Aeroportul are un profit lunar de "<<profit<<"\n";
    else {
        if (profit < 0)
            std::cout << "Aeroportul are pierderi lunare de " << profit << "\n";
        else
            std::cout << "Aeroportul nu are nici profit,nici pierderi" << "\n";
    }
}
bool operator>(const Aeroport& a1, const Aeroport& a2) {
    return a1.nrAvioane > a2.nrAvioane;
}
#pragma clang diagnostic pop