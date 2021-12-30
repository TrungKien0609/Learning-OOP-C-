#include <iostream>

class Student
{
private:
    static int startId;
    int studentId;
    std::string studentName;
    int dayOfBirth;
    int monthOfBirth;
    int yearOfBirth;
    float mathResult;
    float englishResult;

public:
    Student()
    {
        this->studentId = startId++;
    }
    Student(const std::string &studentName,
            const int &dayOfBirth, const int &monthOfBirth, const int &yearOfBirth,
            const float &mathResult, const float &englishResult)
    {
        this->studentId = startId++;
        this->studentName = studentName;
        this->dayOfBirth = dayOfBirth;
        this->monthOfBirth = monthOfBirth;
        this->yearOfBirth = yearOfBirth;
        this->mathResult = mathResult;
        this->englishResult = englishResult;
    };
    float average()
    {
        return (this->mathResult + this->englishResult) / 2;
    }
    int getDayOfBirth()
    {
        return this->dayOfBirth;
    }
    int getMonthOfBirth()
    {
        return this->monthOfBirth;
    }
    int getYearOfBirth()
    {
        return this->yearOfBirth;
    }
    float getMathResult()
    {
        return this->mathResult;
    }
    float getEnglishResult()
    {
        return this->englishResult;
    }
    friend std::istream &operator>>(std::istream &is, Student *obj)
    {
        std::cout << "Please fill the name: ";
        std::fflush(stdin);
        std::getline(is, obj->studentName);
        std::cout << "Please fill day of birth: ";
        is >> obj->dayOfBirth;
        std::cout << "Please fill month of birth: ";
        is >> obj->monthOfBirth;
        std::cout << "Please fill year of birth: ";
        is >> obj->yearOfBirth;
        std::cout << "Please fill math result: ";
        is >> obj->mathResult;
        std::cout << "Please fill english result: ";
        is >> obj->englishResult;
        std::cout << "----------------------------------------" << std::endl;
        return is;
    }
    friend std::ostream &operator<<(std::ostream &os, Student *obj)
    {

        std::cout << "Id: " << obj->studentId << std::endl;
        std::cout << "Name: " << obj->studentName << std::endl;
        std::cout << "day: " << obj->dayOfBirth << std::endl;
        std::cout << "month: " << obj->monthOfBirth << std::endl;
        std::cout << "year: " << obj->yearOfBirth << std::endl;
        std::cout << "math result: " << obj->mathResult << std::endl;
        std::cout << "english result: " << obj->englishResult << std::endl;
        std::cout << "-----------------------------------------" << std::endl;
        return os;
    }
    int getStudentId()
    {
        return this->studentId;
    }
};
int Student::startId = 1;
class TestCandidateList
{
private:
    int n;
    Student *list;

public:
    TestCandidateList()
    {
        this->n = 1;
    }
    friend std::istream &operator>>(std::istream &is, TestCandidateList *obj)
    {
        std::cout << "Fill the input of the amount of students:";
        is >> obj->n;
        return is;
    };
    void Create()
    {
        this->list = new Student[this->n];
        for (int i = 0; i < n; i++)
        {
            std::cout << "Student: " << i + 1 << std::endl;
            std::cin >> &this->list[i];
        }
    }
    void show()
    {
        for (int i = 0; i < this->n; i++)
        {
            std::cout << "Information of Student " << i + 1 << std::endl;
            std::cout << &this->list[i];
        }
    }
    void ShowStudents()
    { // show students have average of math and english greater than 1
        for (int i = 0; i < this->n; i++)
        {
            if (this->list[i].average() > 1)
            {
                std::cout << "Information of Student " << i + 1 << std::endl;
                std::cout << &list[i];
            }
        }
    };
};

int main()
{
    TestCandidateList *list = new TestCandidateList;
    std::cin >> list;
    list->Create();
    list->show();
    std::cout << "The number of students have average of math and english greater than 1" << std::endl;
    list->ShowStudents();
    system("pause");
    return 0;
}