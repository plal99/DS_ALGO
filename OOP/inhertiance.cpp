class Animal
{ 
    public:
    int legs = 4;
};

// Dog class inheriting Animal class
class Dog : public Animal
{ 
    public:
    int tail = 1;
};

int main()
{
    Dog d;
    cout << d.legs;
    cout << d.tail;
}