#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableView>
#include <QStandardItemModel>
#include <vector>
#include <fstream>
#include <iostream>
#include <QMessageBox>
#include "readcsv.h"
#include "docentes.h"
#include "docentes.h"
#include "docentescomparador.h"
#include "docentesordena.h"
#include "compararpornome.h"
#include "compararpormatricula.h"
#include "comparardepartamentotipocontratonome.h"
#include "comparardepartamentotitulacaonome.h"
#include "compararpordepartamentoandnome.h"
#include "comparartipocontratoandnome.h"
#include "comparartitulacaoandnome.h"
#include "buscar.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_comboBoxOrdenacao_currentIndexChanged(int index);

    void on_pushButtonBuscar_clicked();


private:
    Ui::MainWindow *ui;
    QStandardItemModel *model;
    QTableView *tableView;
    std::vector<docentes> arrayDocentes;
    QStandardItem* itemMatricula = nullptr;
    QStandardItem* itemNome = nullptr;
    QStandardItem* itemDepartamento = nullptr;
    QStandardItem* itemTitulacao = nullptr;
    QStandardItem* itemTipoContrato = nullptr;
    compararPorNome CompararPorNome;
    compararPorMatricula CompararPorMatricula;
    compararTitulacaoAndNome CompararTitulacaoNome;
    compararTipoContratoAndNome CompararTipoContratoNome;
    compararPorDepartamentoAndNome DepartamentoNome;
    compararDepartamentoTitulacaoNome DepartamentoTitulacaoNome;
    compararDepartamentoTipoContratoNome DepartamentoTpNome;
    buscar busca;
};
#endif // MAINWINDOW_H
