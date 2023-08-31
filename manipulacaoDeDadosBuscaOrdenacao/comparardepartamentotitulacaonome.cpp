#include "comparardepartamentotitulacaonome.h"

compararDepartamentoTitulacaoNome::compararDepartamentoTitulacaoNome()
{

}
bool compararDepartamentoTitulacaoNome::comparar(const docentes &p1,const docentes &p2) const{
    if(p1.getDepartamento() != p2.getDepartamento()){
        return p1.getDepartamento() < p2.getDepartamento();
    }
    else{
        if(p1.getTitulacao() != p2.getTitulacao())
            return p1.getTitulacao() < p2.getTitulacao();
        else
            return p1.getNome() < p2.getNome();
    }
}
