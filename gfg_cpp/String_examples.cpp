/*
        String are classified into 2 ways :=
            >> C - style strings 
            >> C++ strings - work as class..

        C - style strings :-        // C - Programming..
            int main(){
                char str[] = "gfg";     // stop at '\0'
                cout << str;

                cout << sizeof(str);    //  return '4' because it count 'g, f, g, \0' {total - 4};

                char str1[] = {'g', 'f', 'g', '\0'} ;
                cout << str1;
                
                return 0;
            }

            Functions :=
            >> strlen(str1);
            >> strcmp(str1, str2);
            >> strcpy(str1, str2);

            int main(){
                char str[] = "gfg";
                cout << strlen(str);    // return '3' is length of str..
            
            //  https://www.geeksforgeeks.org/tag/lexicographic-ordering/
            //  https://www.geeksforgeeks.org/lexicographical_compare-in-cpp/
    
                char str[] = "abc";      // try for "bcd", "gfg";   {Here it performs Lexisographical}
                char str1[] = "bcd";

                int res = strcmp(str, str1);
                if (res > 0){
                    cout << "str is greater..";
                }
                else if (res == 0){
                    cout << "str is equal to str1..";
                }
                else{
                    cout << "str is lesser..";
                }
            

                char str[5] = "";

                // str = "gfg";     // error: storage size of 'str' isn't known char str[];
                strcpy(str, "gfg");
                cout << str; 

                return 0;
            }

        C++ String :=
        >> Richer Library 
        >> Support Operators like +, -, <, >, ==, !=, <=, >= are possible..
        >> can assign a string later
        >> Do not have to worry about size
        >> can be converted to c-style if needed..  {using  c_str}
        
        int main(){
            string str;             // str is an object for class string..
            str = "geeksforgeeks";
            cout << str.length() << endl;   // gets length of str..

            str = str + "xyz";          // concate two strings..
            cout << str << endl;        

            cout << str.substr(1, 3) << endl;   //  substr(start_index, length);

            cout << str.find("eek") << endl;    // if it is present return first occurance in str.. 
                                            //  or else return string::npos;

            string str[] = "abc";      // try for "bcd", "gfg";   {Here it performs Lexisographical}
            string str1[] = "bcd";

            if (str > str1){
                cout << "str is greater..";
            }
            else if (str == str1){
                cout << "str is equal to str1..";
            }
            else{
                cout << "str is lesser..";
            }

        
            string str;
            // cin >> str;  // it does not take for continous stream of string as input..

            getline(cin, str);      // it take stream of strings..

            cout << str << endl;    

            return 0;
        }

*/ 

#include<bits/stdc++.h>
#include<string>
using namespace std;

int32_t main(){ 
    //  Iterating through a string
    string str = "geeksforgeeks";

    for (int i=0; i<str.length(); i++){
        cout << str[i] << " ";
    }cout << endl;

    for (char z: str){
        cout << z << " " ;
    }

    return 0;
}