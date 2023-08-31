#ifndef DOCENTESCOMPARADOR_H
#define DOCENTESCOMPARADOR_H
#include "docentes.h"

class docentesComparador
{
public:
    docentesComparador();
    virtual bool comparar(const docentes &p1,const docentes &p2) const = 0;
};

#endif // DOCENTESCOMPARADOR_H
