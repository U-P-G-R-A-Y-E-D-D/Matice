//
// Created by Honza on 17.04.2020.
//

#ifndef MATICE_MATICE_H
#define MATICE_MATICE_H
#include <iostream>
#include <iomanip>
#include <stdexcept>

class matice {
public:
    matice();
    matice(int, int);
    matice(const matice& orig);
    virtual ~matice();
    void vypis() const;
    matice & operator = (const matice&);
    matice operator + (const matice&) const;
    const int* operator [] (int) const;
    const int operator () (unsigned int, unsigned int) const;
    int* operator [] (int);
    int & operator () (unsigned int, unsigned int);
private:
    int pocetRadku;
    int pocetSloupcu;
    int **ukazatel;
    void dealloc();
    void malloc(int, int);

};

#endif //MATICE_MATICE_H
