#include <iostream>
#include <string>

using namespace std;

int main()
{
    string final="";
    int n;
    cin>>n;
    
    string start="a";
    string a="ab";
    string b="cd";
    string c="cd";
    string d="ab";
    
    int count=1;
    int temp=0;
    int flag=0;
    int masterlen=1;
    int slen=start.length();
    string out;
    while(flag==0)
    {
        //cout<<endl<<endl<<"Count:"<<count+1<<" SLen:"<<slen<<" MasterLen:"<<masterlen<<endl;
        for (int i=0;i<slen&&flag==0;i++)
        {
            //cout<<"For Loop i:"<<i<<endl;
            //cout<<"Start:"<<start<<endl;
            //flag=1;
            
            if(start[i]=='a')
            {
                //cout<<"Trigger:a"<<endl;
                final=final+a;
            }
            if(start[i]=='b')
            {
                //cout<<"Trigger:b"<<endl;
                final=final+b;
            }
            if(start[i]=='c')
            {
                //cout<<"Trigger:c"<<endl;
                final=final+c;
            }
            if(start[i]=='d')
            {
                //cout<<"Trigger:d"<<endl;
                final=final+d;
            }
            //cout<<"Final[i]:"<<final<<endl;
        }
        slen=final.length();
        start=final;
        final="";
        
        masterlen=masterlen+slen;
        if(masterlen>=n)
        {
            //cout<<"Flag Trigger masterlen:"<<masterlen<< " Slen:"<<slen<<" Start:"<<start<< endl; 
            flag++;
            int templen=(masterlen-slen);
            int templen1=n-templen;
            //cout<<"templen:"<<templen<< " templen1:"<<templen1<<endl;
            out=start[templen1-1];
        }
        count++;
        
    }
    cout<<out<<endl;
    return 0;
}
