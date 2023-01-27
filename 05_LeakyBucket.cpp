#include <iostream>
#include <vector>
using namespace std;

class packet{
public:
    int id, size;
};

class Bucket{
public:
    int bucketSize, leakRate, currSize;
    vector<packet> bucket;

    Bucket(int size, int leakRate){
        this->bucketSize = size;
        this->leakRate = leakRate;
        currSize = 0;
    }
   
    void leakyBucket(vector<packet> packets){
        cout << "pid " << "Packet_size  " << "  Accepted  " << "Sent  " << "Remaining" << endl;
        int i = 0;
        while(bucket.size() > 0 || i < packets.size()){
            if(i < packets.size()){
                packet p = packets[i++];
                cout << " " << p.id << "\t" << p.size << "\t\t";
                //Adding packet
                if(currSize + p.size <= bucketSize){
                    bucket.push_back(p);
                    currSize += p.size;

                    cout << p.size << "\t";
                }
                else 
                    cout << "Dropped\t";
            }
            else cout << " -\t-\t\t-\t";
            //Sending packets
            packet rm = bucket[0];
            if(rm.size >= leakRate){
                currSize -= leakRate;
                bucket[0].size -= leakRate;
                if(bucket[0].size == 0) bucket.erase(bucket.begin());
                cout << leakRate << "\t";
            }
            else{
                currSize -= rm.size;
                bucket.erase(bucket.begin());
                cout << rm.size << "\t";
            } 
            cout << currSize << endl;
        }
    }
};

int main() {
    vector<packet> packets;
    int n;
    // cout << "Enter no of packets : ";
    cin >> n;

    // cout << "Enter new packet id and size : ";
    for(int i = 0; i < n; i++){
        packet p;
        cin >> p.id >> p.size;
        packets.push_back(p);
    }
    
    int size, rate;
    // cout << "Enter size of bucket and leak rate : ";
    cin >> size >> rate;
    Bucket b(size, rate);

    b.leakyBucket(packets);
    
    return 0;
}
