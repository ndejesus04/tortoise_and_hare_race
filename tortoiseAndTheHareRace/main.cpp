/*
 (Simulation: The Tortoise and the Hare) In this exercise, you’ll re-create the classic race of
 the tortoise and the hare. You’ll use random number generation to develop a simulation of this memorable event.
 Our contenders begin the race at “square 1” of 70 squares. Each square represents a possible position along the race course. The finish line is at square 70. The first contender to reach or pass square 70 is rewarded with a pail of fresh carrots and lettuce. The course weaves its way up the side of a slippery mountain, so occasionally the contenders lose ground.
 There is a clock that ticks once per second. With each tick of the clock, your program should use function moveTortoise and moveHare to adjust the position of the animals according to the rules in Fig. 8.21. These functions should use pointer-based pass-by-reference to modify the posi- tion of the tortoise and the hare.
 Percentage of
 Animal Move type the time Actual move
 Tortoise Fast plod 50% 3 squares to the right
 Slip 20% 6 squares to the left
 Slow plod 30% 1 square to the right
 Hare Sleep 20% No move at all
 Big hop 20% 9 squares to the right
 Big slip 10% 12 squares to the left
 Small hop 30% 1 square to the right
 Small slip 20% 2 squares to the left
 
 
 Generate the percentages in the preceding table by producing a random integer, i, in the range 1 ≤i ≤10. For the tortoise, perform a “fast plod” when 1 ≤i ≤5, a “slip” when 6 ≤i ≤7, or a “slow plod” when 8 ≤i ≤10. Use a similar technique to move the hare.
 
 */

//
//  main.cpp
//  tortoiseAndTheHareRace
//
//  Created by Nyvia DeJesus on 3/7/16.
//  Copyright © 2016 CSCI272. All rights reserved.
//

#include <iostream>
#include <stdlib.h> //srand, rand
#include <time.h> //time
#include <stdio.h>//NULL
#include <iomanip>
#include <ctime>
using namespace std;

void haresTurn(int x, int& hare)
{
    x = rand() % 10 +1;
    int *h = &hare;
    
    if(x>=1 && x<=2)
        *h += 0;//hare is asleep no move
    if(x>=3 && x<=4)
        *h +=9;//big hop
    if(x==5)
        *h -=12;//big slip
    if(x>=6 && x<= 8)
        *h +=1;//small hop
    if(x>=9 && x <=10)
        *h -=2;//small slip
    
    else if (*h >=70)
        *h = 70;
}
void tortoisesTurn(int x, int& tortoise)
{
    x = rand() % 10 +1;
    int *t = &tortoise;
    
    if(x>=1 && x<= 5)
        *t += 3;//fast plod
    if(x>=6 && x<=7)
        *t -=6;//slip
    if(x>=8 && x<=10)
        *t += 1;//slow plod
    else if (*t >=70)
        *t = 70;
}
void positions(int *h,int *t)
{
    if ( *h == *t)
        cout << setw( *h ) << "Ouch!!!";// they landed at the same spot
    
    else if ( *h < *t)
        cout << setw( *h ) << "H" << setw( *t - *h ) << "T";
    
    else
        cout << setw( *t ) << "T"
<< setw( *h - *t ) << "H";
    
    cout << "\n";
    
}

int main()
{
    srand(time(NULL));//Initializes random seed
    int randInt;
    int hare = 0;
    int tortoise = 0;
    int count = 0;
    
    cout<<"BANG !!!!! \nAND THEY'RE OFF !!!!!"<<endl;
    
    do{
        haresTurn(randInt, hare);
        tortoisesTurn(randInt, tortoise);
        
        positions(&hare, &tortoise);//to call the postions functions so they print out the positions like a real race
        count++;//see how many times the loop runs
    }while(hare <70 && tortoise <70 );
    
    if(hare >= 70)
        cout<<"The Hare wins "<<endl;
    if(tortoise>= 70)
        cout<<"The Tortoise Wins"<<endl;
    cout<<"The loop went "<< count<< " times"<<endl;
    
    //system("pause");
    return 0;
}