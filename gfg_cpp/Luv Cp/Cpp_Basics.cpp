
/*
        Double 
        Float
        Long Long int
        Long int
        int
        Character           --> Has higher Precedence..
    
        Precedence Table :-

    Ref :-  https://en.cppreference.com/w/c/language/operator_precedence

    The following table lists the precedence and associativity of C operators. Operators are listed top to bottom, in descending precedence.

Precedence	Operator	    Description	Associativity
    1   	++ --	    Suffix/postfix increment and decrement	Left-to-right
            ()      	Function call
            []	        Array subscripting
            .	        Structure and union member access
            ->	        Structure and union member access through pointer
        (type){list}	Compound literal(C99)
    2     ++ --	        Prefix increment and decrement[note 1]	Right-to-left
            + -	        Unary plus and minus
            ! ~	        Logical NOT and bitwise NOT (type)Cast
            *       	Indirection (dereference)
            &	        Address-of 
            sizeof	    Size-of[note 2]
         _Alignof	    Alignment requirement(C11)
    3      	* / %	    Multiplication, division, and remainder	Left-to-right
    4	    + -	        Addition and subtraction
    5   	<< >>	    Bitwise left shift and right shift
    6	    < <=    	For relational operators < and ≤ respectively
            > >=	    For relational operators > and ≥ respectively
    7	    == !=	    For relational = and ≠ respectively
    8	    &	        Bitwise AND
    9	    ^	        Bitwise XOR (exclusive or)
    10	    |	        Bitwise OR (inclusive or)
    11	    &&	        Logical AND
    12	    ||	        Logical OR
    13	    ?:	        Ternary conditional[note 3]	Right-to-left
    14      =	        Simple assignment
            += -=	    Assignment by sum and difference
            *= /= %=	Assignment by product, quotient, and remainder
            <<= >>=	    Assignment by bitwise left shift and right shift
            &= ^= |=	Assignment by bitwise AND, XOR, and OR
    15  	    ,	    Comma	Left-to-right
*/ 

#include<bits/stdc++.h>
using namespace std;

int32_t main()
{   
    double x = 3/2;         //  Here it does first calculation and then store..
    cout << x << "\n";

    double x2 = 3/2.0;
    cout << x2 << "\n";     //  It depends on the precedence..

    cout << 'c' + 1 << "\n";    //  ASCII key value of 'c' is 99 then it has high precedence than integer..

/* Data types :-   int, char, long int, long long int, float, double

        -10^9 < int < 10^9
        -10^12 < long int < 10^12
        -10^18 < long long int < 10^18

*/
    int a = 100000;
    int b = 100000;     //  Or declare as long int 
    long long int c = a * b;
    long long int c2 = a * 1LL * b;
    cout << c << " " << c2 << endl;

    int mx = INT_MAX;
    cout << mx+1 << endl;       
                            //      -INT_MIN < INT < INT_MAX
                            //          |_____+1_______|            Overflow..


    double a2 = 1e5;
    double b2 = 1e5;        //  e is a scientific way to write 10 to power something ____
    double x3 = a2 * b2;
    cout << fixed << setprecision(0) << x3 << endl; 
                    //  'fixed' is a keyword, used to remove 'e' format 
                    //      and 'setprecision(_val)' we remove the decimal value 
            //  Why doesn't use the double in case of long long int because, It doesn't return prefect value.

    x3 = 1e24;
    cout << x3 << endl;     // In case of 'DOUBLE and FLOAT' is not a exact value..

    return 0;
}
