#include <iostream>
#include <string>

using namespace std;

class Up_quark{
private:
    string mass;
    double spin, electric_charge;
    string statistics;
public:
    Up_quark(string, double, double, string);
    ~Up_quark();
    void print_info() const;
};

class Down_quark{
private:
    string mass;
    double spin, electric_charge;
    string statistics;
public:
    Down_quark(string, double, double, string);
    ~Down_quark();
    void print_info() const;
};

class Gluon{
private:
    string mass;
    double spin, electric_charge;
    string statistics;
public:
    Gluon(string, double, double, string);
    ~Gluon();
    void print_info() const;
};

class Electron{
private:
    string mass;
    double spin, electric_charge;
    string statistics;
public:
    Electron(string, double, double, string);
    ~Electron();
    double get_electric_charge() const;
    void print_info() const;
};

class Proton{
private:
    int i, j, k;
    Up_quark* up_quarks_array[2];
    Down_quark* down_quarks_array[1];
    Gluon* gluons_array[3];
    string mass;
    double spin, electric_charge;
    string statistics;
public:
    Proton(string, double, double, string);
    ~Proton();
    double get_electric_charge() const;
    void print_info() const;
};

class Neutron{
private:
    int i, j, k;
    Up_quark* up_quarks_array[1];
    Down_quark* down_quarks_array[2];
    Gluon* gluons_array[3];
    string mass;
    double spin, electric_charge;
    string statistics;

public:
    Neutron(string, double, double, string);
    ~Neutron();
    void print_info() const;
};

class Nucleus{
private:
    int protons;
    int neutrons;
public:
    void set(const int, const int);
};

class Atom{
private:
    int i, j, k;
    int atomic_number, neutrons_number, mass_number;
    Nucleus nucleus;
    Proton** protons_array;
    Neutron** neutrons_array;
    Electron** electrons_array;
    double electric_charge, pr, e;

public:
    Atom(int p, int n);
    ~Atom();
    int get_atom_number() const;
    int get_mass_number() const;
    double get_electric_charge() const;
    void print_info() const;
};
