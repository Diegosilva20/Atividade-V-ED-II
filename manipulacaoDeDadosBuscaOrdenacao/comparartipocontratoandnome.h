#ifndef COMPARARTIPOCONTRATOANDNOME_H
#define COMPARARTIPOCONTRATOANDNOME_H
#include "docentescomparador.h"

class compararTipoContratoAndNome : public docentesComparador
{
public:
    compararTipoContratoAndNome();
     bool comparar(const docentes &p1, const docentes &p2) const override;
};

#endif // COMPARARTIPOCONTRATOANDNOME_H
