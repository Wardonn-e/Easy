#include <gtest/gtest.h>
#include <class/Workers.h>

using namespace workers;
using namespace std;

TEST(EmployeesTests, addPerson1)
{
    Employees _worker;
    _worker.add_worker(make_shared<PartEmployee>("Иван", "Иванов", "Иванович", 13, 12, 2003, 400, 5, 80));

    EXPECT_EQ(_worker.size(), 1);
}
TEST(EmployeesTests, addPerson2)
{
    Employees _worker;
    _worker.add_worker(make_shared<PartEmployee>("Иван", "Иванов", "Иванович", 13, 12, 2003, 400, 5, 80));
    _worker.add_worker(make_shared<PartEmployee>("Иван", "Иванов", "Иванович", 13, 12, 2003, 400, 5, 80));
    _worker.add_worker(make_shared<PartEmployee>("Иван", "Иванов", "Иванович", 13, 12, 2003, 400, 5, 80));
    _worker.add_worker(make_shared<PartEmployee>("Иван", "Иванов", "Иванович", 13, 12, 2003, 400, 5, 80));

    EXPECT_EQ(_worker.size(), 4);
}
TEST(EmployeesTests, deletePersonGood1)
{
    Employees _worker;
    _worker.add_worker(make_shared<PartEmployee>("Иван", "Иванов", "Иванович", 13, 12, 2003, 400, 5, 80));
    _worker.add_worker(make_shared<PartEmployee>("Иван", "Иванов", "Иванович", 13, 12, 2003, 400, 5, 80));
    _worker.delete_person(0);

    EXPECT_EQ(_worker.size(), 1);
}
TEST(EmployeesTests, deletePersonGood2)
{
    Employees _worker;
    _worker.add_worker(make_shared<PartEmployee>("Иван", "Иванов", "Иванович", 13, 12, 2003, 400, 5, 80));

    EXPECT_NO_THROW(_worker.delete_person(0), std::out_of_range);
}
/*TEST(EmployeesTests, deletePersonаFailed)
{
    Employees _worker;
    _worker.add_worker(make_shared<PartEmployee>("Иван", "Иванов", "Иванович", 13, 12, 2003, 400, 5, 80));

    EXPECT_ANY_THROW(_worker.delete_person(0), std::out_of_range);
}*/
// Эта проверка выдает FALSE умышленно, проверка на выбрасывание исключения
TEST(EmployeesTests, insertPerson1)
{
    Employees _worker;
    _worker.add_worker(make_shared<FullEmployee>("Иван", "Иванов", "Иванович", 13, 12, 2003, 54000));
    _worker.insert_person(make_shared<PartEmployee>("Иван", "Иванов", "Иванович", 13, 12, 2013, 700, 3, 40), 0);

    EXPECT_EQ(_worker[0]->get_year(), 2013);
}
TEST(EmployeesTests, insertPerson2)
{
    Employees _worker;
    _worker.add_worker(make_shared<FullEmployee>("Иван", "Иванов", "Иванович", 13, 12, 2003, 54000));
    _worker.add_worker(make_shared<PartEmployee>("Иван", "Иванов", "Иванович", 13, 12, 2013, 700, 3, 40));
    _worker.insert_person(make_shared<PartEmployee>("Иван", "Иванов", "Иванович", 13, 12, 2013, 700, 3, 40), 1);

    EXPECT_EQ(_worker[0]->get_year(), 2003);
    EXPECT_EQ(_worker[1]->get_year(), 2013);
}
TEST(EmployeesTests, search_max_salary1)
{
    Employees _worker;
    _worker.add_worker(make_shared<FullEmployee>("Иван", "Иванов", "Иванович", 13, 12, 2003, 54000));
    _worker.add_worker(make_shared<PartEmployee>("Иван", "Иванов", "Иванович", 13, 12, 2013, 700, 3, 40));
    _worker.add_worker(make_shared<FullEmployee>("Иван", "Иванов", "Иванович", 13, 12, 2013, 20000));

    ASSERT_EQ(search_max_salary(_worker), 0);
}
TEST(EmployeesTests, search_max_salary2)
{
    Employees _worker;
    _worker.add_worker(make_shared<FullEmployee>("Иван", "Иванов", "Иванович", 13, 12, 2003, 54000));
    _worker.add_worker(make_shared<PartEmployee>("Иван", "Иванов", "Иванович", 13, 12, 2013, 900, 3, 120));
    _worker.add_worker(make_shared<FullEmployee>("Иван", "Иванов", "Иванович", 13, 12, 2013, 20000));

    ASSERT_EQ(search_max_salary(_worker), 1);
}