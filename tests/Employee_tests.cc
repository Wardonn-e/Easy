#include <gtest/gtest.h>
#include <class/Workers.h>

using namespace workers;
using namespace std;

TEST(EmployeeTests, calculating_salary_full_time) {
    const auto worker = make_shared<FullEmployee>("Василий", "Васильев", "Васильевич", 13, 12, 2003, 54000);
    float result = worker->calculating_salary();
    EXPECT_EQ(result, 59130);
}TEST(EmployeeTests, calculating_salary_full_time2) {
    const auto worker = make_shared<FullEmployee>("Василий", "Васильев", "Васильевич", 7, 9, 1995, 37000);
    float result = worker->calculating_salary();
    EXPECT_EQ(result, 41995);
}
TEST(EmployeeTests, calculating_salary_full_time3) {
    const auto worker = make_shared<FullEmployee>("Василий", "Васильев", "Васильевич", 7, 9, 1955, 37777);
    double result = worker->calculating_salary();
    EXPECT_NEAR(result, 50432.3, 0.1);
}
TEST(EmployeeTests, calculating_salary_part_time) {
    const auto worker = make_shared<PartEmployee>("Василий", "Васильев", "Васильевич", 13, 12, 2003, 400, 5, 80);
    float result = worker->calculating_salary();
    EXPECT_EQ(result, 33600);
}
TEST(EmployeeTests, calculating_salary_part_time2) {
    const auto worker = make_shared<PartEmployee>("Василий", "Васильев", "Васильевич", 13, 12, 2013, 700, 3, 40);
    float result = worker->calculating_salary();
    EXPECT_EQ(result, 28840);
}
TEST(EmployeeTests, calculating_salary_part_time3) {
    const auto worker = make_shared<PartEmployee>("Василий", "Васильев", "Васильевич", 13, 12, 2013, 700, 3, 0);
    float result = worker->calculating_salary();
    EXPECT_EQ(result, 0);
}
TEST(EmployeeTests, calculating_salary_part_time4) {
    const auto worker = make_shared<PartEmployee>("Василий", "Васильев", "Васильевич", 13, 12, 2013, 333, 3, 33);
    float result = worker->calculating_salary();
    EXPECT_NEAR(result, 11318.67, 0.1);
}
