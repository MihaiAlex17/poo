//
// Created by Alex on 21.04.2024.
//

#ifndef POO_STEWARDESA_H
#define POO_STEWARDESA_H

#include "Angajati.h"
#include <vector>

class Stewardesa : public Angajati {
private:
    std::string functie;
    std::string limbaVorbita;
public:
    explicit Stewardesa( const std::string &n="", const std::string &pre="", int sal=0  ,const std::string &functie="Stewardesa",const std::string &limba ="");
    virtual ~Stewardesa();
    friend std::ostream &operator<<(std::ostream &out, const Stewardesa &angajat);
    friend std::istream &operator>>(std::istream &ci, Stewardesa &angajat);

};


#endif //POO_STEWARDESA_H
