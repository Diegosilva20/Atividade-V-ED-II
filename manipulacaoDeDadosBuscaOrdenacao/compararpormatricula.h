#ifndef COMPARARPORMATRICULA_H
#define COMPARARPORMATRICULA_H
#include "docentescomparador.h"

class compararPorMatricula : public docentesComparador
{
public:
    compararPorMatricula();
    bool comparar(const docentes &p1, const docentes &p2)const override;
};

#endif // COMPARARPORMATRICULA_H
