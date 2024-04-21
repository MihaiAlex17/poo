//
// Created by Alex on 21.04.2024.
//

#ifndef POO_STEWARDESA_H
#define POO_STEWARDESA_H

#include "Angajati.h"
#include <vector>

class Stewardesa : public Angajati {
private:
    std::string nume;
    std::string prenume;
    int salariu;
    std::string functie;
    std::string limbaVorbita;

public:
    explicit Stewardesa( std::string limba ="", const std::string &n="", const std::string &pre="", int sal=0  );
    virtual ~Stewardesa();
    virtual void DetaliiRol() override;
    Stewardesa(const Stewardesa &aux);
    bool operator==(const Stewardesa &angajat) const;
    bool operator!=(const Stewardesa &angajat) const;
    friend std::ostream &operator<<(std::ostream &out, const Stewardesa &angajat);
    friend std::istream &operator>>(std::istream &ci, Stewardesa &angajat);
    int getSalariu() const;
};


#endif //POO_STEWARDESA_H
