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
           Node *tail = NULL;
           int len=0;
    public:
           void insert(T data){
               if(head==NULL){
                  Node* node =new Node;
                  node->data = data;
                  node->prev = NULL;
                  node->next=NULL;
                  head = node;
                  tail = node;
                  len++;
               }
               else{
                    Node* node = new Node;
                    node->data = data;
                    node->prev = tail;
                    node->next = NULL;
                    tail->next = node;
                    tail = node;
                    len++;
               }
           }
           void insertFromArray(T arr[], size_t len){
                for(int i=0; i < len;i++){
                    insert(arr[i]);
                }
           }
           bool deleteNode(int pos){//delete certain node
               if(head==NULL||size()<pos)//list is null or pos > size of the list, return error
                    return false;
               Node* pNode=head;
               int num=0;
               while(pNode&&num < pos){//point to the deleting node
                    num++;
                    pNode = pNode->next;
               }
               if(pNode==tail){
                   deleteFinalNode();
               }
               else{
               pNode->prev->next = pNode->next;//pNode's previous node points to pNode's next node
               pNode->next->prev = pNode->prev; //pNode's next node points to pNode's previous node
               pNode = NULL;
               len--;
               }
               return true;
           }
           bool deleteFinalNode(){
               if(head==NULL)
                   return false;
               tail->prev->next = NULL;
               tail = tail->prev;
               len--;
               return true;
           }
           void showList(){
               Node* pNode;
               pNode = head;
               while(pNode){
                   cout << pNode->data <<endl;
                   pNode = pNode->next;
               }
           }
           int size(){
               return len;
           }
           
};

int main()
{
    linkedList<int> l;
    l.insert(0);
    l.insert(1);
    l.insert(2);
    l.insert(3);
    l.insert(4);
    l.showList();
    l.deleteFinalNode();
    l.showList();
    int arr[5]={4, 5, 6, 7, 8};
    l.insertFromArray(arr,5);
    l.showList();
    l.deleteNode(7);
    l.showList();
    return 0;
}

