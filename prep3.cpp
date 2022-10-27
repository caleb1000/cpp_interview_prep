#include <iostream>

class cipher{

private:
	unsigned key;//some internal state
public:
	cipher(unsigned x) : key(x) { std::cout<<"Constructor list called"<<std::endl; } //constructor list
        bool operator()(unsigned n){
            if(n == key){
                std::cout<<"KEY VALID"<<std::endl;
                return true;
            }
            //else
            std::cout<<"KEY INVALID"<<std::endl;
            return false;
        }

};

template <typename T> bool equal(T a, T b){
    return (a == b) ? true : false;
}

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
 	//lambda vs functors vs function pointers vs templates
 	unsigned a = 0x12345678;
 	unsigned b = 0x87654321;
 	std::cout << "Example of function pointers being used to support generic boolean operation function:" <<std::endl;
 	std::cout << "Inital values: a=0x12345678 b=0x87654321"<<std::endl;

 	unsigned result = boolean_op(a, b, AND); //Example of a function pointer. The oldest feature (from C) but is the least flexible
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

 	std::cout << "Example of functors being used to override the () operator" << std::endl;
 	std::cout << "Create cipher object c1" << std::endl;
 	cipher c1(0x12345678);//create cipher object with key value 0x12345678
 	std::cout << "Testing c1 functor with invalid key" << std::endl;
 	c1(0x31245679);//try with wrong key
 	std::cout << "Testing c1 functor with valid key" << std::endl;
 	c1(0x12345678);//try with right key

 	std::cout << "Example of lambda function being used to invert input" << std::endl;
 	auto invert = [](unsigned n) {
     		std::cout << "Lambda invert called"<<std::endl;
     		std::cout << "Input value = 0x" <<std::hex << n << std::endl;
     		std::cout << "Output value = 0x" <<std::hex << ~n << std::endl;
     		return ~n;
 	};
        unsigned test = 0x7FFF0000;
 	result = invert(test);
 	std::cout << "Result from lambda = " << std::hex << result << std::endl;

        std::cout << "Example of template being used to compare if two values are equal" << std::endl;
        std::cout << "Compare if 0x" << result << " is equal to 0x"<< test << ": "<< equal(result, test) << std::endl;//compare result of invert to original value
        result = ~result;
        std::cout << "Compare if 0x" << result << " is equal to 0x"<< test << ": "<< equal(result, test) << std::endl;//compare inverted value of the inverted original value to the original value
        std::cout << "Compare if 33.47 is equal to -33.47: "<< equal(33.47, -33.47) << std::endl;//compare signed type to see if template works on different data types
        std::cout << "Compare if 33.47 is equal to 33.47: "<< equal(33.47, 33.47) << std::endl;//compare signed type to see if template works on different data types


 	return 0;
}
