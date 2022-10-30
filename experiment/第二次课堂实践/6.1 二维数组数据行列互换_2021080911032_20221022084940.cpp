#include<iostream>
using namespace std;
void tran(int array[5][3],int out_array[3][5]){
    if(array==NULL||out_array==NULL){
        cout<<"error"<<endl;
        return;
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<5;j++){
            out_array[i][j]=array[j][i];
        }
    }
}