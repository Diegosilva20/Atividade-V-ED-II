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
    docentesOrdena(const vector<docentes>& arrayDocentes,const docentesComparador &comparador);
    vector<docentes>ordena();
private:
    const vector<docentes>& arrayDocentes;
    const docentesComparador &comparador;

};

#endif // DOCENTESORDENA_H
