#include <iostream>
class Date
{
protected:
    int day, month, year;

public:
    Date()
    {
        this->day = this->month = this->year = 0;
    }
    ~Date()
    {
        this->day = this->month = this->year = 0;
    }
    void input()
    {
        std::cout << "Please enter the day of the flight:";
        std::cin >> this->day;
        std::cout << "Please enter the month of the flight:";
        std::cin >> this->month;
        std::cout << "Please enter the year of the flight:";
        std::cin >> this->year;
    }
    void outPut()
    {
        std::cout << "Day/month/year:" << this->day << "/" << this->month << "/" << this->year << std::endl;
    }
};
class PlaneTicket
{
private:
    std::string from, to;
    int price;
    Date *flightDate = new Date;

public:
    PlaneTicket()
    {
        this->from = "";
        this->to = "";
        this->price = 0;
    }
    ~PlaneTicket()
    {
        this->from = "";
        this->to = "";
        this->price = 0;
        delete this->flightDate;
    }
    void inPut()
    {
        std::cin.ignore();
        std::cout << "Please enter the start position:";
        fflush(stdin);
        std::getline(std::cin, this->from);
        std::cout << "Please enter the destination:";
        fflush(stdin);
        std::getline(std::cin, this->to);
        std::cout << "Please enter the price:";
        std::cin >> this->price;
        std::cout << "Please enter the day to flight:" << std::endl;
        this->flightDate->input();
    }
    void outPut()
    {
        std::cout << "From: " << this->from << std::endl;
        std::cout << "To: " << this->to << std::endl;
        std::cout << "Flight Date: " << std::endl
                  << "\t";
        this->flightDate->outPut();
        std::cout << "Ticket Price: " << this->price << std::endl;
    }
    int getPrice()
    {
        return this->price;
    }
};
class Person
{
protected:
    std::string name, gentle;
    int age;

public:
    Person()
    {
        this->name = this->gentle = "";
        this->age = 0;
    }
    ~Person()
    {
        this->name = this->gentle = "";
        this->age = 0;
    }
    void input()
    {
        std::cin.ignore();
        std::cout << "enter name: ";
        fflush(stdin);
        std::getline(std::cin, this->name);
        std::cout << "enter gentle: ";
        fflush(stdin);
        std::getline(std::cin, this->gentle);
        std::cout << "Age: ";
        std::cin >> this->age;
    }
    void outPut()
    {
        std::cout << "Name:" << this->name << std::endl;
        std::cout << "Gentle: " << this->gentle << std::endl;
        std::cout << "Age" << this->age << std::endl;
    }
};
class Passenger : public Person
{
protected:
    int amount;
    int totalPrice;
    PlaneTicket *ticket;
    // PlaneTicket *ticket = new PlaneTicket[1000] 
    // We cannot increase/decrease the size of the same array so can't use this->ticket[this->amount] to reasign the number of items in ticket array
public:
    Passenger()
    {
        this->amount = 0 ;
        this->totalPrice = 0;
        // this->ticket = new PlaneTicket[this->amount];
    }
    ~Passenger()
    {
        this->amount = 0;
        this->totalPrice = 0;
        delete[] this->ticket;
    }
    void inPut()
    {
        //If there is a function with the same signature in the derived class you can disambiguate it by adding the base class's name followed by two colonsbase_class::foo(...). You should note that unlike Java and C#, C++ does not have a keyword for "the base class" (super or base) since C++ supports multiple inheritance which may lead to ambiguity
        Person::input();
        std::cout << "enter the amount of tickets that The passenger brought:";
        std::cin >> this->amount;
        this->ticket = new PlaneTicket[this->amount]; // can't asign the number of items for ticket array before and then reasign with  this->ticket[this->amount]
        for (int i = 0; i < this->amount; i++)
        {
            ticket[i].inPut();
            this->totalPrice += ticket[i].getPrice();
        }
    }
    void outPut()
    {
        std::cout << "-----Passenger information-------" << std::endl;
        Person ::outPut();
        std::cout << "- ----Flight Information------- " << std::endl;
        for (int i = 0; i < this->amount; ++i)
        {
            ticket[i].outPut();
            std::cout << std::endl;
        }
        std::cout << "==> Total Price = " << this->totalPrice;
        std::cout << std::endl;
    }
    bool operator < (const Passenger &obj)
    {
        if (this->totalPrice < obj.totalPrice)
            return true;
        else
            return false;
    }
};
void swap(Passenger &a, Passenger &b)
{
    Passenger temp = a;
    a = b;
    b = temp;
}
void Bubblesort(Passenger arr[], int n)
{
    for (int i = 0; i < n - 1; ++i)
        for (int j = 0; j < n - i - 1; ++j)
            if (arr[j] < arr[j + 1])
                swap(arr[j], arr[j + 1]);
}
int main()
{
    int n;
    std::cout << "Enter the number of pasengers:";
    std::cin >> n ;
    Passenger *arr = new Passenger[n];
    for (int i = 0; i < n; i++)
    {
        arr[i].inPut();
    }
    for (int i = 0; i < n; i++)
    {
        arr[i].outPut();
        std::cout << std::endl
                  << "--------------------------------" << std::endl;
    }
    std::cout << "After Sort: " << std::endl;
    Bubblesort(arr, n);
    for (int i = 0; i < n; ++i)
    {
        arr[i].outPut();
        std::cout << std::endl << "------------------" << std::endl << std::endl;
    }
    system("pause");
    return 0;
}