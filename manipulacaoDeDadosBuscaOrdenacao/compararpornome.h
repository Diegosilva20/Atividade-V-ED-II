#ifndef COMPARARPORNOME_H
#define COMPARARPORNOME_H
#include "docentescomparador.h"

class compararPorNome : public docentesComparador
{
public:
    compararPorNome();
    bool comparar(const docentes &p1, const docentes &p2) const override;
};

#endif // COMPARARPORNOME_H
