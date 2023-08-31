#include "docentes.h"

docentes::docentes(QString matricula, QString nome, QString departamento, QString titulacao, QString tipoDeContrato) :
    matricula(matricula),nome(nome),departamento(departamento),titulacao(titulacao),tipoDeContrato(tipoDeContrato)
{

}

docentes::~docentes(){}

QString docentes::getMatricula() const
{
    return matricula;
}

QString docentes::getNome() const
{
    return nome;
}

QString docentes::getDepartamento() const
{
    return departamento;
}

QString docentes::getTitulacao() const
{
    return titulacao;
}

QString docentes::getTipoDeContrato() const
{
    return tipoDeContrato;
}
