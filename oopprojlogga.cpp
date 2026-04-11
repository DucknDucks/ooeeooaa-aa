/*
NTO1046
OOP(object-oriented programming) project
Author: Hussein Hajee
Student ID: 40501349
boolean expression and truth table gen
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

class boolop{
public:
    virtual string nameget() const = 0;
    virtual bool eval(bool a, bool b) const{return false;}
    virtual string explanget() const = 0;
    virtual bool noteval(bool a)const{return false;}
    virtual bool isnot() const{return false;}
    virtual ~boolop(){}
};

class AND : public boolop{

};

class OR : public boolop{

};

class XOR : public boolop{

};  

class NOT : public boolop{

};

class NAND : public boolop{

};

class NOR : public boolop{

};

int main(){
    cout <<"\n><================================================><\n";
    cout <<"\n               boolean truth table sim              \n";
    cout <<"\n><================================================><\n";
}