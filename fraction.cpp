#include <iostream>
// using namespace std;
class Fraction
{
private:
    int numerator, denominator;

public:
    Fraction()
    {
        numerator = 0;
        denominator = 1;
    }
    ~Fraction()
    {
        numerator = 0;
        denominator = 1;
    }
    // method
    void set()
    {
        std::cout << "Please give me numerator:";
        std::cin >> this->numerator;
        std::cout << "Please give me denominator:";
        std::cin >> this->denominator;
    }
    void get()
    {
        std::cout << "Fraction:" << this->numerator << "/" << this->denominator << std::endl;
    }
    Fraction *Subtract(Fraction *obj1, Fraction *obj2)
    {
        Fraction *obj3 = new Fraction;
        obj3->numerator = obj1->numerator * obj2->denominator - obj1->denominator * obj2->numerator;
        obj3->denominator = obj1->denominator * obj2->denominator;
        return obj3;
    }
    Fraction *Add(Fraction *obj1, Fraction *obj2)
    {
        Fraction *obj3 = new Fraction;
        obj3->numerator = obj1->numerator * obj2->denominator + obj1->denominator * obj2->numerator;
        obj3->denominator = obj1->denominator * obj2->denominator;
        return obj3;
    }
    Fraction *Mutiply(Fraction *obj1, Fraction *obj2)
    {
        Fraction *obj3 = new Fraction;
        obj3->numerator = obj1->numerator * obj2->numerator;
        obj3->denominator = obj1->denominator * obj2->denominator;
        return obj3;
    }
    Fraction *Divide(Fraction *obj1, Fraction *obj2)
    {
        Fraction *obj3 = new Fraction;
        obj3->numerator = obj1->numerator * obj2->denominator;
        obj3->denominator = obj1->denominator * obj2->numerator;
        return obj3;
    }
};
int main()
{
    std::cout << "Faction1:---------------------------------" << std::endl;
    Fraction *Fraction1 = new Fraction;
    Fraction1->set();
    Fraction1->get();

    std::cout << "Fraction2--------------------------------" << std::endl;
    Fraction *Fraction2 = new Fraction;
    Fraction2->set();
    Fraction2->get();

    std::cout << "Fraction3---------------------------------" << std::endl;
    Fraction *Fraction3 = new Fraction;
    std::cout << "Subtract------------------------" << std::endl;
    Fraction3->Subtract(Fraction1, Fraction2)->get();
    std::cout << "Add-----------------------------" << std::endl;
    Fraction3->Add(Fraction1, Fraction2)->get();
    std::cout << "Mytiply------------------------" << std::endl;
    Fraction3->Mutiply(Fraction1, Fraction2)->get();
    std::cout << "Divide-------------------------" << std::endl;
    Fraction3->Divide(Fraction1, Fraction2)->get();

    system("pause");
    return 0;
}