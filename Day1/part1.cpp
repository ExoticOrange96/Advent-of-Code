#include <bits/stdc++.h>
using namespace std;

int main()
{
    ifstream inp("input.txt");
    istream_iterator<string> inp_it(inp), inp_eof;
    
    vector<string> words(inp_it, inp_eof);
    int sum = 0;

    for (auto s : words)
    {
        int i = 0;
        int n = s.size();
        int j = n;
        string firstDigit = "";
        string lastDigit = "";
        for(i=0; i<n; i++){
            if(isdigit(s[i])){
                firstDigit = s[i];
                break;
            }
        }
        for(j=n-1; j>=0; j--){
            if(isdigit(s[j])){
                lastDigit = s[j];
                break;
            }
        }
        string finalNumber = firstDigit + lastDigit;
        sum = sum + stoi(finalNumber); 
    }

    cout << sum;
    return 0;
}
