#include "docentesordena.h"

docentesOrdena::docentesOrdena(const std::vector<docentes> &arrayDocentes, const docentesComparador &    comparador): arrayDocentes(arrayDocentes),
    comparador(comparador)
{
}

vector<docentes> docentesOrdena::ordena(){
    vector<docentes>ordenaDocentes = arrayDocentes;// fazendo uma cópia do vetor
    sort(ordenaDocentes.begin(),ordenaDocentes.end(),[&](const docentes &p1,const docentes &p2){
        return comparador.comparar(p1,p2);
    });
    return ordenaDocentes;
}
