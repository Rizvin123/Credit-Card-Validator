#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

bool isNumberString(string s){
    int n = s.size();
    for(auto i = 0; i<n; i++) if(s[i] < '0' || s[i] > '9') return false;
    return true;
}

int main(){
    string ccNumber;

    cout << "This program uses the Luhn Algorigthm to validate a CC number.\n";
    cout << "You can enter 'exit' anytime to quit.\n";

    while(true){
        cout << "Please enter a CC number to validate: ";
        cin>>ccNumber;

        if(ccNumber == "exit") break;

        else if(!isNumberString(ccNumber)){
            cout<<"Bad Input ! \n";
            continue;
        }

        int len = ccNumber.size();
        int doubleEvenSum = 0;

        // Step 1 is to double every second digit, starting from the right. If it
        // results in a two digit number, add both the digits to obtain a single
        // digit number. Finally, sum all the answers to obtain 'doubleEvenSum'.   


        for(auto i=len - 2; i>=0; i-=2){
            int dbl = (ccNumber[i] - '0')*2;
            if(dbl > 9){
                dbl = (dbl%10) + (dbl/10);
            }
            doubleEvenSum +=dbl;
        }

        // Step 2 is to add every odd placed digit from the right to the value
        // 'doubleEvenSum'.

        for (int i = len - 1; i >= 0; i -= 2) {
            doubleEvenSum += (ccNumber[i] - '0');
        }

        // Step 3 is to check if the final 'doubleEvenSum' is a multiple of 10.
        // If yes, it is a valid CC number. Otherwise, not.
        
        cout << (doubleEvenSum % 10 == 0 ? "Valid" : "Invalid!")<<"\n";

        continue;
    }

    return 0;
}