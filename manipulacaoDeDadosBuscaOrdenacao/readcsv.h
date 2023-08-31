#ifndef READCSV_H
#define READCSV_H
#include <QString>
#include <vector>
#include "docentes.h"
class readCsv
{
public:
    readCsv(const std::string &nomeArquivo);
    ~readCsv();
    std::vector<docentes>lerArquivo();
    std::vector<docentes>getArrayDocentes();
private:
    std::string nomeArquivo;
    std::vector<docentes>arrayDocentes;
};

#endif // READCSV_H
