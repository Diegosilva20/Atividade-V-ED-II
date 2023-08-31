#include "comparartitulacaoandnome.h"

compararTitulacaoAndNome::compararTitulacaoAndNome()
{

}
bool compararTitulacaoAndNome::comparar(const docentes &p1, const docentes &p2) const {
    if(p1.getTitulacao() != p2.getTitulacao())
        return p1.getTitulacao() < p2.getTitulacao();
    return p1.getNome() < p2.getNome();
}
