//  Copyright © 2017 Dougy Ouyang. All rights reserved.

#include <iostream>
#include <string>
#include <stdio.h>
#include <ctype.h>
#include <algorithm>

using namespace std;
string adj[35][105], mc[105][35];
int counter[35], cal[35];
int ct[35];

int main()
{
    int n, k, adjc;
    int mcpo[105];
    int i, j, l;
    for(i=0;i<35;i++){
        cal[i]=1;
    }
    
    cin >> n >> k;
    string line;
    getline(cin, line);
    for(i=0;i<n;i++){
        string s, adjective;
        int size;
        adjc=0;
        getline(cin, s);
        size=s.length();
        for(j=19;j<size-4;j++){
            if(s[j]==' '){
                mc[i][adjc]=adjective;
                bool used=false;
                for(l=0;l<counter[adjc];l++)
                    if(adj[adjc][l]==adjective)
                        used=true;
                if(!used)
                    adj[adjc][counter[adjc]++]=adjective;
                adjective="", adjc++;
            }
            adjective+=s[j];
        }
    }
    for(i=0;i<adjc;i++){
        sort(adj[i], adj[i]+counter[i]);
    }
    for(i=adjc-2;i>=0;i--)
        cal[i]=cal[i+1]*counter[i+1];
    
    //find position of missing cows
    for(i=0;i<n;i++){
        int sum=0;
        for(j=0;j<adjc;j++){
            for(l=0;l<counter[j];l++){
                if(mc[i][j]==adj[j][l]){
                    sum+=cal[j]*l;
                    break;
                }
            }
        }
        mcpo[i]=sum;
    }
    //find position k
    k--;
    for(i=0;i<n;i++){
        if(mcpo[i]<=k)
            mcpo[i]=2000000000, k++;
    }
    
    //cout kth position
    i=0;
    while(k)
        ct[i]=k%counter[adjc-i-1], k/=counter[adjc-i-1], i++;
    for(j=0;j<adjc;j++){
        cout << adj[j][ct[adjc-j-1]];
    }
    cout << endl;
    
    return 0;
}
