#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <limits>
#include <ctime>
#include "CarGame.h"
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;
CarGame *BFS(CarGame *initial,long long &examined,long long &mem){
    cout<<"BFS STARTED..."<<endl;
    queue<CarGame *> agenda;
    vector <CarGame> closed;
    /*1*/
    agenda.push(initial);
    examined = 0;
    mem=1;
    /*2*/
    while (agenda.size()>0){
        //update mem
        if (agenda.size() + closed.size() > mem)
            mem = agenda.size() + closed.size();
        CarGame *s = agenda.front();
        agenda.pop();
        /*3*/
        if (find(closed.begin(), closed.end(), *s)==closed.end()){
            //update examined states
            examined++;
            /*4*/
            if (s->isSolved())
                return s;
            /*5*/
            closed.push_back(*s);
            /*6*/
            vector<CarGame *> children =s->expand();
            /*7*/
            for (unsigned int i=0;i<children.size();i++){
                if (find(closed.begin(), closed.end(), *children[i])==closed.end())
                    agenda.push(children[i]);
            }
        }
    }
    return nullptr;
}
int  main(){
    long long examined,mem;
    CarGame carGame;
    carGame.printBoard();
    cout<<"Enter number of cars"<<endl;
    int n,x,y;
    int v;
    cin>>n;
    for(int i=0;i<n;i++){
        cout<<"Enter x and y"<<endl;
        cin>>x;
        cin>>y;
        cout<<"Enter orientation (1 for vertical 2 for horizontal)"<<endl;
        cin>>v;
        if(v==1)carGame.newCar(Car (x,y, true));
        if(v==2)carGame.newCar(Car (x,y, false));
    }
    CarGame *initial=&carGame;
    cout<<"*****INITIAL BOARD*****"<<endl;
    initial->printBoard();
    CarGame *final=BFS(initial,examined,mem);
    cout<<"*****FINAL BOARD*****"<<endl;
    if(final!= nullptr) {
        final->printBoard();
        cout << "Mem: " << mem << ", Examined: " << examined << endl;
    }
}