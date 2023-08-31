#ifndef COMPARARPORDEPARTAMENTOANDNOME_H
#define COMPARARPORDEPARTAMENTOANDNOME_H
#include "docentescomparador.h"

class compararPorDepartamentoAndNome : public docentesComparador
{
public:
    compararPorDepartamentoAndNome();
    bool comparar(const docentes &p1, const docentes &p2)const override;
};

#endif // COMPARARPORDEPARTAMENTOANDNOME_H
