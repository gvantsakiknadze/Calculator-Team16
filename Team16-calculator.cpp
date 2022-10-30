#include <iostream>
using namespace std;

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
int RomanToInt(string A)
 {
    int i,l, ans=0,p=0;
    string valid;
    l=A.length();
    for (i=0;i<l;i++) {
        if (value(A[i]) == 0) {
            valid = "no";
        }
        if ((A[i] == A[i+1]) && (A[i] == A[i+2]) && (A[i] == A[i+3]) && (A[i] == 'X' )) {
            valid = "no";
        }
        if ((A[i] == A[i+1]) && (A[i] == A[i+2]) && (A[i] == A[i+3]) && (A[i] == 'I')) {
            valid = "no";
        }
        if (A[i] == 'V' && A[i+1] == 'V') {
            valid = "no";
        }
        if (A[i] == 'L' && A[i+1] == 'L') {
            valid = "no";
        }
        if (A[i] == 'C' && A[i+1] == 'C') {
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

string intToRoman(int n)
{
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

int main()
 {
        string s,m,ope;
        int answer;
        cout<<"please enter first roman number: ";
        cin>>s;
        while(RomanToInt(s) == 0) {
            cout<<"This number is incorrect, please enter again: ";
            cin>>s;
        }
        answer = RomanToInt(s);
        while ( (ope != "exit") && (m != "exit") ) {
            cout<<"please enter operator: ";
            cin>>ope;
            if (ope != "exit") {
                cout<<"please enter next roman number: ";
                cin>>m;
                if (m != "exit") {
                while(RomanToInt(m) == 0) {
                    cout<<"This number is incorrect, please enter again: ";
                    cin>>m;
                    }
                }
            }
            if (ope != "exit" && m != "exit") {
                if(ope == "+") {
                    answer=answer+RomanToInt(m);

                }
                if(ope == "-") {
                    answer=answer-RomanToInt(m);

                }
                if(ope == "*") {
                   answer=answer*RomanToInt(m);

                }
                if(ope == "/") {
                    answer=answer/RomanToInt(m);

                }
            }
            }
                cout<<intToRoman(answer)<<"\n";
                return 0;
        }
