#include<bits/stdc++.h>
using namespace std;

int getDecimal(string binary) {
    long int result = 0;
    for (int i = 0; i < binary.size(); i++) {
        if (binary[i] == '1') {
            result += 1 << (binary.size() - 1 - i);
        }
    }
    return result;
}

int divide(long int a,long int b){
    return a%b;
}

string binString(long int num)
{

    string str;
      while(num){

      if(num & 1)
        str+='1';
      else
        str+='0';
      num>>=1;
    }

      return str;
}

string concatenate(string a,string b){
    string ans;
    ans = a + b;
    return ans;
}

int main(){
    string s;
    cout<<"Enter 8 bit data : ";
    cin>>s;
    string strDividend = concatenate(s,"0000000000000000");
    //string strDividend = s;
    long int dividend = getDecimal(strDividend);
    long int divisor = getDecimal("10001000000100001");
    string remainder = binString(divide(dividend,divisor));
    string checkSum = concatenate(s,remainder);
    cout<<"Check sum is : "<<checkSum<<"\n\n";

    string checkRemainder = binString(divide(getDecimal(checkSum),divisor));
    cout<<"\n"<<checkRemainder<<"\n";
    if(checkRemainder == ""){
        cout<<"Flawless transmission ";
    }
    else{
        cout<<"Wrong data Transmitted!";
    }
    return 0;
}
