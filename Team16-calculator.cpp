#include <iostream>
using namespace std;

// Converting Roman numerals into integers
int value(char roman) { 
    switch(roman) {
    case 'I':return 1;
    case 'V':return 5;
    case 'X':return 10;
    case 'L':return 50;
    case 'C':return 100;
    }
return 0;
}
int RomanToInt(string A)  {
    int i,l, ans=0,p=0;
    string valid;
    l=A.length();
    // Checking the validity of Roman numerals
    for (i=0;i<l;i++) {
        if ( (value(A[i]) == 0) 
        || ((A[i] == A[i+1]) && (A[i] == A[i+2]) && (A[i] == A[i+3]) && (A[i] == 'X'))
        || ((A[i] == A[i+1]) && (A[i] == A[i+2]) && (A[i] == A[i+3]) && (A[i] == 'I')) 
        || (A[i] == 'V' && A[i+1] == 'V') 
        || (A[i] == 'L' && A[i+1] == 'L') 
        || (A[i] == 'C' && A[i+1] == 'C')) {
            valid = "no";
        }
    }
    if(valid != "no") {
     for (i=l-1;i>=0;i--) {
        if (value(A[i])>=p)
        ans=ans+value(A[i]);
        else ans=ans-value(A[i]);
       p=value(A[i]);
    }} else {
        ans = 0;
    }
       return ans;
}

// Converting integers into Roman numerals 
string intToRoman(int n) {
        string romans[] = {"C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        int values[] = {100, 90, 50, 40, 10, 9, 5, 4, 1};
        string result = "";
        for (int i = 0; i < 9; i++) {
            while(n - values[i] >= 0) {
                result += romans[i];
                n -= values[i];
            }
        }
        return result;
}

// Calculator
int main() {
        string s,m,ope;
        int answer;
        cout<<"Please enter first Roman numeral: ";
        cin>>s;
        // Asking user to enter Roman numeral until it is correct
        while(RomanToInt(s) == 0) {
            cout<<"This numeral is incorrect, please enter again: ";
            cin>>s;
        }
        answer = RomanToInt(s);
        while (true) {
            cout<<"Please enter operator: ";
            cin>>ope;
            // Calculate the results until user types "exit"
            if (ope != "exit") {
                cout<<"Please enter next Roman numeral: ";
                cin>>m;
                if (m != "exit") {
                    while(RomanToInt(m) == 0) {
                    cout<<"This numeral is incorrect, please enter again: ";
                    cin>>m;
                    }
                if(ope == "+") {
                    answer=answer+RomanToInt(m);
                } else if (ope == "-") {
                    answer=answer-RomanToInt(m);
                } else if(ope == "*") {
                   answer=answer*RomanToInt(m);
                } else if(ope == "/") {
                    answer=answer/RomanToInt(m);
                }
                } else {
                    break;
                }
            } else {
                break;
            }
        }
             cout<<intToRoman(answer)<<"\n";
             return 0;
}
