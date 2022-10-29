//Do big 3 copy constructor, assignment constructor, and destructor
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

class airplane
{
public:
    std::string name;
    char* arms;
    int arms_number;
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
        arms_number = plane.arms_number;
        arms = (char*) malloc(arms_number*sizeof(char));//allocate
        char* temp_copy = arms;
        char* temp_org = plane.arms;
        for(int x = 0; x<arms_number; x++){
            *temp_copy = *temp_org;
            temp_copy++;
            temp_org++;
        }
        std::cout<<"Copy Constructor Called"<<std::endl;

    }

    airplane& operator=(const airplane& plane){
        //assignment constructor
        speed = plane.speed;
        name = plane.name;
        length = plane.length;
        flying = plane.flying;
        arms_number = plane.arms_number;
        arms = (char*) malloc(arms_number*sizeof(char));//allocate
        char* temp_copy = arms;
        char* temp_org = plane.arms;
        for(int x = 0; x<arms_number; x++){
            *temp_copy = *temp_org;
            temp_copy++;
            temp_org++;
        }

        std::cout<<"Assignment Constructor Called"<<std::endl;
        return *this;//dereference this pointer and return the object being pointed to
    }

    ~airplane(){
         std::cout<<"Destructor called"<<std::endl;
         free(this->arms);//free the malloc for the char pointer mem
     }//destructor

};

int main()
{
    // -> has higher operator precedence than *
    std::cout<<"Create objects a1 and a3, but only assign a1 values directly"<<std::endl;
    airplane a1,a3;
    a1.name = "B2";
    a1.speed = 628;
    a1.length = 34;
    a1.flying = true;
    a1.arms_number = 5;//4 chars and 1 null byte
    a1.arms = (char*) malloc(a1.arms_number*sizeof(char));//allocate 4 chars
    std::string temp_string = "bomb";
    char* temp_str = a1.arms;
    for(int x = 0; x<a1.arms_number-1; x++){
        *temp_str = temp_string.at(x);
        temp_str++;
    }
    *temp_str = '\0';//added final null byte terminator to str
    std::cout<<"Create a copy a2 from object a1"<<std::endl;
    airplane a2 = a1; //copy constructor called
    //The copy constructor is only called once, on the first creation of an object
    std::cout<<"Assign a3's values by copying a1's"<<std::endl;
    a3 = a2; //assignment constructor called
    *(a2.arms) = 'c';
    std::cout<<"Modify a2's char buffer to show it is a deep copy rather than a shallow copy of the pointer"<<std::endl;
    std::cout<<"Final planes arms values:"<<std::endl;

    std::cout<<"a1 arms = "<<a1.arms<<std::endl;
    std::cout<<"a2 arms = "<<a2.arms<<std::endl;
    std::cout<<"a3 arms = "<<a3.arms<<std::endl;
    return 0;
}
