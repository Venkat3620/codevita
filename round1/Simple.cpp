#include <iostream>

using namespace std;

int main()
{
    string row1,row2,row3;
    cin>>row1>>row2>>row3;
    
    char arow1[3],arow2[3],arow3[3];
    
    for(int i=0;i<3;i++)
    {
        arow1[i]=row1[i];
        arow2[i]=row2[i];
        arow3[i]=row3[i];
    }
    char check=arow1[0];
    
    int flag=0;
    
    for(int i=0;i<3;i++)
    {
        for (int j=0;j<3;j++)
        {
            if(i==0&&j==0)
            {
                check=arow1[j];
                if (arow1[j+1]==check && arow1[j+2]==check)
                {
                    flag++;
                }
                if (arow2[j]==check && arow3[j]==check)
                {
                    flag++;
                }
                if (arow2[j+1]==check && arow3[j+2]==check)
                {
                    flag++;
                }
            }
            else if(i==0&&j==1)
            {
                check=arow1[j];
                if (arow2[j]==check && arow3[j]==check)
                {
                    flag++;
                }
            }
            else if(i==0&&j==2)
            {
                check=arow1[j];
                if (arow2[j]==check && arow3[j]==check)
                {
                    flag++;
                }
                if (arow2[j-1]==check && arow3[j-2]==check)
                {
                    flag++;
                }
            }
            else if(i==1&&j==0)
            {
                check=arow2[j];
                if (arow2[j+1]==check && arow2[j+2]==check)
                {
                    flag++;
                }
            }
            else if(i==2&&j==0)
            {
                check=arow3[j];
                if (arow3[j+1]==check && arow3[j+2]==check)
                {
                    flag++;
                }
            } 
        }
    }
    //cout<<"Flag: "<<flag<<endl;
    if(flag==1)
    {
        cout<<"YES";
    }
    else
    {
        cout<<"NO";
    }

    return 0;
}