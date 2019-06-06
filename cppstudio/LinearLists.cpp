//
//  LinearLists.cpp
//  cppstudio
//
//  Created by Иван Милаев on 06/06/2019.
//  Copyright © 2019 IvanMilaev. All rights reserved.
//

#include "LinearLists.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>


using namespace std;

struct Data
{
    string a;
};

struct List
{
    Data d;
    List *next;
};

List * find(List *u, string item);


void insert(List **u, string item)
{
    string copy(item);
    reverse(copy.begin(), copy.end());
    if (find(*u, copy) || find(*u, item)){
        return;
    }
    Data* tmp = new Data;
    tmp->a = item;
    Data x = *tmp;
    
    
    List *p = new List;
    p->d.a = x.a;
    
    if(*u == 0)
    {
        p->next = 0;
        *u = p;
        return;
    }
    
    List *t = *u;
    if(t->d.a >= p->d.a)
        
    {
        p->next = t;
        *u = p;
        return;
    }
    
    List *t1 = t->next;
    while(t1)
    {
        if(t->d.a < p->d.a && p->d.a <= t1->d.a)
        {
            t->next = p;
            p->next = t1;
            return;
        }
        t = t1;
        t1 = t1->next;
    }
    
    t->next = p;
    p->next = 0;
}

void print(List *u)
{
    List *p = u;
    cout << "List:" << endl;
    while(p)
    {
        cout << p->d.a << endl;
        p = p->next;
    }
}


List *find(List *u, string item) {
    Data* tmp = new Data;
    tmp->a = item;
    Data x = *tmp;
    
    List *p = u;
    while(p)
    {
        if(p->d.a == x.a)
            return p;
        p = p->next;
    }
    return 0;
}



void read_console(List** u)
{
    string line="", word="";
    getline(cin, line, '.');
    
    for (int i = 0; i < line.length(); ++i)
    {
        if (isalpha(line[i]))
        {
            word += line[i];
        }
        else
        {
            insert(u, word);
            
            word = "";
        }
    }
    
};

void read_file(List** u) {
    ifstream fin("../input.txt");
    string line="", word="";
    getline(fin, line, '.');
    
    for (int i = 0; i < line.length(); ++i)
    {
        if (isalpha(line[i]))
        {
            word += line[i];
        }
        else
        {
            insert(u, word);
            
            word = "";
        }
    }
    
    fin.close();
}




int main(){
    List *u = NULL;
    
    read_console(&u);
    
    print(u);
}
