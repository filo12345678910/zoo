#include<iostream>
#include <vector>
namespace zoo
{
    class Animal
    {
        int age;
        std::string gender;
    public:
        Animal(int age, std::string gender);
        void virtual toString();
    };
    class Amphibiant: public Animal
    {
        std::string color_of_skin;
    public:
        Amphibiant(int age, std::string gender,std::string color_of_skin);
        void virtual toString();
    };
    class Salamander: public Amphibiant
    {
        int tail_length;
        std::string color_of_dots;
    public:
        Salamander(int age, std::string gender,std::string color_of_skin,int tail_length,std::string color_of_dots);
        void toString();
    };
    class Frog: public Amphibiant
    {
        bool poisonous;
    public:
        Frog(int age, std::string gender,std::string color_of_skin,bool poisonous);
        void toString();
    };

    template <class T>
    class Zoo
    {
    public:
        std::vector<Animal*> Animals;
        void Add(T value);
        void Remove(int i);
        void RemoveAll();
        void Show();
    };
    template <class T>
    void Zoo<T>::Add(T value)
    {
        this->Animals.push_back(value);
    };
    template <class T>
    void Zoo<T>::Remove(int i)
    {
        this->Animals.erase(this->Animals.begin() + i);
    };
    template <class T>
    void Zoo<T>::Show()
    {
        for(int i = 0; i < this->Animals.size(); i++)
        {
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

    /*class Breeder
    {
    public:
        void Create();
    };*/
}
