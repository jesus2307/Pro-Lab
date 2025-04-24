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
    QVector<Activity> getActivities() const;
    void removeActivity(const QDate& date, int index);
    int countAllActivities() const;
    int countActivitiesByType(const QString& type) const;
private:
    QMap<QDate, QVector<Activity>> log;
};

#endif // ACTIVITYLOG_H
