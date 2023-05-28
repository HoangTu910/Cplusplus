#include <iostream>
#include <cmath>

using namespace std;

int beautifulDays(int i, int j, int k) {
    int reverse, left;
    int count = 0;
    for(int start = i; start <= j; start++){
        int startDay = start;
        if(start >= 10){
            while(startDay > 0){
                left = startDay % 10;
                reverse = reverse * 10 + left;
                startDay = startDay / 10;
            }
        }
        else{
            reverse = start;
        }
        
        if(((reverse - start))%k == 0){
            count++;
        }
    }
    
    return count;
    
}

int main(){
    int i, j, k;
    i = 20;
    j = 23;
    k = 6;

    cout << beautifulDays(i, j, k) << endl;
}