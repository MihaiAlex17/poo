//
// Created by Alex on 21.04.2024.
//

#ifndef POO_PILOT_H
#define POO_PILOT_H

#include "Angajati.h"

class Pilot: public Angajati {
private:
    int id;
    int vechime;
    std::string functie;

public:
    explicit Pilot(const std::string &n="", const std::string &pre="", int sal=0, int vechime=0,int id=0,const std::string &functie="Pilot");
    virtual ~Pilot();
    friend std::ostream& operator<<(std::ostream& output, const Pilot& pilot);
    friend std::istream& operator>>(std::istream& input, Pilot& pilot);
    int getId() const;
    int getVechime() const;
};


#endif //POO_PILOT_H
