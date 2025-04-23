#include <QMessageBox>
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    updateActivityList(ui->dateEdit->date());
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_addButton_clicked() {
    QString desc = ui->descriptionEdit->text();
    QTime start = ui->startTimeEdit->time();
    QTime end = ui->endTimeEdit->time();
    QDate date = ui->dateEdit->date();

    if (desc.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "Description cannot be empty!");
        return;
    }
    if (start >= end) {
        QMessageBox::warning(this, "Time Error", "End time must be after start time!");
        return;
    }
    

    Activity activity(desc, start, end);
    activityLog.addActivity(date, activity);
    updateActivityList(date);

     ui->descriptionEdit->clear();
     ui->startTimeEdit->setTime(QTime(0, 0));
     ui->endTimeEdit->setTime(QTime(0, 0));
      
}

void MainWindow::on_dateEdit_userDateChanged(const QDate &date) {
    updateActivityList(date);
}

void MainWindow::updateActivityList(const QDate& date) {
    ui->activityListWidget->clear();
    for (const Activity& a : activityLog.getActivitiesForDate(date)) {
        ui->activityListWidget->addItem(
            QString("%1 | %2 - %3")
            .arg(a.getDescription())
            .arg(a.getStartTime().toString("hh:mm"))
            .arg(a.getEndTime().toString("hh:mm"))
        );
    }
}
/*Cuando haces clic en "Añadir":
Recoge los datos escritos (descripción, hora inicio y fin),
Crea un Activity,
Lo añade al ActivityLog,
Actualiza la lista visible.
Cuando haces clic en "Exportar":
Abre una ventana para guardar el archivo CSV,
Llama a exportToCSV,
Muestra un mensaje de éxito o error.

*/