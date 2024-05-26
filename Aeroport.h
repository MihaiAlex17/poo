#ifndef POO_AEROPORT_H
#define POO_AEROPORT_H
#include <iostream>
#include <string>
#include "Angajati.h"
#include "Avioane.h"
#include "Zbor.h"
#include <list>
class Aeroport {
private:
    std::string nume;
    std::string tara;
    std::string oras;
    int nrAvioane;
    std::vector<Avioane> avioane;

public:
    explicit Aeroport(const std::string &n = "Henri Coanda", const std::string &t = "Romania",
                      const std::string &o = "Bucuresti", int nr = 0, const std::vector<Avioane> &av = std::vector<Avioane>());

    ~Aeroport();
    Aeroport(const Aeroport& other);
    friend std::ostream &operator<<(std::ostream &out, const Aeroport &aeroport);
    friend std::istream &operator>>(std::istream &ci,Aeroport &aer);
    bool operator==(const Aeroport &aer) const;
    bool operator!=(const Aeroport &obj) const;
    friend Aeroport& operator+(const Aeroport &a1,const Aeroport &a2);
    void AvionAterizat(const Avioane& avion);
    void DecolareAvion(const std::string& destinatieAvion);
    void Destinatii();
    void ProfitAeroport();
    friend bool operator>(const Aeroport& a1, const Aeroport& a2);
};


#endif
