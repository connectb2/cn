#include<iostream>
using namespace std;

#define QUEUE_SIZE 15
#define MAX_PACKETS 20
#define MIN_PROBABILITY 0.3
#define MAX_PROBABILITY 0.7

double rand_doublt(int min, int max){
    return min + (max-min) * (double) rand() / RAND_MAX; 
}

int main(){
    srand(time(0));
    int queueSize = 0;
    double dropProbability = MIN_PROBABILITY;

    for(int i = 0; i < MAX_PACKETS; i++){
        if(queueSize == QUEUE_SIZE){
            cout << "Packet dropped (Queue Full)" << endl;
            dropProbability = MIN_PROBABILITY;
        }
        else if(rand_doublt(0, 1) < dropProbability){
            cout << "Packet dropped Random" << endl;
            dropProbability += (MAX_PROBABILITY - MIN_PROBABILITY) / (MAX_PACKETS -1);
        }
        else{
            cout << "Packet Accepted" << endl;
            dropProbability = MIN_PROBABILITY;
            queueSize++;
        }
        
    }
}

