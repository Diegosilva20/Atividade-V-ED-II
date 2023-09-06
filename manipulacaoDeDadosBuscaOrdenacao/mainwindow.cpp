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

    try {
        ifstream arquivo("C:/Users/dpsil/Downloads/manipulacaoDeDadosBuscaOrdenacao/DocentesEscola.csv");
        if (!arquivo.is_open()) {
            QMessageBox::warning(this, "Erro", "Erro ao abrir arquivo");
        }
        std::string linha = "";
        while (std::getline(arquivo, linha)) {
            QStringList lista = QString::fromStdString(linha).split(';'); // Convertendo string para QString
            // Verificando abaixo se alguma linha do arquivo está com erro
            if (!(lista.value(0).isEmpty() || lista.value(1).isEmpty() || lista.value(2).isEmpty() || lista.value(3).isEmpty() || lista.value(4).isEmpty()) && lista.size() == 5) {
                QString matricula = lista.value(0);
                QString nome = lista.value(1);
                QString departamento = lista.value(2);
                QString titulacao = lista.value(3);
                QString tipoContrato = lista.value(4);
                docentes docente(matricula, nome, departamento, titulacao, tipoContrato);
                arrayDocentes.push_back(docente);
            } else {

            }
        }
        arquivo.close();
    } catch (QString &erro) {
        QMessageBox::information(this, "ERRO", erro);
    }

    imprimirNaTela(arrayDocentes);

}

void MainWindow::imprimirNaTela(vector<docentes>arrayDocentes){
    int tam = arrayDocentes.size();
    for(int i = 0;i < tam;i++){
        itemMatricula = new QStandardItem(arrayDocentes[i].getMatricula());
        itemNome = new QStandardItem(arrayDocentes[i].getNome());
        itemDepartamento = new QStandardItem(arrayDocentes[i].getDepartamento());
        itemTitulacao = new QStandardItem(arrayDocentes[i].getTitulacao());
        itemTipoContrato = new QStandardItem(arrayDocentes[i].getTipoDeContrato());

        model->setItem(i,0,itemMatricula);
        model->setItem(i,1,itemNome);
        model->setItem(i,2,itemDepartamento);
        model->setItem(i,3,itemTitulacao);
        model->setItem(i,4,itemTipoContrato);
    }
}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_comboBoxOrdenacao_currentIndexChanged(int index)
{
    if(index == 1){
        docentesOrdena ordena(arrayDocentes,CompararPorMatricula);
        arrayDocentes = ordena.ordena();
        imprimirNaTela(arrayDocentes);
    }
    else{
        if(index == 2){
            docentesOrdena ordena(arrayDocentes,CompararPorNome);
            arrayDocentes = ordena.ordena();
            imprimirNaTela(arrayDocentes);
        }else{
            if(index == 3){
                docentesOrdena ordena(arrayDocentes,DepartamentoNome);
                arrayDocentes = ordena.ordena();
                imprimirNaTela(arrayDocentes);
            }else{
                if(index == 4){
                    docentesOrdena ordena(arrayDocentes,CompararTitulacaoNome);
                    arrayDocentes = ordena.ordena();
                    imprimirNaTela(arrayDocentes);
                }else{
                    if(index == 5){
                        docentesOrdena ordena(arrayDocentes,CompararTipoContratoNome);
                        arrayDocentes = ordena.ordena();
                        imprimirNaTela(arrayDocentes);
                    }else{
                        if(index == 6){
                            docentesOrdena ordena(arrayDocentes,DepartamentoTitulacaoNome);
                            arrayDocentes = ordena.ordena();
                            imprimirNaTela(arrayDocentes);
                        }else{
                            docentesOrdena ordena(arrayDocentes,DepartamentoTpNome);
                            arrayDocentes = ordena.ordena();
                            imprimirNaTela(arrayDocentes);
                        }
                    }
                }
            }
        }
    }
 }


void MainWindow::on_pushButtonBuscar_clicked()
{
    QString opcao = ui->comboBoxBusca->currentText();
    if(opcao == "Busca Sequencial  - Nome"){
        try {
            docentesOrdena ordena(arrayDocentes,CompararPorNome);
            arrayDocentes = ordena.ordena();
            if(ui->lineEditDado->text().isEmpty()) throw QString("Digite o nome que seja buscar");
            obj = busca.buscaSequencialNome(arrayDocentes,ui->lineEditDado->text());
            //if(obj.getNome().isEmpty())throw QString("Professor não existente na base de dados");
            if (model) {
                model->removeRows(0, model->rowCount()); // Remove todas as linhas da tabela.
            }
            itemMatricula = new QStandardItem(obj.getMatricula());
            itemNome = new QStandardItem(obj.getNome());
            itemDepartamento = new QStandardItem(obj.getDepartamento());
            itemTitulacao = new QStandardItem(obj.getTitulacao());
            itemTipoContrato = new QStandardItem(obj.getTipoDeContrato());

            model->setItem(0,0,itemMatricula);
            model->setItem(0,1,itemNome);
            model->setItem(0,2,itemDepartamento);
            model->setItem(0,3,itemTitulacao);
            model->setItem(0,4,itemTipoContrato);
        } catch (QString &erro) {
            QMessageBox::information(this,"ERRO",erro);
        }

    }else{
        if(opcao == "Busca Sequencial - Matricula"){
            try {
                docentesOrdena ordena(arrayDocentes,CompararPorMatricula);
                arrayDocentes = ordena.ordena();
                if(ui->lineEditDado->text().isEmpty()) throw QString("Digite o nome que seja buscar");
                obj = busca.buscaSequencialMatricula(arrayDocentes,ui->lineEditDado->text());
                if (model) {
                    model->removeRows(0, model->rowCount()); // Remove todas as linhas da tabela.
                }
                itemMatricula = new QStandardItem(obj.getMatricula());
                itemNome = new QStandardItem(obj.getNome());
                itemDepartamento = new QStandardItem(obj.getDepartamento());
                itemTitulacao = new QStandardItem(obj.getTitulacao());
                itemTipoContrato = new QStandardItem(obj.getTipoDeContrato());

                model->setItem(0,0,itemMatricula);
                model->setItem(0,1,itemNome);
                model->setItem(0,2,itemDepartamento);
                model->setItem(0,3,itemTitulacao);
                model->setItem(0,4,itemTipoContrato);
            } catch (QString &erro) {
                  QMessageBox::information(this,"ERRO",erro);
            }
        }
        else{
            if(opcao == "Busca Binária - Nome"){
                try {
                    docentesOrdena ordena(arrayDocentes,CompararPorNome);
                    arrayDocentes = ordena.ordena();
                    if(ui->lineEditDado->text().isEmpty()) throw QString("Digite o nome que seja buscar");
                    obj = busca.buscaBinariaNome(arrayDocentes,ui->lineEditDado->text());
                    if (model) {
                        model->removeRows(0, model->rowCount()); // Remove todas as linhas da tabela.
                    }
                    itemMatricula = new QStandardItem(obj.getMatricula());
                    itemNome = new QStandardItem(obj.getNome());
                    itemDepartamento = new QStandardItem(obj.getDepartamento());
                    itemTitulacao = new QStandardItem(obj.getTitulacao());
                    itemTipoContrato = new QStandardItem(obj.getTipoDeContrato());

                    model->setItem(0,0,itemMatricula);
                    model->setItem(0,1,itemNome);
                    model->setItem(0,2,itemDepartamento);
                    model->setItem(0,3,itemTitulacao);
                    model->setItem(0,4,itemTipoContrato);
                } catch (QString &erro) {
                    QMessageBox::information(this,"ERRO",erro);
                }
            }else{
                try {
                    docentesOrdena ordena(arrayDocentes,CompararPorMatricula);
                    arrayDocentes = ordena.ordena();
                    if(ui->lineEditDado->text().isEmpty()) throw QString("Digite o nome que seja buscar");
                    obj = busca.buscaBinariaMatricula(arrayDocentes,ui->lineEditDado->text());
                    if (model){
                        model->removeRows(0, model->rowCount()); // Remove todas as linhas da tabela.
                    }
                    itemMatricula = new QStandardItem(obj.getMatricula());
                    itemNome = new QStandardItem(obj.getNome());
                    itemDepartamento = new QStandardItem(obj.getDepartamento());
                    itemTitulacao = new QStandardItem(obj.getTitulacao());
                    itemTipoContrato = new QStandardItem(obj.getTipoDeContrato());

                    model->setItem(0,0,itemMatricula);
                    model->setItem(0,1,itemNome);
                    model->setItem(0,2,itemDepartamento);
                    model->setItem(0,3,itemTitulacao);
                    model->setItem(0,4,itemTipoContrato);
                } catch (QString &erro) {
                    QMessageBox::information(this,"ERRO",erro);
                }
            }
        }

    }
}



