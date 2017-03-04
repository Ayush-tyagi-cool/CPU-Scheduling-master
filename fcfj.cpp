#include<iostream>
#include<conio.h>
#include<vector>
#include<stdlib.h>

#define REP(i,a,b) for(i=(a);i<=(b);i++)

using namespace std;

typedef vector<int> vi;

int main()
{
    int i,x,n;
    vi burst_time,waiting_time;
    float avg_waiting = 0.0;
    
    cout<<"Enter number of processes :";
    cin>>n;
    
    REP(i,0,n-1){
       cout<<"\nEnter burst time of process "<<i+1<<" (in sec): ";
       cin>>x;
       burst_time.push_back(x);                                       
    }    

    waiting_time.push_back(0);          //since first process will have process time 0 only
    
    REP(i,1,burst_time.size()-1)
       waiting_time.push_back( waiting_time[i-1] + burst_time[i] );
       
    system("cls");
    
    cout<<"\nProcess\t| Burst time\t| Wait time\n-------------------------------------";
    
    REP(i,0,burst_time.size()-1){
       cout<<"\n"<<i+1<<"\t| "<<burst_time[i]<<"\t\t| "<<waiting_time[i];
       avg_waiting += waiting_time[i];   
    }

    cout<<"\n-------------------------------------\n\t\t\t| "<<avg_waiting<<"\n-------------------------------------\n\naverage wait period : "<<avg_waiting/n<<" sec";
    
getch();

return 0;
}
