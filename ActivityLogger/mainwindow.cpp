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
// Slot que se ejecuta cuando se pulsa el botón "Añadir".
// Recoge los datos introducidos por el usuario, valida la actividad y la añade al registro si es válida. Luego actualiza la lista mostrada.
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
// Slot que se ejecuta cuando el usuario cambia la fecha del selector.
// Actualiza la lista de actividades que se muestran en pantalla.
void MainWindow::on_dateEdit_userDateChanged(const QDate &date) {
    updateActivityList(date);
}
// Función privada que actualiza el listado de actividades en función de la fecha seleccionada.
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
// Slot que se ejecuta cuando se pulsa el botón "Mostrar todas".
// Muestra todas las actividades, independientemente de la fecha.
void MainWindow::on_showAllButton_clicked() {
    ui->activityListWidget->clear();
    QVector<Activity> allActivities = activityLog.getActivities();

    for (const Activity& a : allActivities) {
        ui->activityListWidget->addItem(
            QString("%1 | %2 - %3")
            .arg(a.getDescription())
            .arg(a.getStartTime().toString("hh:mm"))
            .arg(a.getEndTime().toString("hh:mm"))
        );
    }
}
// Slot que se ejecuta cuando se pulsa el botón "Eliminar".
// Elimina la actividad seleccionada en la lista para la fecha actual.
void MainWindow::on_deleteButton_clicked() {
    int index = ui->activityListWidget->currentRow();
    QDate date = ui->dateEdit->date();

    if (index >= 0) {
        activityLog.removeActivity(date, index);
        updateActivityList(date);
    } else {
        QMessageBox::warning(this, "Selecciona una actividad", "Selecciona una actividad para eliminarla.");
    }
}
// Slot que se ejecuta cuando se pulsa el botón "Contar todas".
// Muestra el número total de actividades registradas.
void MainWindow::on_countAllButton_clicked() {
    int total = activityLog.countAllActivities();
    QMessageBox::information(this, "Total de actividades",
                             QString("Hay un total de %1 actividades registradas.").arg(total));
}
// Slot que se ejecuta al pulsar el botón "Contar por tipo".
// Muestra el número de actividades que coinciden con el tipo introducido.
void MainWindow::on_countByTypeButton_clicked() {
    QString type = ui->typeLineEdit->text();

    if (type.isEmpty()) {
        QMessageBox::warning(this, "Error", "Introduce un tipo de actividad.");
        return;
    }

    int count = activityLog.countActivitiesByType(type);
        QMessageBox::information(this, "Cantidad por tipo",
                             QString("Hay %1 actividades del tipo '%2'.").arg(count).arg(type));
}
