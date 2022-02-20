/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include<list>
#include<bits/stdc++.h>
using namespace std;
template<typename T>
class linkedList{
    struct Node{
               T data;
               Node* prev;
               Node* next;
    };
    
    private:
           Node *head =NULL;
           Node *curr = NULL;
           int len = 0;
    public:
           void insert(T data){
               if(head=NULL){
                  Node node = new Node();
                  node.data = data;
                  node.prev = NULL;
                  head = &node;
                  curr = &node;
                  len++;
               }
               else{
                    Node node = new Node();
                    node.data = data;
                    node.prev = curr;
                    curr->next = &node;
                    curr = &node;
                    len++;
               }
           }
           bool deleteNode(int pos){
               if(head==NULL||size()<pos)
                    return false;
               Node* pNode=head;
               int num=0;
               while(pNode->next&&num<pos){
                    pNode = pNode->next;   
                    num++;
               }
               pNode->prev->next = pNode->next;//pNode's previous node points to pNode's next node
               pNode->next->prev = pNode->prev; //pNode's next node points to pNode's previous node
           
               return true;
           }
           bool deleteFinalNode(){
               if(head==NULL)
                   return false;
               (head+size()-2)->next =NULL; 
               return true;
           }
           int size(){
               return len;
           }
           
          
};

int main()
{
    string str1 ="waterbottle";
    string str2="erbottlewat";
    return 0;
}

