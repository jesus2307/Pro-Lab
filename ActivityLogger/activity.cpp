#include "activity.h"

Activity::Activity(const QString& description, const QTime& start, const QTime& end)
    : description(description), startTime(start), endTime(end) {}

QString Activity::getDescription() const { return description; }
QTime Activity::getStartTime() const { return startTime; }
QTime Activity::getEndTime() const { return endTime; }
bool Activity::isValid() const {
    int duration = startTime.secsTo(endTime);
    return !description.isEmpty() && duration > 0;
}

