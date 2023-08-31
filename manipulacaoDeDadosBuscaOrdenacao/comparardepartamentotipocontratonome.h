#ifndef COMPARARDEPARTAMENTOTIPOCONTRATONOME_H
#define COMPARARDEPARTAMENTOTIPOCONTRATONOME_H
#include "docentescomparador.h"

class compararDepartamentoTipoContratoNome : public docentesComparador
{
public:
    compararDepartamentoTipoContratoNome();
    bool comparar(const docentes &p1, const docentes &p2)const override;
};

#endif // COMPARARDEPARTAMENTOTIPOCONTRATONOME_H
