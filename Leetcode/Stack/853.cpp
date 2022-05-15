#include<bits/stdc++.h>
using namespace std;


class Car{
public:
    Car(int pos, int speed){
        this->pos = pos;
        this->speed= speed;
    }
    int pos;
    int speed;
};



int32_t main(){
    
    vector<int>position,speed;

    int x,n,i,j,target;
    
    cin>>n>>target;
    
    for(int i=0;i<n;i++){
        cin>>x;
        position.push_back(x);
    }

    for(int i=0;i<n;i++){
        cin>>x;
        speed.push_back(x);
    }





    vector<Car> cars;
        int N = position.size();
        for(int i = 0; i<N; i++){
            cars.push_back(Car(position[i], speed[i]));
        }
        
        sort(cars.begin(), cars.end(), [](const Car& a, const Car& b){
            return a.pos<b.pos;
        });
        
        stack<float> mono;
        for(int i = 0; i<N; i++){
            float time = 
                (target-cars.at(i).pos)/(float)cars.at(i).speed;
            while(!mono.empty() && time >= mono.top()){
                mono.pop();
            }
            mono.push(time);
        }
        return mono.size();

    return 0;
}