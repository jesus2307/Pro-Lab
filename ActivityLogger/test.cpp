
#include <gtest/gtest.h>
#include "activity.h"
#include "activitylog.h"

TEST(ActivityTest, Creation) {
    Activity act("Estudiar", QTime(10, 0), QTime(11, 0));
    EXPECT_EQ(act.getDescription().toStdString(), "Estudiar");
    EXPECT_EQ(act.getStartTime(), QTime(10, 0));
    EXPECT_EQ(act.getEndTime(), QTime(11, 0));
}

TEST(ActivityLogTest, AddAndRetrieveActivity) {
    ActivityLog log;
    QDate date = QDate::currentDate();
    Activity act("Leer", QTime(9, 0), QTime(10, 0));

    log.addActivity(date, act);

    auto activities = log.getActivitiesForDate(date);
    ASSERT_EQ(activities.size(), 1);
    EXPECT_EQ(activities[0].getDescription().toStdString(), "Leer");
    EXPECT_EQ(activities[0].getStartTime(), QTime(9, 0));
    EXPECT_EQ(activities[0].getEndTime(), QTime(10, 0));
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
