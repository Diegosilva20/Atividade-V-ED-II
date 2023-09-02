#include "readcsv.h"
#include <iostream>
#include <fstream>
#include <QMessageBox>
#include "docentes.h"
using namespace std;

readCsv::readCsv(const std::string &nomeArquivo) : nomeArquivo(nomeArquivo)
{
}

readCsv::~readCsv(){

}
std::vector<docentes> readCsv::lerArquivo(){
    try{
        ifstream arquivo(nomeArquivo);
        if(!arquivo.is_open()){
            throw std::runtime_error("ERRO AO ABRIR ARQUIVO");
        }
        std::string linha="";
        while(std::getline(arquivo,linha)){
            QStringList lista = QString::fromStdString(linha).split(';');//convertendo string para QString
            // verificando abaixo se alguma linha do arquivo está com erro
            if(!(lista.value(0).isEmpty()||lista.value(1).isEmpty()||lista.value(2).isEmpty()||lista.value(3).isEmpty()||lista.value(4).isEmpty())){
                QString matricula = lista.value(0);
                QString nome = lista.value(1);
                QString departamento = lista.value(2);
                QString titulacao = lista.value(3);
                QString tipoContrato = lista.value(4);
                docentes docente(matricula,nome,departamento,titulacao,tipoContrato);
                arrayDocentes.push_back(docente);
            }
        }
        arquivo.close();

    } catch(std::bad_alloc &erro){
        std::cerr << "Erro ao alocar memória: " << erro.what() << std::endl;
    }
    return arrayDocentes;
}

