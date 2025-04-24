#include "activitylog.h"

void ActivityLog::addActivity(const QDate& date, const Activity& activity) {
    if (activity.isValid()) {
        log[date].append(activity);
    }
    // si quieres saber que algo salió mal
    // else {
    //     qDebug() << "Actividad inválida no añadida";
    // }
}

// Devuelve todas las actividades almacenadas para una fecha específica.
// Si no hay actividades en esa fecha, devuelve un vector vacío.
QVector<Activity> ActivityLog::getActivitiesForDate(const QDate& date) const {
    return log.value(date);
}
// Devuelve una lista completa con todas las actividades registradas, sin importar la fecha.
// Se concatenan todas las listas de cada día en un único vector.
QVector<Activity> ActivityLog::getActivities() const {
    QVector<Activity> allActivities;
    for (const auto& activities : log) {
        allActivities += activities; // concatena cada lista al vector final
    }
    return allActivities;
}
// Elimina una actividad por índice en una fecha determinada.
// Si el índice es válido, se elimina; si la fecha queda vacía tras eliminar, se borra del mapa.
void ActivityLog::removeActivity(const QDate& date, int index) {
    if (log.contains(date) && index >= 0 && index < log[date].size()) {
        log[date].removeAt(index);
        // Si no quedan actividades en esa fecha, eliminamos la fecha del mapa
        if (log[date].isEmpty()) {
            log.remove(date);
        }
    }
}
// Cuenta el número total de actividades registradas en todas las fechas.
int ActivityLog::countAllActivities() const {
    int total = 0;
    for (const auto& activities : log) {
        total += activities.size();
    }
    return total;
}
// Cuenta cuántas actividades hay de un tipo específico (según la descripción).
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

