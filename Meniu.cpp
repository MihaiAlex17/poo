//
// Created by Alex on 26.05.2024.
//
#include "Meniu.h"
#include <iostream>
Meniu* Meniu::instancePtr = NULL;

void Meniu::DisplayMeniu() {
    std::cout<<"1.Vezi informatiile aeroportului"<<"\n";
    std::cout<<"2.Adauga un avion care a aterizat pe aeroport"<<"\n";
    std::cout<<"3.Elimina un avion care a decolat de pe avion"<<"\n";
    std::cout<<"4.Vezi profitul lunar al aeroportului"<<"\n";
    std::cout<<"5.Iesi din meniu"<<"\n"<<"\n";
    std::cout<<"Alege:"<<"\n";
}

void Meniu::TakeMenuOption() {
    std::cin>>input;
    switch (input) {
        case 1:{std::cout<<a;
            break;}
        case 2:{
            Avioane av;
            std::cin>>av;
            a.AvionAterizat(av);
            break;
        }
        case 3:{std::string dest;
            std::cout<<"Ce destinatie are avionul decolat?"<<"\n";
            a.Destinatii();
            std::cin>>dest;
            a.DecolareAvion(dest);
            break;
        }
        case 4:{a.ProfitAeroport();
            break;}
        default:{std::cout<<"Aceasta optiune nu exista"<<"\n";
            break;}

        case 5: {running= false;
            break;}}
}

Meniu::Meniu() {
    this->running = true;
//    this->a = new Aeroport();

    this->input = 0;
}

Meniu *Meniu::getInstance() {
    if(instancePtr == NULL)
    {
        instancePtr = new Meniu();
        return instancePtr;
    }
    else{
        return instancePtr;
    }
}

bool Meniu::getRunning() {
    return this->running;
}

