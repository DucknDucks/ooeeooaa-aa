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
    virtual string nameget() const = 0; //this will just name the operators, and, or, nor etc
    virtual bool eval(bool a, bool b) const{return false;} //this will just take 2 inputs and evaluate the operator
    virtual string explanget() const = 0; //this will explain what the operator does
    virtual bool noteval(bool a)const{return false;} //this is for not only basically, reads 1 input
    virtual bool isnot() const{return false;} //this is just to check whether the operator is not
    virtual ~boolop(){} //classic lil destructor
};

class AND : public boolop{
    string nameget() const override {return "AND";}
    string explanget() const override{
        return "AND  : True only if BOTH inputs are true.(0 AND 0=0, 1 AND 0=0, 1 AND 1=1)";}
    bool eval(bool a, bool b) const override {return a&&b;}
};

class OR : public boolop{
    string  nameget() const override {return "OR";}
    string explanget() const override{
        return "OR   : True if at least ONE input is true.(0 OR 0=0, 1 OR 0=1, 1 OR 1=1)";}
    bool eval(bool a, bool b) const override {return a||b;}
};

class XOR : public boolop{
    string nameget() const override {return "XOR";}
    string explanget() const override{
        return "XOR  : True if exactly ONE input is true. (0 XOR 0=0, 1 XOR 0=1, 1 XOR 1=0)";}
    bool eval(bool a, bool b) const override {return a != b;}
};  

class NOT : public boolop{
    string nameget() const override {return "NOT";}
    string explanget() const override {
        return "NOT  : Inverts the input. (NOT 0=1, NOT 1=0)";
    }
    bool noteval(bool a) const override{
        return !a;
    }
    bool isnot() const override{
        return true;
    }
};

class NAND : public boolop{
    string nameget() const override {return "NAND";}
    string explanget() const override {
        return "NAND : True unless BOTH inputs are true. (0 NAND 0=1, 1 NAND 0=1, 1 NAND 1=0)";}
    bool eval(bool a, bool b) const override {return !(a && b);}
};

class NOR : public boolop{
    string nameget() const override { return "NOR"; }
    string explanget() const override {
        return "NOR  : True only if BOTH inputs are false. (0 NOR 0=1, 1 NOR 0=0, 1 NOR 1=0)";}
    bool eval(bool a, bool b) const override {return !(a || b);}   
};

string uppercase(string str){
    for (int i = 0; i<(int)str.size(); i++){ //this is just to convert the input to uppercase, so turning "and" into "AND" so forth and so on
        if (str[i]>='a' && str[i]<='z'){
            str[i] = str[i]-32;
        }   
    }
    return str;
}

bool containsop(const string& stri, const string&word){
    size_t pos = stri.find(word);
    while (pos != string::npos){    //this is to check if the input has an operator in it, it also makes the distinction between AND in NAND, so it basically checks if the word is surrounded by non-alphabetic characters or is at the start/end of the string that sort of thing
        bool before = (pos == 0) || !isalpha(stri[pos - 1]);
        bool after = (pos + word.size() >= stri.size()) || !isalpha(stri[pos + word.size()]);
        if (before && after){
            return true;
        }
        pos = stri.find(word, pos + 1);
    }
    return false;
}

class boolexpression{
private:
    string expression;
    bool a, b, c;   //this is a wip
    vector<string> opsfound;
public:
    boolexpression(){
        expression = "";
        a = b = c = false;
    }
    void expressionset(const string&epress){
        expression = uppercase(epress);
        a = (expression.find("A") != string::npos);
        b = (expression.find("B") != string::npos);
        c = (expression.find("C") != string::npos);
        opsfound.clear();
            if (containsop(expression, "AND")){
                opsfound.push_back("AND");
        }
            if (containsop(expression, "OR")){
                opsfound.push_back("OR");
        }
            if (containsop(expression, "XOR")){
                opsfound.push_back("XOR");
        }
            if (containsop(expression, "NOT")){
                opsfound.push_back("NOT");
        }
            if (containsop(expression, "NAND")){
                opsfound.push_back("NAND");
        }
            if (containsop(expression, "NOR")){
                opsfound.push_back("NOR");
        }
            if(int(opsfound.size())>3){
                cout << "the max operator limit has been exceeded\n";
            }
    }

    string epressget() onst{
        return expression;
    }
    bool geta() const{
        return a;
    }
    bool getb()const{
        return b;
    }
    bool getc()const{
        return c;
    }
    vector<string> getfoundops() const{
        return opsfound;
    }

    bool evaluate(bool aval, bool bval, bool cval) const{
        //this is also wip, the idea is to evaluate the expression according to the operators found and the values of a,b,c
        //but what i plan for it to do is replace the variables with their values and then evaluate the expression based on the operators found
        return false;
    }
};

int main(){
    cout <<"\n><================================================><\n";
    cout <<"\n               boolean truth table sim              \n";
    cout <<"\n><================================================><\n";
}