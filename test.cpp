//
// Created by tameer on 9/3/19.
//

#include "test.h"
#include "String.h"
void Test ::String_test() {
        String s;
        cout  << s<< endl;
        String s1("tameer");
        String s2("ghanim");
        if(s1>s2)
            cout<<s1<<" is greater than :"<<s2<<endl;
        else{
            if(s1<s2)
                cout<<s1<<" is smaller than: "<<s2<<endl;
            else
                if(s1 == s2)
                    cout<<s1<<" is equal to : "<<s2<<endl;
        }
        cout<<"concatenation of "<<s1 <<" and "<<s2<<":"<<endl;
        s1+=s2;

        String s4(s1);
        cout<<s1<<endl;
        cout<<"length of :"<<s1<<",is:"<<s1.length()<<endl;
        cout<<"substring from index: 2 to index: 6 in :"<<s1<<" ,is:"<<endl;
        s1=s1.substring(2,8);

        cout<<s1<<endl;
}