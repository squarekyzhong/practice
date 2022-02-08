#include <iostream>

using namespace std;
class Node{
    private:
	    Node *next;
	    int data;
	public: 
	   Node(int d){
	         data = d;
	}

       int getData(){
		     return data;
	}
	   Node* getNextNode(){
	       return this->next;
	   }
	
	   void appendToTail(int d){
		    Node* end = new Node(d);
		    Node *n = this;
		    while(n->next!=NULL){
		        n = n->next;
		    }
		    n->next = end;
	}
     
};
int main(){

   Node* fir = new Node(0);
   fir->appendToTail(1);
   fir->appendToTail(2);
   fir->appendToTail(3);
   while(fir->getNextNode()!=NULL){
       fir = fir->getNextNode();
       cout << fir->getData()<<endl;
   }

}
