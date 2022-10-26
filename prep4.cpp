//Do big 3 copy constructor, assignment constructor, and destructor
#include <iostream>

class airplane
{
public:
    std::string name;
    int speed;
    int length;
    bool flying;

    airplane(){}//create default constructor but doesn't set any values

    airplane(const airplane& plane){
        //copy constructor
        //creates a deep copy based on given
        speed = plane.speed;
        name = plane.name;
        length = plane.length;
        flying = plane.flying;
        std::cout<<"Copy Constructor Called"<<std::endl;

    }

    airplane& operator=(const airplane& plane){
        //assignment constructor
        speed = plane.speed;
        name = plane.name;
        length = plane.length;
        flying = plane.flying;
        std::cout<<"Assignment Constructor Called"<<std::endl;
        return *this;//dereference this pointer and return the object being pointed to
    }

    ~airplane(){
         std::cout<<"Destructor called"<<std::endl;
     }//destructor

};

int main()
{
    airplane a1;
    a1.name = "B2";
    a1.speed = 628;
    a1.length = 34;
    a1.flying = true;

    airplane a2 = a1; //copy constructor called
    std::cout<<a2.name<<std::endl;
    a2.name = "Test";
    a2 = a1; //assignment constructor called
    std::cout<<a2.name<<std::endl;
    return 0;
}
