#ifndef DOCENTESORDENA_H
#define DOCENTESORDENA_H
#include "docentes.h"
#include "docentescomparador.h"
#include <vector>
#include <algorithm>
using namespace std;
class docentesOrdena
{
public:
    docentesOrdena(std::vector<docentes> &arrayDocentes, const docentesComparador &comparador);
    std::vector<docentes>& ordena();
private:
    vector<docentes>& arrayDocentes;
    const docentesComparador &comparador;

};

#endif // DOCENTESORDENA_H
