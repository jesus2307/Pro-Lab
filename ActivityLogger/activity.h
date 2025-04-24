#ifndef ACTIVITY_H
#define ACTIVITY_H

#include <QString>
#include <QTime>

class Activity {
public:
    Activity(const QString& description, const QTime& start, const QTime& end);

    QString getDescription() const;
    QTime getStartTime() const;
    QTime getEndTime() const;

private:
    QString description;
    QTime startTime;
    QTime endTime;
};

#endif // ACTIVITY_H


/*
Guarda los datos de una actividad: descripción, hora de inicio y hora de fin.
Tiene tres getters (getDescription, getStartTime, getEndTime) para acceder a esos datos.*/