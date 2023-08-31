#include "compararpornome.h"
#include "docentescomparador.h"
compararPorNome::compararPorNome()
{

}

bool compararPorNome::comparar(const docentes &p1,const docentes &p2) const{
    return p1.getNome() < p2.getNome();
}
