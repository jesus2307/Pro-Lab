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
