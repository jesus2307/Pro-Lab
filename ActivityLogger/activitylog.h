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
