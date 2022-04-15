#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int initialCalorie;
    int jumpCalorie;
    int coinCalorie;
    int m;
    int n;
    
    cin>>initialCalorie;
    cin>>jumpCalorie;
    cin>>coinCalorie;
    cin>>m>>n;
    
    vector<string>matrix;
    
    vector<int>coinCount(n);            // To Count total coins in a column
    vector<int>coinHeight(n);           // To Store the max height of coin in column
    vector<int>hurdleHole(n);           // To find where is the hole to move to next column
    
    string temp;
    for(int i=0;i<m;i++){
        cin>>temp;
        matrix.push_back(temp);
    }

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            
            if(matrix[i][j]=='C'){
                
                if(coinCount[j]==0){
                    coinHeight[j]=m-i-1;
                }
                coinCount[j]++;
            }
            
            if(matrix[i][j]=='0'){
                hurdleHole[j]=m-i-1;
            }
        }
    }
    
    int lastRow=0;
    bool output=false;
    
    for(int i=0;i<n;i++){
        
        if(coinCount[i]==0)                             // if there are no coins
        {
            if(hurdleHole[i]==0){                       // and no hurdles move to next column
                
                if(initialCalorie==0){
                    output=true;
                    cout<<lastRow;
                    break;
                }
                
                initialCalorie--;
                lastRow=i;
            }
            else                                        // if there are hurdles
            {
                int totalJumpCalorie=hurdleHole[i]*jumpCalorie;
                if(totalJumpCalorie>initialCalorie){
                    output=true;
                    cout<<lastRow;
                    break;
                }
                lastRow=i;
                initialCalorie=initialCalorie-totalJumpCalorie;
            }
            
        }
        else                                            // If there are coins
        {
            int totalJumpCalorie=coinHeight[i]*jumpCalorie;
            
            if(totalJumpCalorie>initialCalorie){
                output=true;
                cout<<lastRow;
                break;
            }
            
            int totalCoinCalorie=coinCount[i]*coinCalorie;
            initialCalorie=initialCalorie-(totalJumpCalorie)+(totalCoinCalorie);
            lastRow=i;
        }
        
    }
    
    if(!output)
    cout<<initialCalorie;
    
}
