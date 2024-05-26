//
// Created by Alex on 22.05.2024.
//

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wc++11-extensions"
#ifndef POO_ZBOR_H
#define POO_ZBOR_H

#include <iostream>
#include <string>
#include <vector>
#include <map>

template <typename TipPasager, typename TipBagaj>
class Zbor {
public:
    std::string codZbor;
    std::vector<TipPasager> pasageri;
    std::map<TipPasager, TipBagaj> bagaje;

    explicit Zbor(const std::string& codZbor);

    void adaugaPasager(const TipPasager& pasager);
    void adaugaBagaj(const TipPasager& pasager, const TipBagaj& bagaj);

    virtual void afiseazaDetalii() const;
};

template <typename TipPasager, typename TipBagaj>
class ZborPasageri : public Zbor<TipPasager, TipBagaj> {
public:
    explicit ZborPasageri(const std::string& codZbor);

    void afiseazaDetalii() const override;
};

template <typename TipPasager, typename TipBagaj>
class ZborMarfa : public Zbor<TipPasager, TipBagaj> {
public:
    explicit ZborMarfa(const std::string& codZbor);

    void afiseazaDetalii() const override;
};

// Definiții pentru template-uri

template <typename TipPasager, typename TipBagaj>
Zbor<TipPasager, TipBagaj>::Zbor(const std::string& codZbor) : codZbor(codZbor) {}

template <typename TipPasager, typename TipBagaj>
void Zbor<TipPasager, TipBagaj>::adaugaPasager(const TipPasager& pasager) {
    pasageri.push_back(pasager);
}

template <typename TipPasager, typename TipBagaj>
void Zbor<TipPasager, TipBagaj>::adaugaBagaj(const TipPasager& pasager, const TipBagaj& bagaj) {
    bagaje[pasager] = bagaj;
}

template <typename TipPasager, typename TipBagaj>
void Zbor<TipPasager, TipBagaj>::afiseazaDetalii() const {
    std::cout << "Zbor: " << codZbor << "\n";
    for (typename std::vector<TipPasager>::const_iterator it = pasageri.begin(); it != pasageri.end(); ++it) {
        const TipPasager& pasager = *it;
        std::cout << "Pasager: " << pasager << ", Bagaj: " << bagaje.at(pasager) << "\n";
    }
}

template <typename TipPasager, typename TipBagaj>
ZborPasageri<TipPasager, TipBagaj>::ZborPasageri(const std::string& codZbor) : Zbor<TipPasager, TipBagaj>(codZbor) {}

template <typename TipPasager, typename TipBagaj>
void ZborPasageri<TipPasager, TipBagaj>::afiseazaDetalii() const {
    std::cout << "Zbor pasageri: " << this->codZbor << "\n";
    Zbor<TipPasager, TipBagaj>::afiseazaDetalii();
}

template <typename TipPasager, typename TipBagaj>
ZborMarfa<TipPasager, TipBagaj>::ZborMarfa(const std::string& codZbor) : Zbor<TipPasager, TipBagaj>(codZbor) {}

template <typename TipPasager, typename TipBagaj>
void ZborMarfa<TipPasager, TipBagaj>::afiseazaDetalii() const {
    std::cout << "Zbor marfa: " << this->codZbor << "\n";
    Zbor<TipPasager, TipBagaj>::afiseazaDetalii();
}


#endif // POO_ZBOR_H
#pragma clang diagnostic pop
