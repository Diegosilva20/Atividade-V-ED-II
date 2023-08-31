#ifndef COMPARARTITULACAOANDNOME_H
#define COMPARARTITULACAOANDNOME_H
#include "docentescomparador.h"

class compararTitulacaoAndNome : public docentesComparador
{
public:
    compararTitulacaoAndNome();
     bool comparar(const docentes &p1, const docentes &p2) const override;
};

#endif // COMPARARTITULACAOANDNOME_H
