#include "activitylog.h"

void ActivityLog::addActivity(const QDate& date, const Activity& activity) {
    log[date].append(activity);
}

QVector<Activity> ActivityLog::getActivitiesForDate(const QDate& date) const {
    return log.value(date);
}

/*Guarda una lista de actividades (QList<Activity>).
Puedes añadir una nueva actividad con addActivity.
Puedes obtener la lista con getActivities.
*/