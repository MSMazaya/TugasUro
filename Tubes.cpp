#include<iostream>
#include<vector>
#include<algorithm>
#include <time.h>
#include <stdlib.h> 
using namespace std;

class Robot{
    public:
        pair<int,int> coordinate;
        pair<int,int> boundary;
        void init(pair<int,int> mapsize){ 
            coordinate=make_pair(0,0);
            boundary=mapsize;
        }
        string gerak(string gerak){
            int *x = &coordinate.first;
            int *y = &coordinate.second;
            if(gerak == "kanan"){
                if(*x == boundary.first-1) return "Melebihi map\n";
                *x += 1; 
            } else if(gerak == "kiri") {
                if(*x == 0) return "Melebihi map\n";
                *x -= 1;
            } else if(gerak=="atas") {
                if(*y == boundary.second-1) return "Melebihi map\n";
                *y += 1;
            } else if(gerak=="bawah"){
                if(*y == 0) return "Melebihi map\n";
                *y -= 1;
            } else {
                return "Input tidak valid!\n";
            }
            return "";
        }
};

class Kecoa{
    public:
        pair<int,int> coordinate;
        void init(pair<int,int> mapsize){
            srand ( time(NULL) );
            while(coordinate == make_pair(0,0)){
                coordinate.first = rand() % mapsize.first;
                coordinate.second = rand() % mapsize.second;
            }
            cout << coordinate.first << coordinate.second;
        }
};

class Game{
    public:
        Robot *robot;
        Kecoa *kecoa;
        pair<int,int> size;
        void showMap(){
            for(int i = size.first-1;i>-1;i--){
                for(int j = 0;j<size.second;j++){
                    if(j == (*robot).coordinate.first && i == (*robot).coordinate.second){
                        cout << "# ";
                        continue;
                    }else if(j == (*kecoa).coordinate.first && i == (*kecoa).coordinate.second){
                        cout << "X ";
                    } else{
                        cout << "_ ";
                    }
                }
                cout << endl;
            }
            cout << endl;
        }
        void init(Robot *input_robot,Kecoa *input_kecoa,pair<int,int> mapsize){
            robot = &(*input_robot);
            kecoa = &(*input_kecoa);
            size = mapsize;
            (*robot).init(size);
            (*kecoa).init(size);
        }
};


int main(){
    Robot anu;
    Kecoa kecoa;
    Game game;
    game.init(&anu,&kecoa,make_pair(10,10));
    while(true){
        string input;
        cout << "Pilih gerakan : ";
        cin >> input;
        string error = anu.gerak(input);
        if(error != ""){
            cout << error << endl;
        } else {
             game.showMap();
        }
    }
    
}