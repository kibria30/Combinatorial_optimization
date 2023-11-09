#include<iostream>
#include<vector>

using namespace std;

void LPS(vector<int> &lps, string pattern){
    int len = -1;              //for 0 base indexing
    int index = 1;
    lps[0] = 0;

    while(index < pattern.size()){
        if(pattern[index] == pattern[len+1]){
            len++;
            lps[index] = len;
            index++;
        }
        else{
            len = -1;        
            lps[index] = 0;
            index++;
        }
    }
}

int KMP(string str, string pattern){
    int count =0;
    int len_str = str.size();
    int len_pat = pattern.size();
    vector<int> lps(len_pat);

    LPS(lps, pattern);
    cout<<"LPS array (0 base indexing): "<<endl;
    for(auto i: pattern){
        cout<<i<< " "; 
    }
    cout<<endl;
    for(auto i:lps){
        cout<<i<<" ";
    }
    cout<<endl;
    int index = 0;
    int ptr = -1;
    cout<<"Comparisons: "<<endl;
    while(index < len_str){
        cout<<str[index]<<" - "<<pattern[ptr+ 1]<<endl;
        if(str[index] == pattern[ptr+1]){
            ptr++;
            index++;
            if(ptr == len_pat-1){
                count++;
                ptr = -1;
                cout<<"Successfully matched!!"<<endl;
                cout<<"after shifting "<<index - len_pat<<" char (0 base indexing)."<<endl;
            }
        }
        else{
            if(ptr == -1){
                ptr = 0;
            }
            else{
                ptr = lps[ptr];
            }
                
            if(ptr == 0 && pattern[ptr+1] != str[index]){
                index++;
                ptr = -1;
            }
        }
    }
    return count;
}

int main(){
    string str, pattern;
    freopen("string_input.txt", "r", stdin);
    cin>>str;
    cin>>pattern;

    cout<< pattern << " found " << KMP(str, pattern) << " times in " <<str<<endl;
}