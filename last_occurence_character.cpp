// #include <iostream>
// #include <vector>
// using namespace std;
// int index(vector<char>arr,int n,int i,char c,int ans){
//     // base case
//     if(i>=n){
//         return ans;
//     }

//     // ak case solve karde te hai baki ka toh recursion sambhal lega 
//     if(arr[i]==c){
//         ans=i;
//     }

//     // bss fir agle index ke liye index call karde te hai

//     return index(arr,n,i+1,c,ans);
// }
// int main(){

//     vector<char>arr{'a','d','c','d','e'};
//     int n=arr.size();
//     char c='d';
//     int ans=-1;
//     int i=0;

//     int final_ans=index(arr,n,i,c,ans);

//     if(final_ans==-1){
//         cout<<"the character doesnt even exist"<<endl;
//     }
//     else{
//         cout<<"the last occurence of the character is at the index  -->"<<final_ans<<endl;
//     }


// }

// reverse a string re 

// #include <iostream>
// #include <string>
// using namespace std;
// void reverse(string arr,string& ans,int end ){
//     // base case 
//     if(end<0){
//         return;
//     }

//     // ak case solve kar dete hai baki ka reccursion sambhal lega !

//     ans.push_back(arr[end]);

//     // chalo reccursion ko call kar dete hai!
//     reverse(arr,ans,end-1);
// }
// int main(){
//     string arr="shakanaka";
//     string ans="";
//     int end=arr.size()-1;

//     reverse(arr,ans,end);

//     cout<<"the reversed string is ---> "<<ans<<endl;

// }


// but to do this in the exact same string 
// #include <iostream>
// using namespace std;
// void reverse(string& arr,int start,int end){
//     // base case declare kar de te hai taki computer ko pata chal jai ke kab rukna hai 
//     if(start>=end){
//         return;
//     }
//     // ak case mein sambhal leta hu baki reccursion mereko dekhke sikh jayega!
//     swap(arr[start],arr[end]);

//     // chalo abb recursion chacha ko call kar lete hai
//     reverse(arr,start+1,end-1);
// }
// int main(){
//     string arr="45oon";
//     int start=0;
//     int end=arr.size()-1;

//     reverse(arr,start,end);

//     cout<<"the reversed string is --> "<<arr<<endl;
//     // char ans=arr[0];
//     // int fa=ans;
//     // cout<<fa<<endl;
//     // cout<<int('1')<<endl;
//     // cout<<int('4')<<endl;
//     // cout<<int("4")<<endl;
//     // int sub=fa-'1';

//     cout<<sub<<" "<<endl;

// }

#include <iostream>
using namespace std;
bool check(string&arr,int start,int end){
    // base case 
    if(arr[start]!=arr[end]){
        return false;
    }
    if(start>=end){
        return true;
    }

    // recursion call koira dei
    check(arr,start+1,end-1);
}
int main(){

    string arr="abir";
    int start=0;
    int end=arr.size()-1;

    if(check(arr,start,end))cout<<"true";
    else cout<<"false";
    return 0;

}