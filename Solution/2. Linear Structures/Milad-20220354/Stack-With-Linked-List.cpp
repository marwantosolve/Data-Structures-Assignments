#include<bits/stdc++.h>
using namespace std;
#define Milad cin.tie(0), cout.tie(0), cin.sync_with_stdio(0), cout.sync_with_stdio(0);
typedef long long ll;
#define endl '\n'
# define all(x) x.begin(),x.end()
#define pb push_back
#define sz size()
ll gcd(ll a, ll b){if(b == 0) return a; return gcd(b, a%b);}
ll lcm(ll a, ll b){return a/gcd(a, b)*b;}
const int mod= 1e6+7;
template <typename t>
struct Node {
    t data;
    Node* next;
    Node(t ele):data(ele),next(nullptr){}
};
template<typename t>
class Stack{
private:
    Node<t>* topNode;
    int size;
public:
    Stack():topNode(nullptr),size(0){}

    void push(t ele){
        Node<t>* newnode=new Node<t>(ele);
        newnode->next=topNode;
        topNode=newnode;
        size++;
    }
    t pop(){
        if(isEmpty())
            cout<<"Stack is empty"<<endl;
        else{
            t popele=topNode->data;
            Node<t>* temp=topNode;
            topNode=topNode->next;
            delete temp;
            size--;
            return popele;
        }
    }
    t top(){
        if(isEmpty())
            cout<<"Stack is empty"<<endl;
        else{
            return topNode->data;
        }
    }
    bool isEmpty(){
        return topNode== nullptr;
    }
    int stackSize(){
        return size;
    }
    void clear(){
        while(!isEmpty())
            pop();
    }
    void print(){
        Node<t>* current=topNode;
        while(current!= nullptr){
            cout<<current->data<<" ";
            current=current->next;
        }
        cout<<endl;
    }

};

int main() {
    Milad

    Stack<int>ob;
    ob.push(10);
    ob.push(20);
    ob.push(40);

    cout<<"Top element : "<<ob.top()<<endl;
    cout<<"Stack Size : "<<ob.stackSize()<<endl;

    cout<<"Stack elements : ";
    ob.print();

    cout<<"Popped element : "<<ob.pop()<<endl;
    cout<<"Stack Size : "<<ob.stackSize()<<endl;

    ob.clear();
    cout<<"Stack size after clear : "<<ob.stackSize()<<endl;


    return 0;
}


