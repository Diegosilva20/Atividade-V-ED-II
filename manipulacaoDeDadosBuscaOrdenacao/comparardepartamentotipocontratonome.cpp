#include "comparardepartamentotipocontratonome.h"

compararDepartamentoTipoContratoNome::compararDepartamentoTipoContratoNome()
{

}
bool compararDepartamentoTipoContratoNome::comparar(const docentes &p1,const docentes &p2) const{
    if(p1.getDepartamento() != p2.getDepartamento()){
        return p1.getDepartamento() < p2.getDepartamento();
    }
    else{
        if(p1.getTipoDeContrato() != p2.getTipoDeContrato())
            return p1.getTipoDeContrato() < p2.getTipoDeContrato();
        else
            return p1.getNome() < p2.getNome();
    }
}
