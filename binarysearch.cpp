//without using function
/*

#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int main(){
    int key;
    cout<<"Enter the key which we want to search: ";
    cin>>key;
    cin.ignore();
    cout<<"Enter the sorted elements with spaces: ";
    string strinput;

    getline(cin,strinput);
    istringstream ss(strinput);

    vector<int> vecinput;
    int num;
    while(ss>>num){
        vecinput.push_back(num);
    }

    int len = vecinput.size();
    
    int lb = 0;
    int ub = len-1;

    int flag = 0;
    while(lb<=ub){
        int mid = (lb+ub)/2;
        if(key==vecinput[mid]){
            cout<<"Find the key in "<<mid<<"position"<<endl;
            flag = 1;
            break;
        }
        else if(key<vecinput[mid]){
            ub=mid-1;
        }
        else{
             lb=mid+1;
        }
        
        
    }
    
    if(flag==0){
        cout<<"Key is not in the array";
    }

}

*/


//with using function

#include <iostream>
#include <sstream>
#include <vector>

using namespace std;


int binarysearch(const vector<int>& vec, int key){
    int lb = 0;
    int ub = vec.size()-1;
    while(lb<=ub){
        int mid = (lb+ub)/2;
        if(key==vec[mid]){
            return mid;
        }

        else if(key<vec[mid]){
            ub = mid - 1;
        }

        else{
            lb = mid + 1;
        }

    } 

    return -1;
}


int main(){
    int key;
    cout<<"Enter the key which we want to find: ";
    cin>>key;
    string strinput;
    
    cin.ignore();
    cout<<"Enter the sorted array with spaces: ";
    getline(cin,strinput);
    istringstream ss(strinput);

    vector<int> vecinput;
    int num;

    while(ss>>num){
        vecinput.push_back(num);
    }

    int result = binarysearch(vecinput,key);

    if(result==-1){
        cout<<"Key is not found";
    }
    else{
        cout<<"Key is found "<<result<<" ";
    }
}