#include <bits/stdc++.h>
using namespace std;
 
long long type, number, fact[20];
int indexes[100005], indexOfI;

long long turnIntoFactorial(int n) {
    long long turned = 1;
    for(int i = 1; i <= n; i++) {
        turned *= i;
    }

    return turned;
}
 
int main(){
    
    ifstream read("bazaf.in");
	ofstream print("bazaf.out");
    
    read >> type;

    if(type == 1) {
        read >> number;

        int stop;
        for(stop = 1; stop <= 19; stop++) {
            long long s = turnIntoFactorial(stop);

            if(s > number) {
                break;
            } else {
                fact[stop] = s;
            }
        }
        stop--;
        print << stop <<" ";

        for(int i = stop; i >= 1; i--) {
            int times = number / fact[i];

            if(times != 0 && number != 0) {
                number = number - times*fact[i];
                indexes[i] = times;
            }
        }
        for(int i = 1; i <= stop; i++) {
            print << indexes[i] << " ";
        }
    } else {
        read >> number;
        long long calculate = 0;
        for(int i = 1; i <= number; i++) {
            read >> indexes[i];
        }
        for(int i = 1; i <= number && indexes[number] > 0; i++) {
          indexes[i + 1] += indexes[i] / (i + 1);
          indexes[i] %= (i + 1);
          if(i >= number) {
            number++;
          }
        }
        if(indexes[number] == 0) {
          number--;
        }
        print << number << " ";
        for(int i = 1; i <= number; i++) {
            print << indexes[i] << " ";
        }
         
    }
}