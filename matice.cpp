//
// Created by Honza on 17.04.2020.
//
#include "matice.h"
#include <random>
#include <iostream>

#define MIN 2
#define MAX 10

using namespace std;

matice::matice() {
    this->pocetRadku=0;
    this->pocetSloupcu=0;
    this->ukazatel=0;
}

matice::matice(int pocetRadku, int pocetSloupcu){
    if(pocetRadku<MIN || pocetRadku>MAX){
        pocetRadku=MIN;
    }else{
        this->pocetRadku=pocetRadku;
    }
    if(pocetSloupcu<MIN || pocetSloupcu>MAX){
        pocetSloupcu=MAX;
    }else{
        this->pocetSloupcu=pocetSloupcu;
    }

    malloc(pocetRadku,pocetSloupcu);
    std::random_device generator;
    for(int r=0;r<pocetRadku;r++){
        for(int s=0;s<pocetSloupcu;s++){
            this->ukazatel[r][s]=generator()%99;
        }
    }

}


matice::matice(const matice& orig) {
    this->pocetRadku=orig.pocetRadku;
    this->pocetSloupcu=orig.pocetSloupcu;
    this->ukazatel=new int*[orig.pocetRadku];
    if(this->ukazatel!=0){
        for(int j=0;j<pocetRadku;j++){
            this->ukazatel[j]=new int[pocetSloupcu];
            if(this->ukazatel[j]==0){
                return;
            }else{
                for(int i=0;i<pocetSloupcu;i++){
                    this->ukazatel[j][i]=orig[j][i];
                }
            }
        }
    }
}


void matice::vypis() const{
    for(int r=0;r<pocetRadku;r++){
        for(int s=0;s<pocetSloupcu;s++){
            cout<<this->ukazatel[r][s];
        }
        cout<<endl;
    }
    return;
}


matice::~matice() {
    dealloc();
}

const int* matice::operator [] (int index) const{
    return ukazatel[index];
}

const int matice::operator () (unsigned int i, unsigned int j) const{
    if(i>pocetRadku || j>pocetSloupcu){
        cout<<endl;
    }
    return ukazatel[i][j];

}


int* matice::operator [] (int index){
    return ukazatel[index];
}

int & matice::operator () (unsigned int i, unsigned int j){
    if(i>pocetRadku || j>pocetSloupcu){
        cout<<endl;
    }
    return ukazatel[i][j];
}

void matice::dealloc(){
    if(this->ukazatel!=0){
        for(int i=0;i<pocetRadku;i++){
            delete[]this->ukazatel[i];
            ukazatel[i]=0;
        }
        delete[]this->ukazatel;
        this->ukazatel=0;
    }
}

void matice::malloc(int pocetR, int pocetS){
    this->ukazatel=new int*[pocetR];
    if(this->ukazatel!=0){
        for(int j=0;j<pocetR;j++){
            this->ukazatel[j]=new int[pocetS];
            if(this->ukazatel[j]==0){

            }
        }
    }
    pocetRadku=pocetR;
    pocetSloupcu=pocetS;
}


matice & matice::operator = (const matice& orig){
    if(this!=&orig){
        dealloc();
        malloc(orig.pocetRadku, orig.pocetSloupcu);
        for(int j=0;j<orig.pocetRadku;j++){
            memcpy(this->ukazatel[j],orig.ukazatel[j], orig.pocetSloupcu*sizeof(int));
        }
    }

    return *this;
}

matice matice::operator + (const matice& orig) const {
    matice vysledek(*this);
    if (pocetRadku == orig.pocetRadku && pocetSloupcu == orig.pocetSloupcu) {
        for (int i = 0; i < this->pocetRadku; i++) {
            for (int j = 0; j < orig.pocetSloupcu; j++) {
                vysledek[i][j] += orig[i][j];
            }
        }
    }
    return vysledek;
}

