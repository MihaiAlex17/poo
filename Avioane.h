//
// Created by Alex on 18.04.2024.

#ifndef POO_AVIOANE_H
#define POO_AVIOANE_H
#include <iostream>
#include <string>
#include "Angajati.h"
#include <vector>
#include "Pilot.h"
#include "Stewardesa.h"

class Avioane {
    private:
        std::string model;
        std::string destinatie;
        int capacitate;
        int locuri_ocupate;
        int pret_bilet;
        int medie_bilete;
        int nr_pers_echipaj;
        std::vector<Angajati> echipaj;
    public:
        explicit Avioane(const std::string &mod="", const std::string &dest="", int cap=0,int locuriOcupate=0,int pret=0,int med=0,int nr=0,const std::vector<Angajati> &ech= std:: vector<Angajati>());
        ~Avioane();
        void DetaliiGeneraleEchipaj();
        void AdaugaPilot(Pilot);
        void AdaugaSteward(Stewardesa);
        friend std::ostream &operator<<(std::ostream &out, const Avioane &avion);
        friend std::istream &operator>>(std::istream &ci,Avioane &avion);
        bool operator==(const Avioane &av) const;
        bool operator!=(const Avioane &rhs) const;
        const std::string &getDestinatie() const;
        int getPretBilet() const;
        const std::vector<Angajati> &getEchipaj() const;
        int getMedieBilete() const;
};


#endif //POO_AVIOANE_H
