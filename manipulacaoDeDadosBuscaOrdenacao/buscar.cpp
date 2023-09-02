#include "buscar.h"

buscar::buscar()
{

}
docentes buscar::buscaSequencialNome(const std::vector<docentes>&vetor,QString dado){
    int tam = vetor.size();
    for(int i = 0;i < tam && dado >= vetor[i].getNome();i++){
        if(vetor[i].getNome() == dado)
            return vetor[i];
    }
    return docentes();// retornando objeto vazio;
}
docentes buscar::buscaSequencialMatricula(const std::vector<docentes>&vetor,QString dado){
    int tam = vetor.size();
    for(int i = 0;i < tam && dado >= vetor[i].getMatricula();i++){
        if(vetor[i].getMatricula() == dado)
            return vetor[i];
    }
    return docentes();// retornando objeto vazio;
}
docentes buscar::buscaBinariaNome(const std::vector<docentes>&vetor,QString dado){
    int tam = vetor.size();
    int inicio = 0,final = tam -1,medio;
    while(inicio <= final){
        medio = (inicio+final)/2;
        if(vetor[medio].getNome() == dado)
            return vetor[medio];
        if(vetor[medio].getNome() < dado)
            final = medio -1;
        else
            inicio = medio + 1;
    }
    return docentes();// retornando objeto vazio;
}

docentes buscar::buscaBinariaMatricula(const std::vector<docentes>&vetor,QString dado){
    int tam = vetor.size();
    int inicio = 0,final = tam -1,medio;
    while(inicio <= final){
        medio = (inicio+final)/2;
        if(vetor[medio].getMatricula() == dado)
            return vetor[medio];
        if(vetor[medio].getMatricula() < dado)
            final = medio -1;
        else
            inicio = medio + 1;
    }
    return docentes();// retornando objeto vazio;
}
