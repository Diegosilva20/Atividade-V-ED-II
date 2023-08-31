#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    model = new QStandardItemModel(this);
    model->setColumnCount(5); //nº de colunas
    // colocando o titulo das tabelas
    model->setHeaderData(0,Qt::Horizontal,"Matricula");
    model->setHeaderData(1,Qt::Horizontal,"Nome");
    model->setHeaderData(2,Qt::Horizontal,"Departamento");
    model->setHeaderData(3,Qt::Horizontal,"Titulação");
    model->setHeaderData(4,Qt::Horizontal,"Tipo de Contato");

    tableView = ui->tableView;
    tableView->setModel(model);
    tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    tableView->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);

    readCsv a("C:/Users/dpsil/Downloads/manipulacaoDeDadosBuscaOrdenacao/DocentesEscola.csv");
    arrayDocentes = a.lerArquivo();//pegando o vetor de objetos com os dados do arquivo
    int tam = arrayDocentes.size();
    // colocando os dados na Qtable
    for(int i = 0;i < tam;i++){
        QString matricula = arrayDocentes[i].getMatricula();
        QString nome = arrayDocentes[i].getNome();
        QString departamento = arrayDocentes[i].getDepartamento();
        QString titulacao = arrayDocentes[i].getTitulacao();
        QString tipoContrato = arrayDocentes[i].getTipoDeContrato();

        QStandardItem* itemMatricula = new QStandardItem(matricula);
        QStandardItem* itemNome = new QStandardItem(nome);
        QStandardItem* itemDepartamento = new QStandardItem(departamento);
        QStandardItem* itemTitulacao = new QStandardItem(titulacao);
        QStandardItem* itemTipoContrato = new QStandardItem(tipoContrato);

        model->setItem(i,0,itemMatricula);
        model->setItem(i,1,itemNome);
        model->setItem(i,2,itemDepartamento);
        model->setItem(i,3,itemTitulacao);
        model->setItem(i,4,itemTipoContrato);
    }
    //connect(ui.comboBox, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &SeuFormulario::onComboBoxIndexChanged);

}

MainWindow::~MainWindow()
{
    delete ui;
}





void MainWindow::on_comboBoxOrdenacao_currentIndexChanged(int index)
{
    switch(index){
        case 1:
        compararPorNome CompararPorNome;
        docentesOrdena ordenarPorNome(arrayDocentes,CompararPorNome);
        vector<docentes> arrayOrdenadoPorNome = ordenarPorNome.ordena();
        int tam = arrayOrdenadoPorNome.size();
        // colocando os dados na Qtable
        for(int i = 0;i < tam;i++){
            QString matricula = arrayOrdenadoPorNome[i].getMatricula();
            QString nome = arrayOrdenadoPorNome[i].getNome();
            QString departamento = arrayOrdenadoPorNome[i].getDepartamento();
            QString titulacao = arrayOrdenadoPorNome[i].getTitulacao();
            QString tipoContrato = arrayOrdenadoPorNome[i].getTipoDeContrato();

            QStandardItem* itemMatricula = new QStandardItem(matricula);
            QStandardItem* itemNome = new QStandardItem(nome);
            QStandardItem* itemDepartamento = new QStandardItem(departamento);
            QStandardItem* itemTitulacao = new QStandardItem(titulacao);
            QStandardItem* itemTipoContrato = new QStandardItem(tipoContrato);

            model->setItem(i,0,itemMatricula);
            model->setItem(i,1,itemNome);
            model->setItem(i,2,itemDepartamento);
            model->setItem(i,3,itemTitulacao);
            model->setItem(i,4,itemTipoContrato);
        }
        break;
    }
}

