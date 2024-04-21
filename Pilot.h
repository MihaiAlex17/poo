//
// Created by Alex on 21.04.2024.
//

#ifndef POO_PILOT_H
#define POO_PILOT_H

#include "Angajati.h"

class Pilot: public Angajati {
private:
    std::string nume;
    std::string prenume;
    int salariu;
    std::string functie;
    int vechime;

public:
    explicit Pilot(const std::string &n="", const std::string &pre="", int sal=0, int vechime = 0);
    virtual ~Pilot();
    Pilot(const Pilot &aux);
    virtual void DetaliiRol() override;
    bool operator==(const Pilot &angajat) const;
    bool operator!=(const Pilot &angajat) const;
    friend std::ostream &operator<<(std::ostream &out, const Pilot &angajat);
    friend std::istream &operator>>(std::istream &ci, Pilot &angajat);
    int getSalariu() const;

};


#endif //POO_PILOT_H
