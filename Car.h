#define WIDTH 4
#define HEIGHT 3
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <utility>
#include <algorithm>
#include <queue>
using namespace std;

//Represents a car. Has vertical or horizontal orientation.
class Car{
private:
    //position
    int x,y;
    //true=vertical, false=horizontal
    bool isVertical;
    //tells if it's in the grid or out
    bool isOut;
public:
    Car(int x,int y,bool isVertical){
        this->x=x;
        this->y=y;
        this->isVertical=isVertical;
        setIsOut();

        cout<<"position ["<<x<<","<<y<<"]";
        if(isOut)cout<<"(outside)"<<endl;
        else cout<<"(inside)"<<endl;
        if(isVertical)cout<<"orientation |"<<endl;
        else cout<<"orientation --"<<endl;
        cout<<endl;
    }
    void setX(int x){
        this->x=x;
    }
    void setY(int y){
        this->y=y;
    }
    void setOrientation(bool isVertical){
        this->isVertical=isVertical;
    }
    //Tells if the car is in or out the grid
    void setIsOut(){
        if(x<0 || y<0 || x>=WIDTH || y>=HEIGHT) isOut= true;
        else isOut= false;
    }
    int getX()const{
        return x;
    }
    int getY()const{
        return y;
    }
    bool getOrientation() const {
        return isVertical;
    }
    bool getIsOut(){
        if(x<0 || y<0 || x>=WIDTH || y>=HEIGHT) return true;
        else return false;
    }
    Car operator= (Car o){
        x = o.x;
        y = o.y;
        isVertical=o.isVertical;
        isOut=o.isOut;
        return *this;
    }
    bool operator==(const Car& s) const
    {
        return (x==s.x && y==s.y && isVertical==s.isVertical && isOut==s.isOut);
    }
};