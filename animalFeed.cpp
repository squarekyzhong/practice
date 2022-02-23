#include <iostream>
#include<list>
#include<stack>
#include<bits/stdc++.h>
#include<cstdlib>
#include<time.h>
using namespace std;
class Animal{
    private:
           int order;
           string name;
    public:
          Animal(string n){
              this->name = n;
          }
          
          void setOrder(int order){
              this->order = order;
          }
          
          int getOrder(){
              return order;
          }
          
          bool isOlderThan(Animal a){
              return this->order>a.getOrder();
          }
};

class Dog:public Animal{
    public:
          Dog(string n):Animal(n){
          }
};

class Cat:public Animal{
    public:
         Cat(string n):Animal(n){
         }
};

class animalQueue{
    private:
        list<Dog*> dogs;
        list<Cat*> cats;
        int order = 0;
    public:
          void push_back(Animal* a){
              a->setOrder(order);
              order++;
              if(typeid(a)==typeid(Dog*)){
                  //dogs.push_back(a);
              }
              else{
                  //cats.push_back(a)
              }
          }
          
          Animal pop_front(){
              
              return NULL;
          }
          
          Dog dog_pop(){
           return NULL;   
          }
          
          Cat cat_pop(){
           return NULL;   
          }
          
};
int main()
{ 
    string dog1="dog1";
    Animal* dog = new Dog(dog1);
    return 0;
}

    
