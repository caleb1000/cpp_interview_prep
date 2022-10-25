#include <iostream>

class clearance {
  public:
    int confidential = 1;

    void print_clearance(){
        std::cout<<"Base: Confidential = "<<confidential<<" Secret = "<<secret<<" Top Secret = "<<top_secret<<std::endl;
    }
    void inc_ts(){
        top_secret++;
    }

  protected:
    int secret = 1;
  private:
    int top_secret = 1;
};

class c : public clearance{
public:
    void inc(){
        //all members keep original control level
        confidential++;//public
        secret++;//protected
        //top_secret++; illegal, only base class can modify
    }
};

class s : protected clearance{
public:
    void inc(){
        //all public and protected members are inherited as protected members, private stays private
        confidential++;//protected
        secret++;//protected
        //top_secret++; illegal, only base class can modify
    }
};

class ts : private clearance{
public:
    void inc(){
        //all data members are inherited as private
        confidential++;//private
        secret++;//private
        //top_secret++; illegal, only base class can modify
    }
};

class ts_sci : public ts{
public:
    void try_inc(){
        //confidential++; illegal, data members of ts are all private and can only be modified by that class, even though confidential started as public in the original base class it changed to private in ts
    }
};

class s_sap : public s{
public:
    void try_inc(){
        //because s's data members are protected, inherited classes can still modify the values directly
        confidential++;
        secret++;
        //top_secret++; illegal, only base class can modify
    }
};


int main() {
  //Public: Members can be accessed by base, derived, and outside classes
  //Protected: Members can be accessed by base and derived classes
  //Private: Members can only be accessed by only base class

  std::cout<<"Base class:"<<std::endl;
  clearance c1;
  c1.print_clearance();//print original values
  c1.confidential = 2;//modify public value
  c1.print_clearance();
  c1.inc_ts();
  c1.print_clearance();
  //c1.secret = 2; Illegal
  //c1.top_secret =2; Illegal
  std::cout<<""<<std::endl;

  std::cout<<"Derived public class: C"<<std::endl;
  c c2; //public inherited
  c2.print_clearance();
  c2.confidential = 2;
  c2.print_clearance();
  c2.inc();
  c2.print_clearance();
  c2.inc_ts();
  c2.print_clearance();
  //c2.secret = 2; Illegal
  //c2.top_secret =2; Illegal
  std::cout<<""<<std::endl;

  std::cout<<"Derived protected class: S"<<std::endl;
  s c3; //protected inherited
  //c3.print_clearance(); Illegal
  //c3.inc(); Illegal
  //c3.print_clearance(); Illegal
  //c3.confidential = 2; Illegal
  //c3.secret = 2; Illegal
  //c3.top_secret =2; Illegal
  std::cout<<""<<std::endl;

  std::cout<<"Derived private class: TS"<<std::endl;
  ts c4; //private inherited
  //ts.print_clearance(); Illegal
  //ts.inc(); Illegal
  //ts.print_clearance(); Illegal
  //c4.confidential = 2; Illegal
  //c4.secret = 2; Illegal
  //c4.top_secret = 2; Illegal
  std::cout<<""<<std::endl;

  return 0;
}
