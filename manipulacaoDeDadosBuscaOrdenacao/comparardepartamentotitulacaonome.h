#ifndef COMPARARDEPARTAMENTOTITULACAONOME_H
#define COMPARARDEPARTAMENTOTITULACAONOME_H
#include "docentescomparador.h"

class compararDepartamentoTitulacaoNome : public docentesComparador
{
public:
    compararDepartamentoTitulacaoNome();
     bool comparar(const docentes &p1, const docentes &p2)const override;
};

#endif // COMPARARDEPARTAMENTOTITULACAONOME_H
