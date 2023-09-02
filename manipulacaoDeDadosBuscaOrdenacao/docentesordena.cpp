#include "docentesordena.h"

docentesOrdena::docentesOrdena(std::vector<docentes> &arrayDocentes, const docentesComparador &    comparador): arrayDocentes(arrayDocentes),
    comparador(comparador)
{
}

std::vector<docentes>& docentesOrdena::ordena(){
    sort(arrayDocentes.begin(),arrayDocentes.end(),[&](const docentes& p1,const docentes& p2){
        return comparador.comparar(p1,p2);
    });
    return arrayDocentes;
}
