#include "compararpordepartamentoandnome.h"

compararPorDepartamentoAndNome::compararPorDepartamentoAndNome()
{

}
bool compararPorDepartamentoAndNome::comparar(const docentes &p1,const docentes &p2) const{
    if(p1.getDepartamento() != p2.getDepartamento())
        return p1.getDepartamento() < p2.getDepartamento();
    return p1.getNome() < p2.getNome();
}
