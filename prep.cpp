#include <iostream>
#include <string>

class missile
{
public:
	std::string name;

        void print_name(std::string name){
            std::cout<<"BASE CLASS: missile name "<<name<<std::endl;
        }
        virtual void launch(){
            std::cout<<"BASE CLASS: launch "<<name<<std::endl;
        }
        virtual ~missile() {} //add virtual destructor, even thought it doesn't get used it is needed to allow the base class missile to be dynamically case to other derived classes
};

class lockheedmartin : public missile
{
public:
	//use the base class data member name
        int range;
        void print_name(std::string name){
            std::cout<<"Lockheedmartin: missile name "<<name<<std::endl;
        }
        void print_range(int range){
	    std::cout<<"Lockheedmartin: missile max km range = "<<range<<std::endl;
        }

        static void print_static(){
            //static function that can be called without instance of class
            std::cout<<"Lockheedmartin: Static function call (no object needed) "<<std::endl;
        }
        void launch(){
            std::cout<<"Lockheedmartin: Launch "<<name<<" with max range " <<range<<"km"<<std::endl;
        }
};

class  raytheon : public missile
{
public:
	std::string feature;
        std::string name;
        void print_name(std::string name){
            std::cout<<"Raytheon: missile name "<<name<<std::endl;
        }

        void print_feature(std::string feature){
            std::cout<<"Raytheon: missile feature "<<feature<<std::endl;
        }

        void print_name(){
            std::cout<<"Raytheon: overloaded print function"<<std::endl;
        }

        void launch(){
            std::cout<<"Raytheon: Launch "<<name<<" with feature "<<feature<<std::endl;
        }

};

int main(){

     missile m1;
     raytheon m2;
     missile* mp1 = &m2;//base class pointer to a child object
     //create 2 objects, one parent (base) class, one child

     std::cout<<"Setting base class object m1's name to rocket"<<std::endl;
     m1.name = "rocket";
     m1.print_name(m1.name);

     std::cout<<"Setting derived class object m2's name to stormbreaker"<<std::endl;
     m2.name = "stormbreaker";
     m2.print_name(m2.name);

     std::cout<<"Setting m2's feature to heat-seeking"<<std::endl;
     m2.feature ="heat-seeking";
     m2.print_feature(m2.feature);

     std::cout<<"Calling print_name function from base class pointer mp1 that points to derived object m2"<<std::endl;
     mp1->print_name(mp1->name);//this will be empty as our base class's data member "string name" was not set, only the derived class's "string name" was set
     std::cout<<"Missing base class name, setting base class object name data member to paveway"<<std::endl;
     mp1->name = "paveway";
     mp1->print_name(mp1->name);

     std::cout<<"Dynamically casting mp1 to mp2 which is a derived class pointer, then call derived class print_name"<<std::endl;
     raytheon* mp2 = dynamic_cast<raytheon*>(mp1);
     mp2->print_name(mp2->name);
     std::cout<<"Call base class function with base class data member using the dynamically casted pointer"<<std::endl;
     mp2->missile::print_name(mp2->missile::name);
     std::cout<<"Calling overloaded function for print_name that has no args"<<std::endl;
     mp2->print_name();

     lockheedmartin m3; //create derived class, this time uses base class name member
     missile* mp3 = &m3;
     std::cout<<"Create derived class m3 and create mp3 that is a base class pointer to m3. Set m3 derived class name to PrSM and range to 499km"<<std::endl;
     m3.name = "PrSM";
     m3.range = 499;
     std::cout<<"Call derived class's print_name and print_range member functions, then call the print_name function from the base class pointer"<<std::endl;
     m3.print_name(m3.name);
     m3.print_range(m3.range);
     mp3->print_name(mp3->name);
     std::cout<<"Unlike the previous derived class, this class uses the base class's data member \"name\". This means it is disambiguous to reference the name data member as only the base class has that member"<<std::endl;
     std::cout<<"Calling static member function without an object and with an object"<<std::endl;
     lockheedmartin::print_static();//can call static function without object
     m3.print_static();//can also call static function from an object

     std::cout<<"Launch missiles in order m1, m2, m3, mp1, mp2, mp3"<<std::endl;
     m1.launch();
     m2.launch();
     m3.launch();
     mp1->launch();//notice that mp1 is a missle pointer but still calls the derived class function as launch is a virtual function
     mp2->launch();
     mp3->launch();

}
