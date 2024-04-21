#include <iostream>
#include <string>
#include <vector>
#include "Angajati.h"
#include "Aeroport.h"
#include "Avioane.h"

    void meniu(){
        std::cout<<"1.Vezi informatiile aeroportului"<<"\n";
        std::cout<<"2.Adauga un avion care a aterizat pe aeroport"<<"\n";
        std::cout<<"3.Elimina un avion care a decolat de pe avion"<<"\n";
        std::cout<<"4.Vezi profitul lunar al aeroportului"<<"\n";
        std::cout<<"5.Iesi din meniu"<<"\n"<<"\n";
        std::cout<<"Alege:"<<"\n";
    }
int main() {
    Avioane test;
    test.DetaliiGeneraleEchipaj();
    Pilot pilot("ana","george",100,29);
    test.AdaugaPilot(pilot);
    Stewardesa stew("Engleza","gigi","anton",100);
    test.AdaugaSteward(stew);

    Aeroport a;
    std::cin>>a;
    int alg;
    bool m= true;
    while(m){
        meniu();
        std::cin>>alg;
        switch (alg) {
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

            case 5: {m= false;
            break;}}
    }
    return 0;
}

