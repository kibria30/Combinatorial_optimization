#include<iostream>

using namespace std;

int matcher(string str, string pattern){
    int count =0, ptr; 
    for(int i=0; i<=str.size()-pattern.size(); i++){
        ptr = i;
        //cout<<ptr<<endl;
        bool flag = true;
        for(int j=0; j<pattern.size(); j++){
            if(str[ptr] == pattern[j]){
                ptr++;
            } 
            else {
                flag = false;
                break;
            }
        }
        if(flag){
            cout<< pattern << " is found on position(0 base indexing/ shifting): " << i  <<endl;
            count++;
            i = ptr-1;
        }
    }
    return count;
}

int main(){
    string str, pattern;

    freopen("string_input.txt", "r", stdin);

    cout<<"Enter string: ";
    cin>>str;
    cout<<"Enter pattern: ";
    cin>>pattern;
    
    cout<<endl;
    cout<< pattern <<" is found "<< matcher(str, pattern)<< " times in "<< str ;

}