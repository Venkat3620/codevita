#include <iostream>
#include <string>

using namespace std;

int main()
{
    string inp;
    getline(cin,inp);
    int arr[100][100]={0};
    int len=inp.length();
    //cout<<"Len:"<<len<<endl;
    int taskid, tasklist;
    int tnum=0;
    int j=0;
    int flag=0;
    //cout<<"inp: "<<inp<<endl;
    for (int i=0;i<len&&flag==0;)
    {
        //cout<<"Outer For i:"<<i<<endl;
        if(isdigit(inp[i])&&flag==0)
        {
            //cout<<"ifDigit inp[i]:"<<inp[i]<<endl;
            taskid=inp[i];
            arr[taskid][0]=0;
            i=i+3;
            
            if(inp[i]=='}')
            {
                //cout<<"inp[i] is }"<<endl;
                i=i+3;
                //cout<<"Skipping to next index i:"<<i<<" inp[i]:"<<inp[i]<<endl;
            }
            else
            {
                //cout<<"inp[i] is not }"<<endl;
                while(inp[i]!='}' && flag==0)
                {
                    //cout<<"while i:"<<i<<" j:"<<j<<endl;
                    if(inp[i]>taskid)
                    {
                        //cout<<"greater flag trigger"<<endl;
                        flag=5;
                    }
                    else if(inp[i]=='}'||inp[i]==',')
                    {
                        i++;
                    }
                    else if(len>i)
                    {
                        //cout<<"assigning to arr"<<endl;
                        j++; 
                        arr[taskid][j]=inp[i];
                        i=i+1;
                    }
                }
                i++;
                
            }
        }
    }
    
    if(flag==5)
    {
        cout<<"error";
    }
    else
    {
        cout<<j;
    }
    return 0;
}
