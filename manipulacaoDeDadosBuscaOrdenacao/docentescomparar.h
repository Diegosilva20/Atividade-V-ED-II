#ifndef DOCENTESCOMPARAR_H
#define DOCENTESCOMPARAR_H
#include "docentes.h"

class docentesComparar
{
public:
    docentesComparar();
    virtual bool comparar(const docentes &p1,docentes &p2) const = 0;
};

#endif // DOCENTESCOMPARAR_H
