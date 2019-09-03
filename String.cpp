//
// Created by tameer on 9/3/19.
//

#include "String.h"
#include<cstring>
#include <stdlib.h>

String::String(){
    //cout<<"cont for empty cont"<<endl;
    m_buffer = new char[1];
    m_buffer[0] ='\0';
    m_size = 0;
}

String::String(const char *str){
    //cout<<"cont for char*:"<<endl;
    int length = lenOfChar(str);
    m_buffer = new char[length+1];
    m_size = length;
    m_buffer=strcpy(m_buffer,str);

}

int String :: lenOfChar(const char *str){
    const char *temp = str;
    int count = 0;
    while(*temp++) {
        count++;
    }
    return count;
}

String::String(const String & str){
    //cout<<"copy cont"<<endl;
    m_buffer = new char[str.m_size+1];
    m_size = str.m_size;
    strcpy(m_buffer,str.m_buffer);
}

String ::~String(){
   // cout<<"destructor"<<endl;
    delete[] m_buffer ;
}

int String :: length() const{
    return m_size;
}

void String :: operator=(const String &str){
    delete[] m_buffer;
    m_buffer = new char[str.m_size+1];
    strcpy(m_buffer,str.m_buffer);
    m_size = str.m_size;
}
bool String ::operator==(const String &str) {
    if(m_size != str.m_size)
        return false;
    return !strcmp(m_buffer,str.m_buffer);
}
bool String::operator<=(const String &str) {
    int cmp = strcmp(m_buffer,str.m_buffer);
    if(cmp>0)
        return false;
    return true;
}

bool String::operator>=(const String &str) {
    int cmp = strcmp(m_buffer,str.m_buffer);
    if(cmp<0)
        return false;
    return true;
}

bool String :: operator<(const String &str){
    int cmp = strcmp(m_buffer,str.m_buffer);
    if(cmp>=0)
        return false;
    return true;
}
bool String :: operator>(const String &str){
    int cmp = strcmp(m_buffer,str.m_buffer);
    if(cmp<=0)
        return false;
    return true;
}

void String:: operator+=(const String &str){
    char *temp =(char*) realloc(m_buffer,str.m_size);
    if(temp)
        m_buffer = temp;
    strcat(m_buffer,str.m_buffer);
    m_size+=str.m_size;


}
ostream& operator<<(ostream &os, const String &str){
    for(int i = 0; i < str.m_size; i++)
    {
        os << str.m_buffer[i];
    }
    return os;

}
char& String :: operator[] (unsigned int index){
    return m_buffer[index];
}
void String:: operator+(const String &str){
    char *temp =(char*) realloc(m_buffer,m_size+str.m_size+1);
    if(temp)
        m_buffer = temp;
    strcat(m_buffer,str.m_buffer);
    m_size+=str.m_size;


}
String String:: substring(int start,int end){
    if(start<0 || end >= this->m_size) {
        cout << "BAD_INDEX";
        return NULL;
    }

    int len = end-start+1;
    char *new_buffer = new char[len];
    int i=0;
    while(i < len-1){
        new_buffer[i]=this->m_buffer[i+start];
        i++;
    }
    String substr(new_buffer);
    return substr;

}