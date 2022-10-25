#include <iostream>

class clearance {
  public:
    int confidential = 1;

    void print_clearance(){
        std::cout<<"Confidential = "<<confidential<<" Secret = "<<secret<<" Top Secret = "<<top_secret<<std::endl;
    }

  protected:
    int secret = 1;
  private:
    int top_secret = 1;
};

class c : public clearance{
    void inc(){
        confidential++;
        secret++;
        //top_secret++; illegal
    }
};

class s : protected clearance{
    void inc(){
        //all public and protected members are inherited as protected members, private stays private
        confidential++;
        secret++;
        //top_secret++; illegal
    }
};

class ts : private clearance{
    void inc(){
        //all data members are inherited as private
        confidential++;
        secret++;
        //top_secret++; illegal
    }
};


int main() {
  //Public: Members can be accessed by base, derived, and outside classes
  //Protected: Members can be accessed by base and derived classes
  //Private: Members can only be accessed by only base class


  clearance c1;
  c1.confidential = 2;
  //c1.secret = 2; Illegal
  //c1.top_secret =2; Illegal

  c c2;
  c2.confidential = 2;
  //c2.secret = 2; Illegal
  //c2.top_secret =2; Illegal

  s c3;
  //c3.confidential = 2; Illegal
  //c3.secret = 2; Illegal
  //c3.top_secret =2; Illegal

  ts c4;
  //c4.confidential = 2;
  //c4.secret = 2;
  //c4.top_secret = 2;

  return 0;
}
