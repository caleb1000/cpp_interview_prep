#include <iostream>

unsigned XOR(unsigned x , unsigned y)
{
    return x ^ y;
}

unsigned NOR(unsigned x , unsigned y)
{
    return ~(x | y);
}

unsigned AND(unsigned x , unsigned y)
{
    return x & y;
}

unsigned OR(unsigned x, unsigned y){
    return x | y;
}

unsigned NAND(unsigned x , unsigned y)
{
    return ~(x & y);
}

unsigned XNOR(unsigned x , unsigned y){
    return (~x & ~y) | (x & y);
}

unsigned boolean_op(unsigned x, unsigned y, unsigned(*op)(unsigned, unsigned)){
    return op(x,y);
};

int main()
{
 //lambda vs function pointers
 unsigned a = 0x12345678;
 unsigned b = 0x87654321;

 std::cout << "Inital values: a=0x12345678 b=0x87654321"<<std::endl;

 unsigned result = boolean_op(a, b, AND);
 std::cout << "AND = 0x" <<std::hex <<result<< std::endl;

 result = boolean_op(a, b, OR);
 std::cout << "OR = 0x" <<std::hex <<result<< std::endl;

 result = boolean_op(a, b, XOR);
 std::cout << "XOR = 0x" <<std::hex <<result<< std::endl;

 result = boolean_op(a, b, NAND);
 std::cout << "NAND = 0x" <<std::hex <<result<< std::endl;

 result = boolean_op(a, b, NOR);
 std::cout << "NOR = 0x" <<std::hex <<result<< std::endl;

 result = boolean_op(a, b, XNOR);
 std::cout << "XNOR = 0x" <<std::hex <<result<< std::endl;

 return 0;
}
