#include <iostream>

using namespace std;

string dayofweek(int d, int m, int y)
{
    static int t[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };
    y -= m < 3;
    int temp = ( y + y / 4 - y / 100 + y / 400 + t[m - 1] + d) % 7;
    string day;
    if (temp==0)
    {
        day="Sun";
    }
    else if (temp==1)
    {
        day="Mon";
    }
    else if (temp==2)
    {
        day="Tue";
    }
    else if (temp==3)
    {
        day="Wed";
    }
    else if (temp==4)
    {
        day="Thu";
    }
    else if (temp==5)
    {
        day="Fri";
    }
    else if (temp==6)
    {
        day="Sat";
    }
    return day;
}

int isPrime(int n)
{
    if (n <= 1)
    {
        return 0; 
    }
        
    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
        {
            return 0;
        }
    }
    return 1;
}

int giveMaxD(int m, int y)
{
    if(m==1||m==3||m==5||m==7||m==8||m==10||m==12)
    {
        return 31;
    }
    else if(m==4||m==6||m==9||m==11)
    {
        return 30;
    }
    else if (m==2)
    {
        if(y%400==0)
        {
            return 29;
        }
        else if (y%100==0)
        {
            return 28;
        }
        else if (y%4==0)
        {
            return 29;
        }
        else
        {
            return 28;
        }
    }
    return 0;
}

int main ()
{
    int date;
    string dow;
    int n;
    cin >> date >> dow >> n;
    //cout <<"N:"<< n<<endl;
    int d,m,y;
    y=date/10000;
    m=(date/100)-(y*100);
    d=date%100;
    int od=d;
    int om=m;
    int oy=y;
    int maxd=01;
    int tday=0; //temp for n
    int flag=0;
    int f1,f2; //f1 for month and f2 for n
    string checkd;
    //cout<<"Year:"<<y<<" Month:"<<m<<" Date:"<<d<<endl;
    checkd=dayofweek(d,m,y);
    if(checkd==dow)
    {
        maxd=giveMaxD(m,y);
        for(int i=0;i<7;i++)
        {
           d++; 
           if(d==maxd)
           {
                d=1;
                m++;
                if(m>12)
                {
                    m=1;
                    y++;
                }
           }
        }
        f1=isPrime(m);
        if(f1==0)
        {
            flag++;
        }
    }
    while(flag==0)
    {
        
        maxd=giveMaxD(m,y);

        //cout<<endl<<"NewData Year:"<<y<<" Month:"<<m<<" Date:"<<d<<endl;
        //cout << "Maxd:"<<maxd<<" Tday:"<<tday<<endl;
        
        f1=isPrime(m); //Month Check
        f2=isPrime(tday); //n Check
        
        checkd=dayofweek(d,m,y);
        
        if(f1==1 && f2==1 && checkd==dow)
        {
            //cout<<"INSIDE FLAG TRIGGERED @ d: "<<d<<" m: "<<m<<" tday: "<<tday<<endl;
            flag++;
        }
        else
        {
            d++;
            tday++;
        }
        
        maxd=giveMaxD(m,y);
        if(d==maxd)
        {
            maxd=giveMaxD(m,y);
            //cout<<endl<<"NewData Year:"<<y<<" Month:"<<m<<" Date:"<<d<<endl;
            //cout << "Maxd:"<<maxd<<" Tday:"<<tday<<endl;
            
            f1=isPrime(m); //Month Check
            f2=isPrime(tday); //n Check
            checkd=dayofweek(d,m,y);
            
            if(f1==1 && f2==1 && checkd==dow)
            {
                //cout<<"INSIDE FLAG TRIGGERED @ d: "<<d<<" m: "<<m<<" tday: "<<tday<<endl;
                flag++;
            }
            else
            {
                tday++;
            }
            //cout<<endl<<"PreData Year:"<<y<<" Month:"<<m<<" Date:"<<d<<endl;
            d=1;
            m++;
            if(m>12)
            {
                m=1;
                y++;
            }
            //cout<<"PostData Year:"<<y<<" Month:"<<m<<" Date:"<<d<<endl;
            //cout<<"Month change triggered"<<endl<<endl;
        }
        
        //cout<<"NewData Year:"<<y<<" Month:"<<m<<" Date:"<<d<<endl;
    }
    //cout<<"Flag:"<<flag<<" Tday: "<<tday<<" N: "<<n<<" D: "<< d<<"M: "<<m<<"Y: "<<y<<endl;
    if(flag!=0 && tday==0)
    {
        cout<<"No "<<tday<<endl;
    }
    else if(flag!=0 && tday<=n)
    {
        cout<<"Yes "<<tday<<endl;
    }
    else if (flag!=0 && tday>n)
    {
        cout<<"No "<<tday<<endl;
    }
    string Temp_day = dayofweek(25, 3, 2022);
    return 0;
}
