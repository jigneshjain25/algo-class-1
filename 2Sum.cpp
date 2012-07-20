#include<iostream>
#include<vector>
#include<map>
#include<string.h>
#include<queue>
#include<fstream>
#define rep(i,a,b) for(i=a;i<b;i++)
#define REP(i,a,b) for(int i=a;i<b;i++)
#define pb push_back
using namespace std;

int main()
{
    ifstream fin("HashInt.txt");
    int temp;
    map<int,int> phone;
    map<int,int>::iterator it;
    while(1)
    {
            fin>>temp;
            if(fin.eof())break;
            phone[temp]=1;
    }
    int count=0;
    for(int m=2500;m<=4000;m++)
    {
        int c=0;
        for(it=phone.begin();it!=phone.end();it++)
        {
            if((*it).second==1)
            {
                if(((*it).first<m) && ((m-(*it).first)!=(*it).first))
                    {
                        if(phone[m-(*it).first]==1)
                        {
                            c=1;
                            break;
                        }
                    }
            }
        }
        if(c==1)count++;
    }
    cout<<count;
}
