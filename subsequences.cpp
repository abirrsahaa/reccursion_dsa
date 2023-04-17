#include <iostream>
#include <vector>
using namespace std;
void find_subsequences(string input,int n,int index,string &output,vector<string>&store){
    // base case
    if(index>=n){
        store.push_back(output);
        return;
    }

    // to find subsequences i will apply inclusion and exclusion principle
    // mein ak case solve karungs baki ka reccurusion sambhal lega!

    // include 
    output.push_back(input[index]);
    // reccursive call koira ditasos next index r liga
    find_subsequences(input,n,index+1,output,store);
    // backtracking lagbo
    output.pop_back();

    // exclude 
    // kisu lagdo na just agiye dao 
    find_subsequences(input,n,index+1,output,store);


}
int main(){

    string input="abir";
    string output="";

    vector<string>store;
    int n=input.size();
    int index=0;

    find_subsequences(input,n,index,output,store);

    cout<<"printing the subsequences  -->  "<<endl;

    for(int i=0;i<store.size();i++){
        cout<<store[i]<<" ";
    }

}