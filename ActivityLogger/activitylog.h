#ifndef ACTIVITYLOG_H
#define ACTIVITYLOG_H

#include "activity.h"
#include <QMap>
#include <QDate>
#include <QVector>

class ActivityLog {
public:
    void addActivity(const QDate& date, const Activity& activity);
    QVector<Activity> getActivitiesForDate(const QDate& date) const;

private:
    QMap<QDate, QVector<Activity>> log;
};

#endif // ACTIVITYLOG_H

 /*Define la clase ActivityLog, que:
Guarda actividades agrupadas por fecha (QDate).
Permite añadir una actividad a una fecha con addActivity.
Permite obtener todas las actividades de una fecha con getActivitiesForDate.
Internamente usa un QMap<QDate, QVector<Activity>> log para almacenar todo.*/