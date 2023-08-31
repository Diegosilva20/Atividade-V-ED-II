#include "comparartipocontratoandnome.h"

compararTipoContratoAndNome::compararTipoContratoAndNome()
{

}
bool compararTipoContratoAndNome::comparar(const docentes &p1, const docentes &p2) const {
    if(p1.getTipoDeContrato() != p2.getTipoDeContrato())
        return p1.getTipoDeContrato() < p2.getTipoDeContrato();
    return p1.getNome() < p2.getNome();
}
