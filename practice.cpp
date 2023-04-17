

// // merge sort

// // what is merge sort ..like what and how it is being implemented ....

// // -------- first we find the middle part of the array and what we do is we again do the same thing for its right and left part  -----

// // now when we reach the state where i cannot even break further ..and we have got a single cell now we will merge the two last cells by sorting

// //

// #include <iostream>
// using namespace std;

// // merge function to merge the array

// void merge (int arr[],int start,int end ){
//     // first finding the part
//     int mid =start+(end-start)/2;

//     // now getting the length of each part so that i can make up an array and let the copy of it do the trick

//     int len1=mid-start+1;
//     int len2=end-start;

//     // making up the arrt

//     int* left=new int [len1];
//     int* right=new int[len2];

//     //
// }

// int main(){

// }

// subset sum

// first try to print subset

// #include <iostream>
// #include <vector>
// using namespace std ;

// void subsequences(int arr[],int n,vector<vector<int>>&ans,int index,vector<int>&output){
//     // base case
//     if(index>=n){
//         ans.push_back(output);
//         return;
//     }

//     // ak case solve kar de baki ka reccursion sambhal lega
//     // idhar subset ke liye toh include exclude khel sakta hu mai

//     // include
//     output.push_back(arr[index]);
//     subsequences(arr,n,ans,index+1,output);
//     // backtracking
//     output.pop_back();

//     // exclude
//     subsequences(arr,n,ans,index+1,output);
// }
// int main(){
//     int arr[]={5,2,1};
//     int n=3;
//     vector<vector<int>>ans;
//     vector<int>output;
//     subsequences(arr,n,ans,0,output);

//     cout<<"printing the subsets "<<endl;

//     for(int i=ans.size()-1;i>=0;i--){
//         // cout<<"[";
//         int sum=0;
//         for(int j=0;j<ans[i].size();j++){

//             // cout<<ans[i][j]<<",";
//             sum=sum+ans[i][j];

//         }
//         if(i==0){
//             cout<<sum;
//         }
//         else{
//             cout<<sum<<", ";
//         }
//         // cout<<"] ,";
//     }
// }