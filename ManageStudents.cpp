#include <iostream>
#include <string>
class Student
{
private:
    std::string name, ability;
    int age;
    float weight, height;

public:
    Student()
    {
        this->name = this->ability = "";
        this->age = 0;
        this->weight = this->height = 0;
    }
    Student(std::string name, std::string ability, int age, float weight, float height)
    {
        this->name = name;
        this->age = age;
        this->ability = ability;
        this->weight = weight;
        this->height = height;
    }
    ~Student()
    {
        this->name = this->ability = "";
        this->age = 0;
        this->weight = this->height = 0;
    }
    // Overloading operator >>
    // Dấu &operator dùng đ
    friend std::istream &operator>>(std::istream &is, Student *obj)
    {
        std::cin.ignore();
        std::cout << "Please fill the name:";
        std::fflush(stdin);
        getline(is, obj->name);
        std::cout << "Please fill the ability:";
        std::fflush(stdin);
        getline(is, obj->ability);
        std::cout << "Please fill the age:";
        is >> obj->age;
        std::cout << "Please fill the weight:";
        is >> obj->weight;
        std::cout << "Please fill the height:";
        is >> obj->height;
        return is;
    }
    friend std::ostream &operator<<(std::ostream &os, const Student *obj)
    {
        std::cout << "Name:" << obj->name << std::endl;
        std::cout << "Ability:" << obj->ability << std::endl;
        std::cout << "Age:" << obj->age << std::endl;
        std::cout << "Height:" << obj->height << std::endl;
        std::cout << "Weight:" << obj->weight << std::endl;
        return os;
    }
    bool operator>(const Student &obj)
    {
        if (this->height > obj.height)
            return true;
        else if (this->height < obj.height)
            return false;
        else if (this->weight > obj.weight)
            return true;
        else
            return false;
    }
};
void swap(Student &a, Student &b)
{
    Student temp = a;
    a = b;
    b = temp;
}
void Bubblesort(Student arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
}
int main()
{
    Student *p = new Student("Trung Kien", "Bong Da", 20, 178, 70.5);
    std::cout << p;
    int n;
    std::cout << "Nhap So Luong: ";
    std::cin >> n;
    Student *arr = new Student[n];
    std::cout << std::endl
              << std::endl;
    for (int i = 0; i < n; ++i)
    {
        std::cout << "Fill the infomation of Student " << i + 1 << std::endl;
        std::cin >> &arr[i];
        std::cout << "\n"
                  << std::endl;
    }

    std::cout << "Sort" << std::endl
              << std::endl;

    Bubblesort(arr, n);
    for (int i = 0; i < n; ++i)
        std::cout << &arr[i] << std::endl;
    delete p;
    delete arr;
    system("pause");
    return 0;
}