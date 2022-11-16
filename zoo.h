#include<iostream>
#include <vector>
namespace zoo
{
    class Animal
    {
        friend class Breeder;
        int weight;
        std::string name;
    public:
        Animal(int weight, std::string name);
        void virtual toString();
    };


    class Amphibiant: public Animal
    {
        std::string color_of_skin;
    public:
        Amphibiant(int weight, std::string name,std::string color_of_skin);
        void virtual toString();
    };
    class Fish: public Animal
    {
        bool is_saltwater;
        int fins;
    public:
        Fish(int weight, std::string name, bool is_saltwater, int fins);
        void virtual toString();
    };
    class Mammal: public Animal
    {
        std::string color_of_fur;
    public:
        Mammal(int weight, std::string name, std::string color_of_fur);
        void virtual toString();
    };
    class Bird: public Animal
    {
        int wings;
    public:
        Bird(int weight, std::string name, int wings);
        void virtual toString();
    };
    class Reptile: public Animal
    {
        std::string color_of_scales;
    public:
        Reptile(int weight, std::string name, std::string color_of_scales);
        void virtual toString();
    };


    class Salamander: public Amphibiant
    {
        int tail_length;
        std::string color_of_dots;
    public:
        Salamander(int weight, std::string name,std::string color_of_skin,int tail_length,std::string color_of_dots);
        void toString();
    };
    class Frog: public Amphibiant
    {
        bool poisonous;
    public:
        Frog(int weight, std::string name,std::string color_of_skin,bool poisonous);
        void toString();
    };
    class Shark: public Fish
    {
        int teeth;
    public:
        Shark(int weight, std::string name, bool is_saltwater, int fins, int teeth);
        void toString();
    };
    class Whale: public Fish
    {
        int siz;
    public:
        Whale(int weight, std::string name, bool is_saltwater, int fins, int siz);
        void toString();
    };
    class Cat: public Mammal
    {
        int number_of_whiskers;
    public:
        Cat(int weight, std::string name, std::string color_of_fur, int number_of_whiskers);
        void toString();
    };
    class Monkey: public Mammal
    {
        int length_of_arms;
        int length_of_jump;
    public:
        Monkey(int weight, std::string name, std::string color_of_fur, int length_of_arms, int length_of_jump);
        void toString();
    };
    class Toucan: public Bird
    {
        int beek;
    public:
        Toucan(int weight, std::string name, int wings, int beek);
        void toString();
    };
    class Ostrich: public Bird
    {
        int speed;
    public:
        Ostrich(int weight, std::string name, int wings, int speed);
        void toString();
    };
    class Snake: public Reptile
    {
        bool venomous;
        int length;
    public:
        Snake(int weight, std::string name, std::string color_of_scales, bool venomous, int length);
        void toString();
    };
    class Turtle: public Reptile
    {
        std::string pattern;
    public:
        Turtle(int weight, std::string name, std::string color_of_scales, std::string pattern);
        void toString();
    };


    template <class T>
    class Zoo
    {
    public:
        std::vector<Animal*> Animals;
        Zoo& operator+=(T value);
        Zoo& operator-=(int i);
        void RemoveAll();
        void Show();
    };
    template <class T>
    Zoo<T>& Zoo<T>::operator+=(T value)
    {
        this->Animals.push_back(value);
        return *this;
    };
    template <class T>
    Zoo<T>& Zoo<T>::operator-=(int i)
    {
        this->Animals.erase(this->Animals.begin() + i);
    };
    template <class T>
    void Zoo<T>::Show()
    {
        for(int i = 0; i < this->Animals.size(); i++)
        {
            std::cout << "Animal " << i << std::endl;
            this->Animals[i]->toString();
        }
    };
    template <class T>
    void Zoo<T>::RemoveAll()
    {
        while(this->Animals.size())
        {
            this->Animals.erase(this->Animals.begin());
        }
    };

    class Breeder
    {
    public:
        Animal * Create(int a);
        Animal * Breed(Animal* a, Animal* b);
    };
}
