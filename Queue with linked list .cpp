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
class Queue{
private:
    Node<t>* frontNode;
    Node<t>* rearNode;
    int size;
public:
    Queue():frontNode(nullptr),rearNode(nullptr),size(0){}

    void enqueue(t ele){
        Node<t>* newnode=new Node<t>(ele);
        if(isEmpty()) {
            frontNode = newnode;
            rearNode = newnode;
        }else{
            rearNode->next=newnode;
            rearNode=newnode;
        }
        size++;
    }
    t dequeue(){
        if(isEmpty())
            cout<<"Queue is empty"<<endl;
        else{
            t popele=frontNode->data;
            Node<t>* temp=frontNode;
            frontNode=frontNode->next;
            if(frontNode== nullptr)
                rearNode= nullptr;
            delete temp;
            size--;
            return popele;
        }
    }
    t first(){
        if(isEmpty())
            cout<<"Queue is empty"<<endl;
        else{
            return frontNode->data;
        }
    }
    bool isEmpty(){
        return frontNode== nullptr;
    }
    int QueueSize(){
        return size;
    }
    void clear(){
        while(!isEmpty())
            dequeue();
    }
    void print(){
        Node<t>* current=frontNode;
        while(current!= nullptr){
            cout<<current->data<<" ";
            current=current->next;
        }
        cout<<endl;
    }

};

int main() {
    Milad

    Queue<int>ob;
    ob.enqueue(10);
    ob.enqueue(20);
    ob.enqueue(40);

    cout<<"Top element : "<<ob.first()<<endl;
    cout<<"Queue Size : "<<ob.QueueSize()<<endl;

    cout<<"Queue elements : ";
    ob.print();

    cout<<"Popped element : "<<ob.dequeue()<<endl;
    cout<<"Queue Size : "<<ob.QueueSize()<<endl;

    ob.clear();
    cout<<"Queue size after clear : "<<ob.QueueSize()<<endl;


    return 0;
}


