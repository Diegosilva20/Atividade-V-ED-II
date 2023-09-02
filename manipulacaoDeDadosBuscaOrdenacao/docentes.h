#ifndef DOCENTES_H
#define DOCENTES_H
#include <QString>

class docentes
{
public:
    docentes(QString matricula,QString nome,QString departamento,QString titulacao,QString tipoDeContrato);
    docentes();
    ~docentes();
    QString getMatricula() const;

    QString getNome() const;

    QString getDepartamento() const;

    QString getTitulacao() const;

    QString getTipoDeContrato() const;

private:
    QString matricula;
    QString nome;
    QString departamento;
    QString titulacao;
    QString tipoDeContrato;
};

#endif // DOCENTES_H
