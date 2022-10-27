#include <iostream>
int main()
{
    using namespace std;
    int number[10];
    int count = 0;
    for (int i = 0; i < 10; i++)
    {
        cin >> number[i];
        if (number[i] < 0)
        {
            break;
        }
        ++count;
    }
    /* for(int i=0;i<count;i++){
        cout<<number[i]<<" ";
    } */
    int temp;
    for (int i = 0; i < count - 1; i++)
    {
        for (int j = 0; j < count - i - 1; j++)
        {
            if (number[j] > number[j + 1])
            {
                temp = number[j];
                number[j] = number[j + 1];
                number[j + 1] = temp;
            }
        }
    }
    for (int i = 0; i < count; i++)
    {
        if (number[i]%2!=0){
            cout << number[i] << " ";
        }
    }for (int i = 0; i < count; i++)
    {
        if (number[i]%2==0){
            cout << number[i] << " ";
        }
    }
}