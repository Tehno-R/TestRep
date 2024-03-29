#include "marketwindow.h"
#include "ui_marketwindow.h"
#include <fstream>
#include <QDebug>
#include <QFile>

MarketWindow::MarketWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MarketWindow)
{
    ui->setupUi(this);
    drawProduct();
}

MarketWindow::~MarketWindow()
{
    delete ui;
}

void MarketWindow::setUserName(const QString &_userName)
{
    userName = _userName;
}

void MarketWindow::drawProduct()
{
    readFile();

    QStandardItemModel* model = new QStandardItemModel(this);

    QStringList nameColumn = {"Название" , "Количество" , "Цена" , "В корзине"};
    model->setHorizontalHeaderLabels(nameColumn);

    ui->tableView->setModel(model);

    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers); //блокировка возможности изменения ячеек внутри приложения
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch); //растягивает коллонки под размер таблицы

    QList<QStandardItem*>list;
    for(auto i : products){
        list.append(new QStandardItem(i.getName()));
        list.append(new QStandardItem(QString::number(i.getCount())));
        list.append(new QStandardItem(QString::number(i.getPrice())));
        list.append(new QStandardItem(QString::number(0)));
        model->appendRow(list);
        list.clear();
    }

    connect(ui->tableView, SIGNAL(clicked(QModelIndex)), this, SLOT(addProductInList(QModelIndex)));
}

void MarketWindow::readFile()
{
    QFile file(":/available/product.txt");
    if(file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        while(!file.atEnd()){
            QString str = file.readLine();
            Product product;

            QString name = str.left(str.indexOf(" - "));
            str = str.right(str.size() - str.indexOf(" - ") - 3);
            product.setName(name);

            product.setCount(str.left(str.indexOf(" | ")).toUInt());
            str = str.right(str.size() - str.indexOf(" | ") - 3);

            product.setPrice(str.toUInt());

            products.append(product);
        }
    }
    else{
        qDebug() << "file don't open";
    }
    file.close();
}

void MarketWindow::clearBacket()
{
    backet.clear();
}

void MarketWindow::clearColumnBacket()
{
    QAbstractItemModel* model = ui->tableView->model();
    uint columnBacket = 3;
    for(int i=0; i < model->rowCount(); i++){
        QModelIndex index = model->index(i, columnBacket);
        model->setData(index, 0);
    }
}

uint MarketWindow::countBasket(int row)
{
    QAbstractItemModel* model = ui->tableView->model();
    QModelIndex index = model->index(row, 3);
    QVariant data = model->data(index);
    return data.toUInt();
}

void MarketWindow::addProductInList(QModelIndex index){
    QAbstractItemModel* model = ui->tableView->model();
    int row = index.row();
    const int countColumn = 3;
    QStringList list;

    for(int i=0; i < countColumn; i++){
        QModelIndex idx = model->index(row, i);
        QVariant data = model->data(idx);

        list.append(data.toString()); //добавляем в список значение ячейки из строки
        if(i==1 && data.toInt() != 0){
            model->setData(idx, QVariant(data.toInt() - 1)); // -1 у колонки "Количество"
            model->setData(model->index(row, 3), countBasket(row) + 1); // +1 в колонку "В корзине"
        }else if(i == 1 && data.toInt() == 0)
            return;
    }

    Product p(list.at(0), list.at(2).toUInt());
    backet[p]++;

    qDebug() << p.getName() << p.getCount() << p.getPrice();
    qDebug() << backet[p];
}

void MarketWindow::on_orderButton_clicked()
{
    if(backet.empty())
        return;

    QFile file("C:/Users/nikit/QtProjects/Market/Market/cheque.txt");

    if(file.open(QIODevice::WriteOnly | QIODevice::Text)){
        QTextStream stream(&file);
        stream << "Имя покупателя: "<< userName << "\n";
        unsigned sum = 0;
        for(auto i : backet.keys()){
            QString date = "";
            unsigned price = i.getPrice() * backet[i];
            date = i.getName() + " | кол-во: " + QString::number(backet[i]) + " | Цена: " +
            QString::number(price);
            sum += price;
            stream << date << "\n";
        }
        stream << "Итого: " + QString::number(sum);

        clearColumnBacket();
        clearBacket();
    }
    else{
        //qDebug() << "file don't open!";
        qDebug() << "Error opening file: " << file.errorString();
    }

    file.close();
}
