#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'repeatedString' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts following parameters:
 *  1. STRING s
 *  2. LONG_INTEGER n
 */
long repeatedString(string s, long n) {
    // 변수 선언.
    int n_of_a_in_s = 0;
    long long int n_of_cycle = 0;
    int remain = 0;
    
    //for 문
    
    for (int i = 0; i < s.length() ; i++)
    {
        if (s[i] =='a'){
            n_of_a_in_s++;
        }    
    }
    //몇번 도는지 확인
    n_of_cycle = n / s.length();
    
    #나머지 더해주기
    for (int j = 0; j < n%s.length() ; j++)
    {
        if (s[j] =='a'){
            remain++;
        }    
    }
    
    //한 사이클에 갯수, 사이클수, 나머지
    return n_of_cycle *n_of_a_in_s + remain  ;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string n_temp;
    getline(cin, n_temp);

    long n = stol(ltrim(rtrim(n_temp)));

    long result = repeatedString(s, n);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
