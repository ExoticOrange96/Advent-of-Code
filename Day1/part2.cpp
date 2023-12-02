#include <bits/stdc++.h>
using namespace std;


unordered_map<string, string> numberMap = {
        {"one", "1"}, 
        {"two", "2"}, 
        {"three", "3"},
        {"four", "4"},
        {"five", "5"},
        {"six", "6"},
        {"seven", "7"},
        {"eight", "8"},
        {"nine", "9"},
        {"zero", "0"}, 
    };


int main()
{
    ifstream inp("input.txt");
    istream_iterator<string> inp_it(inp), inp_eof;
    
    vector<string> words(inp_it, inp_eof);
    int sum = 0;

    for(auto s : words){
        for (const auto& pair : numberMap) {
            

            int n = pair.first.size();
            char firstletter = pair.first[0];
            char lastletter = pair.first[n-1];
            string replacementString = firstletter + pair.second + lastletter;

            std::string::size_type pos = s.find(pair.first);
            while (pos != std::string::npos) {
                s.replace(pos, pair.first.length(), replacementString);
                pos = s.find(pair.first, pos + replacementString.size());
            }
        }

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
        cout << "finalNumber" << finalNumber << endl << endl;
        sum = sum + stoi(finalNumber); 
    }

    cout << sum;
    return 0;
}
