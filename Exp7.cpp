#include <iostream>
using namespace std;

void towerofHanoi(int n, char beg,char aux, char end){
    
    if(n==1){
        cout<<"Move disk 1 from "<<beg<<" to "<<end<<endl;
        return;
    }
    towerofHanoi(n-1,beg,end,aux);
    cout<<"Move disk "<<n<<" from "<<beg<<" to "<<end<<endl;
    towerofHanoi(n-1,aux,beg,end);
}

int main(){
    int n;
    cout<<"Enter the number of disks: ";
    cin>>n;
    towerofHanoi(n,'A','B','C');
    return 0;
}