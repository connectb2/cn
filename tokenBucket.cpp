#include <iostream>
#include<chrono>
#include<thread>
using namespace std;
const int RATE=50;
const int CAPACITY=100;
int main()
{
    int tokens=0;
    while(true){
        this_thread::sleep_for(chrono::seconds(1));
        tokens+=RATE;
        if(tokens>CAPACITY){
            tokens=CAPACITY;
        }
        int tokens_needed=60;
        if(tokens>=tokens_needed){
            tokens-=tokens+tokens_needed;
            cout<<"Performed operations remaining tokens:"<<tokens<<endl;
        }
        else{
            cout<<"Not enoigh tokens needed to wait"<<endl;
        }
    }
    
    return 0;
}