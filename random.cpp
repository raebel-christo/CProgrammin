#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main() {

    string s = "HelLo RaeBEl ChrisTO";
    string converted = "";
    for(int i=0; i<s.size(); i++) {
        if(s[i]>0x40 && s[i]<0x5b)
            {converted += s[i]|0x20; continue;}
        else if(s[i] == 0x20);
            continue;
        converted+=s[i];
    }

    cout<<converted;
    return 0;
}