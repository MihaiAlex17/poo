#include "Pilot.h"

Pilot::Pilot(const std::string &n, const std::string &pre, int sal, int vechime,int id,const std::string &func ): Angajati(n,pre,sal),id(id),vechime(vechime),functie(func)
{
}
Pilot::~Pilot(){}


std::ostream& operator<<(std::ostream& ou, const Pilot& pilot) {
    ou << "Nume: " << pilot.getNume() << std::endl;
    ou << "Prenume: " << pilot.getPrenume() << std::endl;
    ou << "Salariu: " << pilot.getSalariu() << std::endl;
    ou << "Vechime: " << pilot.vechime << " ani"<<std::endl;
    ou << "ID: " << pilot.id<< std::endl;
    ou << "Functie: " << pilot.functie << std::endl;
    return ou;
}
std::istream& operator>>(std::istream& input, Pilot& pilot){

    input >> dynamic_cast<Angajati&>(pilot);
    std::cout<<"Introduceti CNP-ul pilotului: ";
    input >> pilot.id;
    std::cout<<"Introduceti vechimea pilotului: ";
    input>> pilot.vechime;
    return input;
}

int Pilot::getId() const {
    return id;
}

int Pilot::getVechime() const {
    return vechime;
}
