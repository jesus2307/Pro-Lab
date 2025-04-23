// mainwindow.h
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDate>
#include "activitylog.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_addButton_clicked();
    void on_dateEdit_userDateChanged(const QDate &date);

private:
    Ui::MainWindow *ui;
    ActivityLog activityLog;
    void updateActivityList(const QDate& date);
};

#endif // MAINWINDOW_H

/*Hereda de QMainWindow, es decir, es una ventana Qt.

Usa la clase ActivityLog para guardar actividades.

Tiene slots (funciones conectadas a botones Qt):

on_addButton_clicked(): cuando el usuario añade una actividad.

on_exportButton_clicked(): cuando exporta a CSV.

updateActivityList() actualiza lo que se muestra en pantalla (la lista de actividades).

*/