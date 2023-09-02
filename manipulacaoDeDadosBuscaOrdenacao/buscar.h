#ifndef BUSCAR_H
#define BUSCAR_H
#include "docentes.h"

class buscar
{
public:
    buscar();
    docentes buscaSequencialNome(const std::vector<docentes>&vetor,QString dado);
    docentes buscaBinariaNome(const std::vector<docentes>&vetor,QString dado);
    docentes buscaSequencialMatricula(const std::vector<docentes>&vetor,QString dado);
    docentes buscaBinariaMatricula(const std::vector<docentes>&vetor,QString dado);
};

#endif // BUSCAR_H
