#include <iostream>
#include <vector>
using namespace std;

void setting(int open,int closed,vector<string> &ans,string &get){

    // base case 
    if(open==0 && closed==0){
        ans.push_back(get);
        return;
    }

    // ak case solve
    // include open 

    if(open>0){
        get.push_back('(');
        setting(open-1,closed,ans,get);
        get.pop_back();
    }

    // include closed 

    if(closed>open){
        get.push_back(')');
        setting(open,closed-1,ans,get);
        get.pop_back();
    }

}


int main(){
    cout<<"enter the number of pairs is there in the problem set --> "<<endl;
    // cout<<endl;
    int n;
    cin>>n;
    int open=n;
    int closed=n;
    vector<string>ans;
    string get="";
    setting(open,closed,ans,get);

    for(auto i: ans){
        cout<<i<<" ";
    }
}