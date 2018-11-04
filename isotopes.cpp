#include <iostream>
#include <string>
#include "isotopes.h"

using namespace std;

Up_quark::Up_quark(string mass = "2.01 MeV/c^2", double spin = 0.5, double electric_charge = 2/3, string statistics = "Fermi-Dirac" )
    : mass(mass), spin(spin), electric_charge(electric_charge), statistics(statistics){
        cout<<"An up quark has been constructed"<<endl;
    }
Up_quark::~Up_quark(){
        cout<<"An up quark will be destroyed"<<endl;
    }

void Up_quark::print_info() const{
    cout<<"mass: "<<mass<<" spin: "<<spin<<" electric charge: "<<electric_charge<<" statistics: "<<statistics<<endl;
}

Down_quark::Down_quark(string mass = "4.7 MeV/c^2", double spin = 0.5, double electric_charge = -1/3, string statistics = "Fermi-Dirac" )
    : mass(mass), spin(spin), electric_charge(electric_charge), statistics(statistics){
        cout<<"A down quark has been constructed"<<endl;
    }
Down_quark::~Down_quark(){
        cout<<"A down quark will be destroyed"<<endl;
    }

void Down_quark::print_info() const{
    cout<<"mass: "<<mass<<" spin: "<<spin<<" electric charge: "<<electric_charge<<" statistics: "<<statistics<<endl;
}

Gluon::Gluon(string mass = "0", double spin = 1, double electric_charge = 0, string statistics = "Bose-Einstein")
    : mass(mass), spin(spin), electric_charge(electric_charge), statistics(statistics){
        cout<<"A gluon has been constructed"<<endl;
    }
Gluon::~Gluon(){
        cout<<"A gluon will be destroyed"<<endl;
    }

void Gluon::print_info() const{
    cout<<"mass: "<<mass<<" spin: "<<spin<<" electric charge: "<<electric_charge<<" statistics: "<<statistics<<endl;
}

Electron::Electron(string mass = "5.48579909070*10^-4 u", double spin = 0.5, double electric_charge = -1, string statistics = "Fermi-Dirac")
    : mass(mass), spin(spin), electric_charge(electric_charge), statistics(statistics){
        cout<<"An electron has been constructed"<<endl;
    }
Electron::~Electron(){
        cout<<"An electron will be destroyed"<<endl;
    }

double Electron::get_electric_charge() const{
    return electric_charge;
}

void Electron::print_info() const{
    cout<<"mass: "<<mass<<" spin: "<<spin<<" electric charge: "<<electric_charge<<" statistics: "<<statistics<<endl;
}

Proton::Proton(string mass = "1.007 u", double spin = 0.5, double electric_charge = 1, string statistics = "Fermi-Dirac" )
    : mass(mass), spin(spin), electric_charge(electric_charge), statistics(statistics){
        for (i = 0 ; i < 2 ; i++){
            up_quarks_array[i] = new Up_quark;
            up_quarks_array[i] -> print_info();
        }
        for (j = 0 ; j < 1 ; j++){
            down_quarks_array[j] = new Down_quark;
            down_quarks_array[j] -> print_info();
        }
        for (k = 0 ; k < 3 ; k++){
            gluons_array[k] = new Gluon;
            gluons_array[k] -> print_info();
        }
        cout<<"A proton has been constructed"<<endl;
    }
Proton::~Proton(){
        for (i = 0 ; i < 2 ; i++)
            delete up_quarks_array[i];
        for (j = 0 ; j < 1 ; j++)
            delete down_quarks_array[j];
        for (k = 0 ; k < 3 ; k++)
            delete gluons_array[k];
        cout<<"A proton will be destroyed"<<endl<<endl;
    }

double Proton::get_electric_charge() const{
    return electric_charge;
}

void Proton::print_info() const{
    cout<<"mass: "<<mass<<" spin: "<<spin<<" electric charge: "<<electric_charge<<" statistics: "<<statistics<<endl<<endl;
}

Neutron::Neutron(string mass = "1.0085 u", double spin = 0.5, double electric_charge = 0, string statistics = "Fermi-Dirac" )
    : mass(mass), spin(spin), electric_charge(electric_charge), statistics(statistics){
        for (i = 0 ; i < 1 ; i++){
            up_quarks_array[i] = new Up_quark;
            up_quarks_array[i] -> print_info();
        }
        for (j = 0 ; j < 2 ; j++){
            down_quarks_array[j] = new Down_quark;
            down_quarks_array[j] -> print_info();
        }
        for (k = 0 ; k < 3 ; k++){
            gluons_array[k] = new Gluon;
            gluons_array[k] -> print_info();
        }
        cout<<"A neutron has been constructed"<<endl;
    }
Neutron::~Neutron(){
        for (i = 0 ; i < 1 ; i++)
            delete up_quarks_array[i];
        for (j = 0 ; j < 2 ; j++)
            delete down_quarks_array[j];
        for (k = 0 ; k < 3 ; k++)
            delete gluons_array[k];
        cout<<"A neutron will be destroyed"<<endl<<endl;
    }

void Neutron::print_info() const{
    cout<<"mass: "<<mass<<" spin: "<<spin<<" electric charge: "<<electric_charge<<" statistics: "<<statistics<<endl<<endl;
}

void Nucleus::set(const int p, const int n){
        protons=p;
        neutrons=n;
    }


Atom::Atom(int p, int n)
    :atomic_number(p), neutrons_number(n), mass_number(p + n), pr(0), e(0)
    {
        protons_array = new Proton*[atomic_number];
        for (i = 0 ; i < atomic_number ; i++){
            protons_array[i] = new Proton;
            protons_array[i]->print_info();
            pr += protons_array[i]->get_electric_charge();
        }
        neutrons_array = new Neutron*[neutrons_number];
        for (j = 0 ; j < neutrons_number ; j++){
            neutrons_array[j] = new Neutron;
            neutrons_array[j]->print_info();
        }
        electrons_array = new Electron*[atomic_number];
        for (k = 0 ; k < atomic_number ; k++){
            electrons_array[k] = new Electron;
            electrons_array[k]->print_info();
            e += electrons_array[k]->get_electric_charge();
        }
        nucleus.set(atomic_number, neutrons_number);
        electric_charge = e + pr;
        cout<<"An atom has been constructed"<<endl;
        cout<<"Number of protons:"<<atomic_number<<endl;
        cout<<"Number of neutrons:"<<neutrons_number<<endl;

        }
Atom::~Atom(){
        for (i = 0 ; i < atomic_number ; i++)
            delete protons_array[i];
        delete[] protons_array;
        for (j = 0 ; j < neutrons_number ; j++)
            delete neutrons_array[j];
        delete[] neutrons_array;
        for (k = 0 ; k < atomic_number ; k++)
            delete electrons_array[k];
        delete[] electrons_array;

        cout<<"An atom will be destroyed"<<endl;
        cout<<"Number of protons:"<<atomic_number<<endl;
        cout<<"Number of neutrons:"<<neutrons_number<<endl<<endl;
    }

int Atom::get_atom_number() const{
    return atomic_number;
}

int Atom::get_mass_number() const{
    return mass_number;
}

double Atom::get_electric_charge() const{
    return electric_charge;
}

void Atom::print_info() const{
    cout<<"atomic number: "<<atomic_number<<" mass number: "<<mass_number<<" electric charge: "<<electric_charge<<endl<<endl;
}
