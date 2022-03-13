/*
        Infix to Prefix :-

    Infix to Prefix (Simple Solution) :-
        This about simple method for Infix to Prefix Conversion.
    ** Converting given a string {Infix} to Prefix.. It contains alphabets and Operators and Brackets..
    
        Operator :-                 Associativity :-                ^
            ^                         Right to Left                 |
            *, /                      Left to Right                 |   {Precedence..}
            +, -                      Left to Right                 |   
            (, )                      Left to Right                 |

        ** If Operator has same Precedence then it follows same Associativity..
        ** If Operator are Different then it follows based on Precedence to evaluation first..

    Infix  :-    X + Y * Z
    prefix :-    + X * Y Z

    Infix  :-    (X + Y) * Z
    prefix :-    * + X Y Z

    Infix  :-    X ^ Y ^ Z
    prefix :-    ^ X ^ Y Z

    Infix  :-    (X + Y) * (Z + W)
    prefix :-    * + X Y + Z W

    // Navie - Approach :-
        Two Steps :-    1) Fully Parethesise..
                        2) Start Converting from innermost to outmost..

    X + Y * Z   => (X + (Y * Z))    => (X + * Y Z)   => (+ X * Y Z)

    X ^ Y ^ Z   => (X ^ (Y ^ Z))      => (X ^ (^ Y Z))  => (^ X ^ Y Z)

    Try :-      1)  X + Y * (Z - W)
                2)  X + Y * Z / W + U
    
    ** In Prefix, First Operator and next Operand_1 and next Operand_2..


Infix to Prefix (Efficient Solution)    :-      TC -> 0(N)..    
        This about stack based efficient solution for Infix to Prefx conversion.
    **  This Algorithm which is similiar to Infix to Postfix but, a Little differ.
    
    Algorithm :-            TC -> 0(N)..
    1) Create an empty stack, 'st'..
    2) Create an empty string,'prefix'..
    3) Do following for Every character  C  from "right to left"..
    4) If  C  is:   
        a) Operand :    Append to the string, 'prefix'..
        b) Right Parenthesis :  Push to 'st'..    //  Because we are traversing from right to left..
        c) Left Parenthesis :   Pop from st until right parenthesis is found. Append the popped character to prefix..
        d) Operator :   If st is empty, then push  C  to st..
                        Else compare with st top.
                    1) Higher Precedence(than st top) : Push  C  to st..
                    2) Lower Precedence(than st top) :  Pop st top and append the popped item to prefix until 
                        a higher Precedence operator is found(or st becomes empty). Push C to st..
                    
                    3) Equal Precedence :   Use Associativity..
                        ** In case ^ which comes early has Higher Precedence than last one..    //  It follows right to left Precedence..
                        ** In case +, -, *, /   which comes left most end (or) late has Higher Precedence than early one..    //  It follows left to right Precedence..

    5) Pop everything from 'st', and append to 'prefix' string..    // reaches end..
    6) Return the "reverse of prefix"..

    Infix to Prefix Using Stack :-
    Ex :-    
        1) Input :-   X + Y * Z

    Input Symbol                   Stack                  Prefix (reverse..)
        Z                                                     Z
        *                            *                        Z
        Y                            *                        Z Y 
        +                            +                        Z Y *     //  '+' has lower Precedence so pop out higher precedence '*'..
        X                            +                        Z Y * X 
    
    Pop out everything from stack                             Z Y * X +     //  Reverse the Prefix..
        when it reaches end..                                 + X * Y Z

            Ouput :-   + X * Y Z

        
        2) Input :-    (X + Y) * Z

    Input Symbol                   Stack                  Prefix (reverse..)
        Z                                                     Z
        *                            *                        Z
        Y                            *                        Z Y 
        )                            *,  )                    Z Y 
        +                            *,  ), +                 Z Y 
        X                            *,  ), +                 Z Y X
        (                            *                        Z Y X +        //  Pop out from the stack upto ')' closed bracket..
    Pop out everything from stack                             Z Y X + *      //  Reverse the Prefix..
        when it reaches end..                                 * + X Y Z

            Ouput :-    * + X Y Z

    3) Input :-     X ^ Y ^ Z       //  BEST example for Associativity..

    Input Symbol                   Stack                  Prefix (reverse..)
        Z                                                     Z         
        ^_1                          ^_1                      Z         // ^_1, ^_2 for Identify Purpose..
        Y                            ^_1                      Z Y 
        ^_2                          ^_2                      Z Y ^_1     // ^_1 has higher Percedence.. than ^_2 because it follows right to left in Associativity..
        X                            ^_2                      Z Y ^_1 X 
    Pop out everything from stack                             Z Y ^_1 X ^_2     //  Reverse the Prefix..
        when it reaches end..                                 ^ X ^ Y Z

            Ouput :-   ^ X ^ Y Z
    
     4)  Input :-   X + Y / Z - W * U   =>  ((X + (Y / Z)) - (W * U)) =>  ((X + (/ Y Z)) - (* W U))
                    =>  ((+ X / Y Z) - (* W U))   => (- + X / Y Z * W U)..
        
        Try using Stack..
        
//  Evaluation of Prefix    :-       We traverse from right to left of string..
        This about simple, efficient and stack based solution for evaluation of prefix.

    Input :-   + * 10 2 3       //  it is an  Prefix we need to find the result using infix Generally navie way.. and infix to prefix..
    Output :-   23              //  We traverse from right to left of string..
   
    *** Here Prefix expressions doesn't required any Parenthesis, Associativity, any Precedence..

    I/p  :-     + * 10 2 3
    O/p  :-     we check for operator from right to left, if it's find then do the operation on top 2 operands of stack..
                    + * 10 2 3  => + 20 3   => 23..
    
    I/p  :-     ^ 10 ^ 2 3 
                     _____
    O/p  :-     ^ 10 ^ 2 3  => ^ 10 8  => 100000000

    Idea :- We traverse to the string from right to left when we see any operator, 
                then we take previous two operands (or) top 2 operands of stack.. and
                     do the evaluation with operator..

    **** Algorithm for evaluation of Prefix :-
        1) Create an empty stack st..
        2) Traverse through every symbol X of given Prefix.. from right to left..
            a) If X is operand then we push to st..
            b) Else (X is an operator)
                1) op1 = st.pop();
                2) op2 = st.pop();      // Previous top two operands..
                3) Compute (op1  X  op2) and "push the result to st"..      // Check here it little differ from Postfix..
        3) Return st.top().. when complete the string..
    
    I/p  :-     *  +  10  2  3      //  Infix is  ((10 + 2)* 3) = 36..
                        //  Traverse from right to left..
    Input Symbol (X)                     Stack (st)                             Operations :-  Compute (op1  X  op2)
        3                                  3                                
        2                                  3,  2
        10                                 3,  2,  10                               
        +                                  3,  12                           2 and 10 top of stack and (2 + 10 = 12).. and push to st..
        *                                  36                               3 and 12 top of stack and (3 * 12 = 36).. and push to stack..        
    O/p  => 36..

    I/p :-      ^  10  ^  2  3         (^ is an Exponecial/Power)
                                //  Traverse from right to left..
                                                                                Compute (op1  X  op2)
    Input Symbol (X)                        Stack (st)                             Operations :-
        3                                     3         
        2                                     3,  2                                 //  2 is top of stack..
        ^                                     8                                     2 and 3 top of st.. and (2 ^ 3 = 9) and push st..
        10                                    8,  10                                //  10 is top of st..
        ^                                     100000000                            10 ^ 8 = 100000000 and push to st..

    ** It does only traversal and stack of operands..
    ** Here Prefix expressions doesn't required any Parenthesis, Associativity, any Precedence..

*/



