//  https://www.youtube.com/watch?v=Rub-JsjMhWY
//  have to compile with c++11
//  g++ -std=c++11

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cstdlib>

using namespace std;

//FUNCTIONS
int addNumbers(int firstNum, int secondNum = 0){
    int combinedValue = firstNum + secondNum;
    return combinedValue;
}

//OVERLOAD FUNCTIONS
int addNumbers(int firstNum, int secondNum, int thirdNum){
    return firstNum + secondNum + thirdNum;
}

//RECURSIVE FUNCTION
int getFactorial(int number){
    int sum;
    if(number == 1) sum = 1;
    else sum = getFactorial(number - 1) * number;
    return sum;
}

//POINTER FUNCTION
void makeMeYoung(int* age){
    cout << "I used to be " << *age << endl;
    *age = 21;
}        

//POINTER FUNCTION
void actYourAge(int& age){
    age = 40;
    }

//OBJECT ORIENTED PROGRAMMING
class Animal{

    //Attributes : height weight variables
    //Capabilties : Run Eat functions / methods
private:
    int height;
    int weight;
    string name;
    
    static int numOfAnimals;
    
public:
    int getHeight(){ return height; }
    int getWeight(){ return weight; }
    string getName(){ return name; }
    void setHeight(int cm){ height = cm; }
    void setWeight(int kg){ weight = kg; }
    void setName(string animalName){ name = animalName; }
    
    Animal(int, int, string);
    ~Animal();
    
    Animal();
        
    static int getNumOfAnimals(){ return numOfAnimals; }
    
    void toString();
};

int Animal::numOfAnimals = 0;


Animal::Animal(int height, int weight, string name){
    this -> height = height;
    this -> weight = weight;
    this -> name = name;
    Animal::numOfAnimals++;
}

Animal::~Animal(){
    cout << "Animal " << this -> name << " destroyed" << endl;
}

Animal::Animal(){
    Animal::numOfAnimals++;
}    

void Animal::toString(){
    cout << this -> name << " is " << this -> height << 
        " cms tall and " << this -> weight << " kgs in weight" << endl; 
}
    
    
//OOP Inheritance    
class Dog : public Animal{
private:
    string sound = "Arf";
    
public:
    void getSound() { cout << sound << endl; }
    
    Dog(int, int, string, string);
    
    Dog() : Animal(){};
    void toString();
};

Dog::Dog(int height, int weight, string name, string bark):
Animal(height, weight, name){
    this -> sound = bark;
}

void Dog::toString(){
    cout << this -> getName() << " is " << this -> getHeight() <<
        " cms tall and " << this -> getWeight() << " kgs in weight and says "
        << this -> sound << endl;
}
//OBJECT ORIENTED PROGRAMMING


//VIRTUAL METHODS AND POLYMORPHISM
//1:02:29
class Animal2 {
public:
    void getFamily() { cout << "We are animals2" << endl; }

    virtual void getClass() { cout << "I'm an Animal2" << endl; }

    virtual void makeSound() { cout << "The Animal2 says grr" << endl; }

};

class Giraffe : public Animal2 {
    public:
        void getClass() { cout << "I'm a Giraffe" << endl; }
        void makeSound() { cout << "The Giraffe says Squeak" << endl; }
};


class Rhino : public Animal2 {
    public:
        void makeSound() { cout << "The Rhino says Burrrr" << endl; }
};        

void whatClassAreYou(Animal2 *animal){
    animal->getClass();
}

class PigmyGiraffe : public Giraffe {
public: 
    void getClass() { cout << "I'm a Pigmy" << endl; }
    void getDerived() { cout << "I'm a pigmy and a Giraffe" << endl; }
};

class Car {
public:
    virtual int getNumWheels() = 0;
    virtual int getNumDoors() = 0;
};

class StationWagon : public Car {
public:
    int getNumWheels(){ cout << "Station wagon has 4 wheels" << endl; }
    int getNumDoors(){ cout << "Station wagon has 5 doors" << endl; }
    StationWagon() {};
    ~StationWagon();
};
    
int main() {

    // Seed a random number generator with time
    srand(static_cast<unsigned int>(time(0)));
    
    // output some text
    cout << "Hello WOrld" << endl;
    
    const double PI = 3.1415926535;
    
    char myGrade = 'A';
    
    bool isHappy = true;
    
    int myAge = 40;
    
    float favNum = 3.141592;
    
    double otherFavNum = 1.6180339887;
    
    int largestInt = 2147483648;
    
    cout << "Favorite Number " << favNum << endl;

    // Other types include
    // short int : At least 16 bits
    // long int : At least 32 bits
    // long long int : At least 64 bits
    // unsigned int : same as signed version but positive
    // long double : Not less than double
    
    cout << "Size of int " << sizeof(myAge) 
        << endl;
    cout << "Size of char " << sizeof(myGrade) << endl;
    cout << "Size of bool " << sizeof(isHappy) << endl;
    cout << "Size of float " << sizeof(favNum) << endl;
    cout << "Size of double " << sizeof(otherFavNum) << endl;

    cout << "Largest int " << largestInt << endl;

    // arithmetic - +, -, *, /, %, ++, --, 
    
    cout << "5 + 2 = " << 5+2 << endl;    
    cout << "5 - 2 = " << 5-2 << endl;
    cout << "5 * 2 = " << 5*2 << endl;
    cout << "5 / 2 = " << 5/2 << endl;
    cout << "5 % 2 = " << 5%2 << endl;

    int five = 5;
    cout << "5++ = " << five++ << endl;
    cout << "++5 = " << ++five << endl;
    cout << "5-- = " << five-- << endl;
    cout << "--5 = " << --five << endl;

    five += 5;
    
    // Order of Operation states * and / is performed before + and -
    
    cout << "1 + 2 - 3 * 2 = " << 1 + 2 - 3 * 2 << endl;
    cout << "(1 + 2 - 3) * 2 = " << (1 + 2 - 3) * 2 << endl;    
    
    cout << "4 / 5 = " << 4 / 5 << endl;
    cout << "4 / 5 = " << (float)4 / 5 << endl;  // casting to  a float

    // comparision operators: ==, !=, >, <, >=, <=    
    // logical operators: &&, ||, !
    
    // if statement
    int age = 70;
    int ageAtLastExam = 16;
    bool isNotIntoxicated = true;

    if ((age >= 1) && (age < 16)) {
        cout << "You can't drive" << endl;
    } else if(!isNotIntoxicated){
        cout << "You can't drive" << endl;
        
    } else if(age >= 80 && ((age > 100) || ((age - ageAtLastExam) > 5))){
        cout << "You can't drive" << endl;
    } else {
        cout << "You can drive" << endl;
    }
    
    
    // switch statement
    int greetingOption = 2;
    switch(greetingOption){
        case 1:
            cout << "boujour" << endl;
            break;
        case 2:
            cout << "hola" << endl;
            break;
        case 3:
            cout << "sup" << endl;
            break;
        default:
            cout << "Hello" << endl;    
    }
    
    // ternary operator  //  variable = (condition) ? true : false
    int largestNum = (5>2) ? 5 : 2;
    cout << "largestNum is " << largestNum << endl;
    
    // arrays. store multiple values of the same data type
    int myFavNums[5];
    int badNums[5] = {4, 13, 14, 24, 34};
    
    cout << "Bad Number 1: " << badNums[0] << endl;
    
    // multidimensional array
    char myName[5][7] = {{'M', 'a', 't', 't'},
                        {'C', 'l', 'e', 'm', 'o', 'n', 's'}};
                    
    cout << "Second letter in second array: " << myName[1][1] << endl;    
    
    myName[0][2] = 'm';
    cout << "New Value: " << myName[0][2] << endl;
    myName[0][0] = 'P';
    myName[0][1] = 'i';
    myName[0][3] = 'p';
    
    // for loops
    for(int i = 1; i <= 10; ++i){
        cout << i << endl;
    }
    
    for(int j = 0; j < 5; ++j){
        for(int k = 0; k < 7; ++k){
            cout << myName[j][k];
        }
    }
    cout << endl;
    
    // while loops
    int randNum = (rand() % 100) + 1;
    
    while(randNum != 100){
        cout << randNum << ", ";
        
        randNum = (rand() % 100) +1;
    }
    
    int index = 1;
    
    while(index <= 10){
        cout << index << endl;
        index++;
    }
    
    
    /* UNCOMMENT FOR DO WHILE    
    // do while loops
    string numberGuessed;
    int intNumberGuessed = 0;
    
    do{
        cout << "Guess between 1 and 10: ";
        getline(cin, numberGuessed);
        intNumberGuessed = stoi(numberGuessed);
        cout << intNumberGuessed << endl;
    } while(intNumberGuessed != 4);    
 
    cout << "You win\n" << endl;
    //UNCOMMENT FOR DO WHILE */
    
    
    
    /* UNCOMMENT FOR STRINGS
    // strings    
    // in c it was
    char happyArray[6] = {'H', 'a', 'p', 'p', 'y', '\0'};
    
    // in c++ you have 'string' objects
    string birthdayString = " Birthday";
    
    // concatenate strings
    cout << happyArray + birthdayString << endl;
    
    
    string yourName;
    cout << "What is your name ";
    getline(cin, yourName);
    
    cout << "hello " << yourName << endl;
    
    /*
    double eulersConstant = .57721;
    string eulerGuess;
    double eulerGuessDouble; 
    
    cout << "What is Euler's constant? ";
    getline(cin, eulerGuess);
    
    eulerGuessDouble = stod(eulerGuess);
    
    if(eulerGuessDouble == eulersConstant){
        cout << "You are right" << endl;
    } else{
        cout << "You are wrong" << endl;
    }
    
    
    cout << "Size of String " << eulerGuess.size() << endl;
    cout << "Is string empty " << eulerGuess.empty() << endl;
    cout << eulerGuess.append(" was your guess") << endl;
    
    
    string dogString = "dog";
    string catString = "cat";
    
    cout << dogString.compare(catString) << endl;
    cout << dogString.compare(dogString) << endl;
    cout << catString.compare(dogString) << endl;
    
    
    string wholeName = yourName.assign(yourName);
    cout << wholeName << endl;
    
    string firstName = wholeName.assign(wholeName, 0, 5);
    cout << firstName << endl;
    
    int lastNameIndex = yourName.find("Clemons", 0);
    cout << "Index for last name " << lastNameIndex << endl;
    
    yourName.insert (5, " Sid");
    cout << yourName << endl;
    
    yourName.erase(6, 7);
    cout << yourName << endl;
    
    yourName.replace(6, 5, "Sami");
    cout << yourName << endl;
    
    //UNCOMMENT FOR STRINGS */
    
        
    //VECTORS.  Like arrays but size can change
    vector <int> lotteryNumVect(10);
    int lotteryNumArray[5] = {4, 13, 14, 24, 34};
    
    lotteryNumVect.insert(lotteryNumVect.begin(), lotteryNumArray, 
        lotteryNumArray+3);
        
    lotteryNumVect.insert(lotteryNumVect.begin()+5, 44);
    cout << lotteryNumVect.at(2) << endl;
    cout << lotteryNumVect.at(5) << endl;
    
    lotteryNumVect.push_back(64);
    cout << "First Value " << lotteryNumVect.front() << endl;
    cout << "Last Value " << lotteryNumVect.back() << endl;
    cout << "Size " << lotteryNumVect.size() << endl;
    
    lotteryNumVect.pop_back();
    
    //FUNCTIONS  ADD THEM BEFORE MAIN
    cout << addNumbers(1) << endl;
    cout << addNumbers(1, 5, 6) << endl;
    cout << "The factorial of 3 is " << getFactorial(3) << endl;
    
    
    //FILE I/O.  Test or machine readable binary
    string steveQuote = "A day without sunshine is like, you know, night";    
    ofstream writer("stevequote.txt");
    
    if(! writer){
        cout << "Error opening file" << endl;
        return -1;
        
    } else{
        writer << steveQuote << endl;
        cout << "File written successfully" << endl;
        writer.close();
    }        
    
    ofstream writer2("stevequote.txt", ios::app);
    
    // Open a stream to apppend to whats there with ios::app
    // ios::binary : Treat file as binary
    // ios::in : Open a file to read input
    // ios::trunc : Default
    // ios::out : Open a file to write output
    
    if(! writer2){
        cout << "Error opening file" << endl;
        return -1;

     } else{
         writer2 << "\n-Steve Martin" << endl;
         cout << "File written successfully" << endl;
         writer2.close();
     }
     
     char letter;
     ifstream reader("stevequote.txt");
     
     if(! reader){
        cout << "Error opening file" << endl;
        return -1;
    } else{
        
        for(int i = 0; ! reader.eof(); ++i){
        
            reader.get(letter);
            cout << letter;
        }
    }
    
    cout << endl;
    reader.close();
    
    
    //EXCEPTION HANDLING
    int number = 0;
    
    try{
        if(number != 0){
            cout << 2/number << endl;    
        
    } else throw(number);
    
    }
    
    catch(int number){
        cout << number << " is not valid" << endl;
    }
    
    //POINTERS
    int jennyAge = 35;
    char jennyGrade = 'A';
    
    cout << "Size of int " << sizeof(jennyAge) << endl;
    cout << "Size of char " << sizeof(jennyGrade) << endl;

    // & reference operator
    
    cout << "jennyAge is located at " << &jennyAge << endl;
    
    int* agePtr = &jennyAge;
    
    cout << "Address of pointer " << agePtr << endl;
    cout << "Data at memory address " << *agePtr << endl;
    
    
    int badNums2[5] = {4, 13, 14, 24, 34};
    int *numArrayPtr = badNums2;
    
    cout << "Address " << numArrayPtr << " Value " << *numArrayPtr << endl;
    numArrayPtr++;
    
    cout << "Address " << numArrayPtr << " Value " << *numArrayPtr << endl;                                                                          
    
    cout << "Address " << badNums2 << " Value " << *badNums2 << endl;
    
    // created two functions above main. makeMeYoung and actYourAge    
    makeMeYoung(&myAge);
    
    cout << "I'm " << myAge <<  " years old now" << endl;
    
    int& ageRef = myAge;
    cout << "myAge : " << myAge << endl;
    
    ageRef++;
    
    cout << "myAge : " << myAge << endl;
            
    actYourAge(ageRef);
    cout << "myAge : " << myAge << endl;    
    

    //OBJECT ORIENTED PROGRAMMING    
    //Created classes above main
    Animal sid;
    
    sid.setHeight(33);
    sid.setWeight(10);
    sid.setName("Sid");
    
    cout << sid.getName() << " is " << sid.getHeight() << 
        " cms tall and " << sid.getWeight() << " kgs in weight" << endl;
    
    Animal sami(36, 15, "Sami");

    cout << sami.getName() << " is " << sami.getHeight() <<
        " cms tall and " << sami.getWeight() << " kgs in weight" << endl;
                    
        
    Dog lulu(38, 16, "Lulu", "Woof");
    cout << "Number of Animals " << Animal::getNumOfAnimals() << endl;
    lulu.getSound();
    sid.toString();
    lulu.toString();
    
    lulu.Animal::toString();
        
    
    
    //VIRTUAL METHODS AND POLYMORPHISM
    //Created classes above main, and under OOB classes    
    Animal2 *animal = new Animal2;
    Giraffe *giraffe = new Giraffe;
        
    animal->getClass();
    giraffe->getClass();    
    
    whatClassAreYou(animal);
    whatClassAreYou(giraffe);
    
    Giraffe tallneck;
    PigmyGiraffe shortneck;
    
    Animal2* ptrGiraffe = &tallneck;
    Animal2* ptrPGiraffe = &shortneck;
    
    Animal2* ptrRhino = new Rhino;
    
    ptrGiraffe -> makeSound();
    ptrRhino -> makeSound();
    
    ptrGiraffe -> getFamily();
    ptrGiraffe -> getClass();
    
    ptrPGiraffe -> getFamily();
    ptrPGiraffe -> getClass();
    
    Car* stationWagon = new StationWagon();
    stationWagon -> getNumWheels();    
    stationWagon -> getNumDoors();
    
                                                    
    return 0;    
}
