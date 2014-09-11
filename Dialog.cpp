
#include <QMessageBox>
#include "Dialog.h"
#include "ui_Dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_resultButton_clicked()
{
    bool ok;

    int a = ui->aLineEdit->text().toInt( &ok );
    if ( !ok ) {
        QMessageBox::information( this, tr( "Ошибка" ), tr( "Вы ввели некорректные данные" ) );
        return;
    }

    int b = ( a / 100 ) * 10 + a % 10;

    ui->bLineEdit->setText( QString::number( b ) );
}
