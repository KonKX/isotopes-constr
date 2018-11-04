#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include "isotopes.h"

using namespace std;

int main(void){
    int i, neutrons_number=0, e=0;
    Atom** pinakas;
    srand (time(NULL));
    int atom_number=rand()%3+1; //1-5
    pinakas = new Atom*[atom_number];
    for (i = 0 ; i < atom_number ; i++){
        neutrons_number=rand()%3+6; //6-8
        pinakas[i] = new Atom(6,neutrons_number);
        pinakas[i]->print_info();
        e += pinakas[i] -> get_electric_charge();
    }
    cout<<"--Total number of atoms constructed: "<<i<<endl;
    cout<<"--Total number of protons constructed: "<<6*i<<endl;
    cout<<"--Total number of neutrons constructed: "<<neutrons_number*i<<endl;
    cout<<"--Total electric charge: "<<e<<endl<<endl;
    for (i = 0 ; i < atom_number ; i++)
            delete pinakas[i];
    delete[] pinakas;
    cout<<"--Total number of atoms destructed: "<<i<<endl;

    return 0;
}
