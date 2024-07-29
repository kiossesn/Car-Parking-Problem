#define WIDTH 4
#define HEIGHT 3
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <utility>
#include <algorithm>
#include <queue>
#include "Car.h"
using namespace std;

//Represents a state of the game
class CarGame {
private:
    char board[WIDTH][HEIGHT];
    bool free[WIDTH][HEIGHT];
    vector<Car> cars;

public:
    //Creates the grid and the randomly placed n(random) obstacles.
    CarGame() {
        //initialize the grid with empty spaces
        for (int j = HEIGHT-1; j >=0; j--) {
            for (int i = 0; i<WIDTH ; i++) {
                free[i][j] = true;
                board[i][j]='O';
            }
        }
        //create n random obstacles
        srand(time(nullptr));
        int numOfObstacles = rand() % 5;
        vector<pair<int, int>> pairs;
        for (int i = 0; i < numOfObstacles; i++) {
            pair<int, int> new_pair;
            do {
                new_pair.first = rand() % 4;
                new_pair.second = rand() % 3;
            } while (find(pairs.begin(), pairs.end(), new_pair) != pairs.end());
            // add the new pair to the list
            pairs.push_back(new_pair);
            //print the position of the obstacle
            cout<<"Obstacle "<<i+1<<": "<<endl;
            cout<<"     "<<new_pair.first<<endl;
            cout<<"     "<<new_pair.second<<endl;
            //update free[][] and board[][]
            free[new_pair.first][new_pair.second]= false;
            board[new_pair.first][new_pair.second]='X';
        }
        cout<<"Board made"<<endl;
    }
    //Tells if the problem is solved. (if there is no '|' or '-' in the array board)
    bool isSolved() {
        for (int j = HEIGHT-1; j >=0; j--) {
            for (int i = 0; i<WIDTH ; i++) {
                if(board[i][j]=='|' || board[i][j]=='-'){
                    cout<<"Problem not yet solved!"<<endl;
                    return false;
                }
            }
        }
        cout<<"Problem solved!"<<endl;
        return true;
    }
    //Puts a new car on the grid and in vector<Car> cars.
    bool newCar(Car car){
        //position not empty
        if(!free[car.getX()][car.getY()]){
            cout<<"You can't place the car on ["<<car.getX()<<","<<car.getY()<<"]. Space not empty!"<<endl;
            return false;
        }
        else{
            //vertical car
            if(car.getOrientation()){
                setFree(car.getX(),car.getY(),false,true);
                cars.push_back(car);
            }
            //horizontal car
            else {
                setFree(car.getX(),car.getY(),false,false);
                cars.push_back(car);
            }
            return true;
        }

    }
    //Changes the free matrix and the board matrix (when a move is done).
    void setFree(int x, int y, bool f, bool isVertical){
        if(!(x<0 || y<0 || x>=WIDTH || y>=HEIGHT)){
            free[x][y]=f;
            if (!f) {
                if (isVertical)board[x][y] = '|';
                else board[x][y] = '-';
            } else {
                board[x][y] = 'O';
            }
        }
    }
    //Tells if a move can be done. (1. there is a car to move 2. it has the right orientation 3. there is no other car or obstacle in the way)
    bool moveCanBeDone(string actionName, Car car){
        if(free[car.getX()][car.getY()]){
            cout<<"There is no car to move!"<<endl<<endl;
            return false;
        }
        if(actionName=="Up"){
            cout<<"Trying moving up..."<<endl;
            if(car.getOrientation() && (isFree(car.getX(),car.getY()+1) || car.getY()+1>=HEIGHT))return true;
        }
        if(actionName=="Down"){
            cout<<"Trying moving down..."<<endl;
            if(car.getOrientation() && (isFree(car.getX(),car.getY()-1) || car.getY()-1<0))return true;
        }
        if(actionName=="Right"){
            cout<<"Trying moving right..."<<endl;
            if(!car.getOrientation() && (isFree(car.getX()+1,car.getY()) || car.getX()+1>=WIDTH))return true;
        }
        if(actionName=="Left"){
            cout<<"Trying moving left..."<<endl;
            if(!car.getOrientation() && (isFree(car.getX()-1,car.getY()) || car.getX()-1<0))return true;
        }
        cout<<"Couldn't make the move!"<<endl<<endl;
        return false;
    }
    //Movement upwards
    bool goN(Car &car){
        //make the move
        int k=car.getY()+1;
        car.setY(k);
        //if the car is out of board make it true
        car.setIsOut();
        //set the free table (don't forget old position to true)
        setFree(car.getX(),car.getY(), false,car.getOrientation());
        setFree(car.getX(),car.getY()-1, true, car.getOrientation());
        //if the car is out of the board remove it from vector cars
        if(car.getIsOut()) {
            auto it= find(cars.begin(),cars.end(),car);
            if (it != cars.end()) {
                cars.erase(it);
            }
        }

        cout<<"Move up done"<<endl;
    }
    //Movement downwards
    bool goS(Car &car){
        //make the move
        int k=car.getY()-1;
        car.setY(k);
        //if the car is out of board make it true
        car.setIsOut();
        //set the free table (don't forget old position to true)
        setFree(car.getX(),car.getY(), false,car.getOrientation());
        setFree(car.getX(),car.getY()+1,true,car.getOrientation());
        //if the car is out of the board remove it from vector cars
        if(car.getIsOut()) {
            auto it= find(cars.begin(),cars.end(),car);
            if (it != cars.end()) {
                cars.erase(it);
            }
        }
        cout<<"Move down done"<<endl;
    }
    //Movement right
    void goE(Car &car){
        //make the move
        int k=car.getX()+1;
        car.setX(k);
        //if the car is out of board make it true
        car.setIsOut();
        //set the free table (don't forget old position to true)
        setFree(car.getX(),car.getY(), false,car.getOrientation());
        setFree(car.getX()-1,car.getY(),true,car.getOrientation());
        //if the car is out of the board remove it from vector cars
        if(car.getIsOut()) {
            auto it= find(cars.begin(),cars.end(),car);
            if (it != cars.end()) {
                cars.erase(it);
            }
        }
        cout<<"Move right done"<<endl;
    }
    //Movement left.
    bool goW(Car &car){
        //make the move
        int k=car.getX()-1;
        car.setX(k);
        //if the car is out of board make it true
        car.setIsOut();
        //set the free table (don't forget old position to true)
        setFree(car.getX(),car.getY(), false,car.getOrientation());
        setFree(car.getX()+1,car.getY(),true,car.getOrientation());
        //set the free table (don't forget old position to true)
        if(car.getIsOut()) {
            auto it= find(cars.begin(),cars.end(),car);
            if (it != cars.end()) {
                cars.erase(it);
            }
        }
        cout<<"Move left done"<<endl;
    }
    //Tells if a spot on the grid is free.
    bool isFree(int x,int y)const{
        if(free[x][y])return true;
        else return false;
    }
    //Prints a representation of the board.
    void printBoard(){
        for (int j = HEIGHT-1; j >=0; j--) {
            for (int i = 0; i <WIDTH; i++) {
                cout<<board[i][j]<<"  ";
            }
            cout<<endl;
        }
        cout<<endl;
    }
    //Returns a vector that contains all the different possible next states.
    vector<CarGame *> expand()  {
        //print current state
        cout<<"EXPAND this state: "<<endl;
        this->printBoard();
        CarGame current=*this;
        //make vector to return the children of the current state
        vector<CarGame *> children;
        CarGame *child;
        //for every car in vector of current's state cars
        for (int i = 0; i<current.cars.size();i++) {
            //if car is vertical
            if(cars.at(i).getOrientation()) {
                //make a child taking the current positions of the cars on the board
                child = new CarGame(current);
                //if move up can be done
                if (moveCanBeDone("Up", current.cars.at(i))) {
                    //make the move
                    child->goN(child->cars.at(i));
                    //print the child's board
                    child->printBoard();
                    //put child into children
                    children.push_back(child);
                } else delete child;

                //make a child taking the current positions of the cars on the board
                child = new CarGame(current);
                if (moveCanBeDone("Down", current.cars.at(i))) {
                    //make the move
                    child->goS(child->cars.at(i));
                    //print the child's board
                    child->printBoard();
                    //put child into children
                    children.push_back(child);
                } else delete child;
            }
            else{
                //make a child taking the current positions of the cars on the board
                child = new CarGame(current);
                //if move up can be done
                if (moveCanBeDone("Right", current.cars.at(i))) {
                    //make the move
                    child->goE(child->cars.at(i));
                    //print the child's board
                    child->printBoard();
                    //put child into children
                    children.push_back(child);
                } else delete child;

                //make a child taking the current positions of the cars on the board
                child = new CarGame(current);
                if (moveCanBeDone("Left", current.cars.at(i))) {
                    //make the move
                    child->goW(child->cars.at(i));
                    //print the child's board
                    child->printBoard();
                    //put child into children
                    children.push_back(child);
                } else delete child;
            }

        }
        cout<<"--------------------------------------------"<<endl<<endl;
        return children;
    }
    //Compares two states
    bool operator==(const CarGame state) const {
        for (int j = HEIGHT-1; j >=0; j--) {
            for (int i = 0; i<WIDTH ; i++) {
                if(board[i][j] != state.board[i][j]) return false;
            }
        }
        return true;
    }

};






