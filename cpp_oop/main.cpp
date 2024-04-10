#include <iostream>
 
class Person
{
public:
    Person(std::string p_name, unsigned p_age)
    {
        ++count;    // при создании нового объекта увеличиваем счетчик
        name = p_name;
        age = p_age;
    }
    void print_count()
    {
        std::cout << "Created " << count << " objects" << std::endl;
    }
private:
    std::string name;
    unsigned age;
    static inline unsigned count{};  // статическое поле - счетчик объектов Person
};
 
int main()
{
    Person tom{"Tom", 38};
    tom.print_count();
    Person bob{"Bob", 42};
    bob.print_count();
    Person sam{"Sam", 25};
    sam.print_count();
}