#include "activitylog.h"

void ActivityLog::addActivity(const QDate& date, const Activity& activity) {
    if (activity.isValid()) {
        log[date].append(activity);
    }
    // Opcional: si quieres saber que algo salió mal
    // else {
    //     qDebug() << "Actividad inválida no añadida";
    // }
}


QVector<Activity> ActivityLog::getActivitiesForDate(const QDate& date) const {
    return log.value(date);
}

QVector<Activity> ActivityLog::getActivities() const {
    QVector<Activity> allActivities;
    for (const auto& activities : log) {
        allActivities += activities; // concatena cada lista al vector final
    }
    return allActivities;
}
void ActivityLog::removeActivity(const QDate& date, int index) {
    if (log.contains(date) && index >= 0 && index < log[date].size()) {
        log[date].removeAt(index);

        // Si no quedan actividades en esa fecha, eliminamos la fecha del mapa
        if (log[date].isEmpty()) {
            log.remove(date);
        }
    }
}
int ActivityLog::countAllActivities() const {
    int total = 0;
    for (const auto& activities : log) {
        total += activities.size();
    }
    return total;
}
int ActivityLog::countActivitiesByType(const QString& type) const {
    int count = 0;
    for (const auto& activities : log) {
        for (const auto& activity : activities) {
            if (activity.getDescription() == type) {
                ++count;
            }
        }
    }
    return count;
}

