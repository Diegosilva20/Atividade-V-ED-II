#include "compararpormatricula.h"

compararPorMatricula::compararPorMatricula()
{

}
bool compararPorMatricula::comparar(const docentes &p1,const docentes &p2) const{
    return p1.getMatricula() < p2.getMatricula();
}
