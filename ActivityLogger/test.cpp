#include <gtest/gtest.h>
#include "activity.h"
#include "activitylog.h"
// Test que comprueba la correcta creación de un objeto Activity.
// Verifica que la descripción, la hora de inicio y la de fin se guardan correctamente.
TEST(ActivityTest, Creation) {
    Activity act("Estudiar", QTime(10, 0), QTime(11, 0));
    EXPECT_EQ(act.getDescription().toStdString(), "Estudiar");
    EXPECT_EQ(act.getStartTime(), QTime(10, 0));
    EXPECT_EQ(act.getEndTime(), QTime(11, 0));
}
// Test que comprueba que se puede añadir una actividad a un día concreto
// y luego recuperarla correctamente usando getActivitiesForDate.
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
// Test que comprueba que getActivities devuelve todas las actividades de todos los días.
TEST(ActivityLogTest, GetAllActivities) {
    ActivityLog log;
    QDate date = QDate::currentDate();

    Activity a1("Correr", QTime(10, 0), QTime(10, 30));
    Activity a2("Nadar", QTime(11, 0), QTime(11, 45));
    log.addActivity(date, a1);
    log.addActivity(date, a2);

    QVector<Activity> all = log.getActivities();
    EXPECT_EQ(all.size(), 2);
}
// Test que comprueba que se puede eliminar una actividad por índice y que después no queda ninguna actividad en esa fecha.
TEST(ActivityLogTest, RemoveActivity) {
    ActivityLog log;
    QDate date = QDate::currentDate();

    Activity a1("Correr", QTime(8, 0), QTime(8, 30));
    log.addActivity(date, a1);
    log.removeActivity(date, 0);

    QVector<Activity> remaining = log.getActivitiesForDate(date);
    EXPECT_TRUE(remaining.isEmpty());
}
// Test que comprueba que countAllActivities devuelve correctamente el número total de actividades registradas.
TEST(ActivityLogTest, CountAllActivities) {
    ActivityLog log;
    QDate date = QDate::currentDate();

    log.addActivity(date, Activity("Correr", QTime(7, 0), QTime(7, 30)));
    log.addActivity(date, Activity("Nadar", QTime(8, 0), QTime(8, 45)));
    EXPECT_EQ(log.countAllActivities(), 2);
}

// Test que comprueba que countActivitiesByType devuelve correctamente el número de actividades de un tipo concreto.
TEST(ActivityLogTest, CountActivitiesByType) {
    ActivityLog log;
    QDate date = QDate::currentDate();

    log.addActivity(date, Activity("Correr", QTime(6, 0), QTime(6, 30)));
    log.addActivity(date, Activity("Nadar", QTime(7, 0), QTime(7, 45)));
    log.addActivity(date, Activity("Correr", QTime(8, 0), QTime(8, 30)));

    EXPECT_EQ(log.countActivitiesByType("Correr"), 2);
    EXPECT_EQ(log.countActivitiesByType("Nadar"), 1);
}
// Test que comprueba la función isValid de la clase Activity:
// - Una actividad con datos correctos debe ser válida.
// - Una con descripción vacía o misma hora de inicio y fin debe ser inválida.
TEST(ActivityTest, ValidateActivity) {
    Activity valid("Correr", QTime(9, 0), QTime(10, 0));
    Activity invalidEmptyType("", QTime(9, 0), QTime(10, 0));
    Activity invalidDuration("Nadar", QTime(10, 0), QTime(10, 0));

    EXPECT_TRUE(valid.isValid());
    EXPECT_FALSE(invalidEmptyType.isValid());
    EXPECT_FALSE(invalidDuration.isValid());
}

// Función principal que lanza todos los tests definidos usando Google Test.
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
