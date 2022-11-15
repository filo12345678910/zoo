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
