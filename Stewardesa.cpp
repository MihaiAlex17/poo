#include "Stewardesa.h"

Stewardesa::Stewardesa(const std::string &n, const std::string &pre, int sal, const std::string &func,const std::string &limba):
Angajati(n,pre,sal),functie(func),limbaVorbita(limba){
}
Stewardesa::~Stewardesa() {
}


std::ostream& operator<<(std::ostream& ou, const Stewardesa& stewardesa) {
    ou << "Nume: " << stewardesa.getNume() << std::endl;
    ou << "Prenume: " << stewardesa.getPrenume() << std::endl;
    ou << "Salariu: " << stewardesa.getSalariu() << std::endl;
    ou << "Limba vorbita: " << stewardesa.limbaVorbita << std::endl;
    ou << "Functie: " << stewardesa.functie << std::endl;
    return ou;
}
std::istream& operator>>(std::istream& input, Stewardesa& stewardesa){

    input >> dynamic_cast<Angajati&>(stewardesa);
    std::cout<<"Introduceti limba straina pe care o vorbeste stweardesa: ";
    input >> stewardesa.limbaVorbita;
    return input;
}




