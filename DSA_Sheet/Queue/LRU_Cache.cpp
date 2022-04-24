#include <iostream>
#include <map>
using namespace std;

// Using Build-in List STL
// Adding new (key, value) pair

// class LRUCache {
//     public:
//         list<int> ls;
//         map<int, list<int> :: iterator> mp;
//         int csize;
 
//     //Constructor for initializing the cache capacity with the given value.
//     LRUCache(int cap)
//     {
//         this->csize = cap;
//     }
    
//     //Function to return value corresponding to the key.
//     int get(int key)
//     {
//         // If value does not exits
//         if(mp.find(key))
//     }
    
//     //Function for storing key-value pair.
//     void set(int key, int value)
//     {
//         // If value does not exits
//         if(mp.find(value) == mp.end()){
            
//             // Insert a new value [check if capacity is reached]
            
//             if(ls.size() == csize){
                
//                 // Delete least recently used [last node in list]
//                 int last = ls.back();
                
//                 ls.pop_back();
                
//                 mp.erase(last);
//             }
//         }
//         else{
            
//             // If value exits [Move to front after deleting]
//             ls.earse(mp[value]);
//         }

//         ls.push_front(value);        
//         mp[value] = ls.begin();
//     }
// };

// Implementing from Scratch
class Node {

    public:
        int key;
        int value;
        Node* prev;
        Node* next;

    Node(int key, int value){

        this->key = key;
        this->value = value;
        this->prev = NULL;
        this->next = NULL;
    }
};

class Queue {

    public:
        int size;
        Node* front;
        Node* rear;

    Queue(){

        this->size = 0;
        this->front = NULL;
        this->rear = NULL;
    }

    void push_front(int key, int value){

        Node* newNode = new Node(key, value);

        if(front == NULL){

            front = newNode;
            rear = newNode;
        }
        else{

            newNode->next = front;
            front->prev = newNode;
            front = newNode;
        }

        size++;
    }

    void pop_back(){

        Node* store = rear;
        rear = rear->prev;

        if(rear != NULL)
            rear->next = NULL;
        else    
            front = NULL;

        size--;
        delete store;
    }

    void move_to_front(Node* curr){

        int key = curr->key;
        int value = curr->value;
        Node* itr1 = curr->prev;  // Can be NULL
        Node* itr2 = curr->next;  // Can be NULL

        // Delete Modification
        if(itr1 == NULL){

            // No need to delete anything [curr is front]
            return;
        }
        else if(itr2 == NULL){

            // Curr is Last
            Node* store = curr;
            rear = rear->prev;

            if(rear != NULL){

                rear->next = NULL;
            }

            delete store;
        }
        else{

            Node* store = curr;

            if(itr1 != NULL){

                itr1->next = itr2;
            }
            
            if(itr2 != NULL){

                itr2->prev = itr1;
            }
            

            delete store;
        }

        push_front(key, value);
    }

};

class LRUCache {

    public:
        int csize;
        Queue q;
        map<int, Node*> mp;

    LRUCache(int capacity)
    {
        this->csize = capacity;
    }

    void get(int key){

        // If does not exits return -1
        if(mp.find(key) == mp.end()){

            cout << "Does not exits in cache !" << endl;
        }
        else{

            // Update LRU Queue
            q.move_to_front(mp[key]);
            mp[key] = q.front;

            cout << "Value is : " << mp[key]->value << endl;
        }
    }

    void put(int key, int value){

        // Adding new (key, value) pair

        // If it does not exits
        if(mp.find(key) == mp.end()){

            // If capacity is reached
            if(q.size == csize){

                // Delete least recently used and move to front
                Node* last = q.rear;

                // Erase fron map
                mp.erase(last->key);
                q.pop_back();
            }

            // Add new (key, value) pair
            q.push_front(key, value);
            mp[key] = q.front;
        }
        else{

            // If already exits
            // Update Key, Value pair
            Node* get = mp[key];
            get->value = value;

            // Move to front
            q.move_to_front(mp[key]);
            mp[key] = q.front;
        }
    }
};

int main()
{
    
    // LRUCache lru(2);

    // lru.put(1, 1);
    // lru.put(2, 2);
    // lru.get(1);

    // lru.put(3, 3);
    // lru.get(2);

    // lru.put(4, 4);
    // lru.get(1);
    // lru.get(3);
    // lru.get(4);

    LRUCache lru(1);

    lru.get(6);
    lru.get(8);

    lru.put(12, 1);
    lru.get(2);

    lru.put(15, 11);
    lru.put(5, 2);
    lru.put(1, 15);
    lru.put(4, 2);
    lru.get(5);
    lru.put(15, 15);

    cout << endl;
    return 0;
}