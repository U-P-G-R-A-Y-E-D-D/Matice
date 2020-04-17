#include <iostream>
#include <cstdlib>
#include "matice.h"

using namespace std;

int main() {

    matice m1 (4,6);
    matice m2 (m1);
    matice m3 (3, 2);
    matice m4=m1+m2;

    m1.vypis();
    std::cout<<""<<endl;
    m2.vypis();
    std::cout<<""<<endl;
    m3.vypis();
    m2=m3;
    std::cout<<""<<endl;
    m4.vypis();
    std::cout<<""<<endl;
    return 0;
}