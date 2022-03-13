/*

    Infix to Postfix :-

Infix to Postfix (Simple Solution) // Navie - Solution :-

    This about simple method for Infix to Postfix conversion.

    1) First Full Parenthesis the expression after it, conver the Inner most expressions into postfix and 
        then its Outer expressions..and final we get the equivalent Postfix expressions..

    Ex :-
    1)  a + b * (c - d)     => (a + b * (c - d))    => (a + (b * (c d -)))   => (a + (b c d - *))   => (a b c d - * +)

    2)  a + b * c / d + e   => ((a + ((b * c) / d)) + e)  => ((a + ((b c *) / d)) + e)  => ((a + (b c * d /)) + e)

                    => ((a b c * d / +)  + e)    =>  (a b c * d / + e +)

//      Efficient Solution :-    infix to postfix conversion using stack..  TC -> 0(N)..
    By following the Algorithm..
    1) Create an empty stack, st..
    2) Do following for every character X from left to right..
    3) If X is :    
        a) Operand : Output it/ Append to result string..
        b) Left Parenthesis : Push to st..
        c) Right Parenthesis : Pop from st until left Parenthesis is found. Output the Popped operators..
        
        d) Operator : If st is empty then, push X to st 
                    Else compare st.top() with X..  if it higher or lower or equal then follow below conditions.. 
                     
            1) Higher Precedence (than st.top()) then push X to st..
            2) Lower Precedence, pop st top and output until a higher precedence operator is found.
                    Then push X to st.. {Take out the higher precedence of the stack.. and push the lower precedence.. }

            3) Equal Precedence, use Associativity..    
                Note :-   Same Precedence has same Associativity..
                    Means from left to right Associativity, the operator which is prev_operator has higher precedence..
                          from right to Left Associativity, the operator which is prev_operator has lower precedence..

    4) Pop and output everything from st.. when expression is completed..

    Input =>  a + b * c
    
    Input Symbol(X)                     Stack                   Result(Postfix)
        a                                                             a
        +                                +                            a
        b                                                             a b
        *                                +,  *                        a b
        c                                +,  *                        a b c
pop out everything one                                                a b c * +
by one and print    

    ^                   ^
    *, /                |
    +, -                |   {Precedence}
    (                   |


    Input =>  (a + b) * c
    
    Input Symbol(X)                     Stack                   Result(Postfix)
        (                                (                            (
        a                                                             a
        +                                +                            a
        b                                                             a b
        )                          // pop out till "("                a b +
        *                                *                            a b +
        c                                *                            a b + c
pop out everything one                                                a b + c *
by one and print    


    Input =>  a * b / c
    
    Input Symbol(X)                     Stack                   Result(Postfix)
        a                                                             a
        *                                *                            a
        b                                                             a b
        /                                /                            a b *        //  Because * has higher precedence than /
        c                                                             a b *
pop out everything one                                                a b * c /
by one and print    

    Input => a + b / c - d * e  => ((a + (b / c)) - (d * e))  => ((a + (b c /)) - (d e *))  => ((a b c / +) - (d e *))
                    => (a b c / + d e * -)      // Navie - Solution..

 Input =>  a + b / c - d * e
    
    Input Symbol(X)                     Stack                   Result(Postfix)
        a                                                             a
        +                                +                            a 
        b                                                             a b
        /                                +,  /                        a b 
        c                                +,  /                        a b c 
        -                                -                            a b c / +     // Here "+" has higher precedence than "-"..
        d                                -                            a b c / + d
        *                                -,   *                       a b c / + d
        e                                -,   *                       a b c / + d e
pop out everything one                                                a b c / + d e * -
by one and print    

        // TC -> 0(N).. Push and Pop takes 0(1)..



//          Evaluation of Postfix :-
    This about a simple, efficient and stack based solution for evaluation of postfix.

    Input :-   10 2 * 3 +       //  it is an  Postfix we need to find the result using infix Generally navie way.. and infix to post..
    Output :-   23


    In Evaluation of Postfix :-     
        Here Postfix expressions doesn't required any Parenthesis, Associativity, any Precedence..

    I/p  :-     10 2 + 3 *
    O/p  :-     we check for operator from left to right, if it's find then do the operation on prev operands..
                    10 2 + 3 *  => 12 3 *   => 36
    
    I/p  :-     10 2 3 ^ ^
                   _____
    O/p  :-     10 2 3 ^ ^  => 10  8 ^  => 100000000

    Idea :- We traverse to the string from left to right when we see any operator, 
    then we take previous two operands and do the  evaluation with operator..

    **** Algorithm for evaluation of Postfix :-
        1) Create an empty stack st..
        2) Traverse through every symbol X of given Postfix..
            a) If X is operand then we push to st..
            b) Else (X is an operator)
                1) op1 = st.pop();
                2) op2 = st.pop();      // Previous top two operands..
                3) Compute (op2  X  op1) and "push the result to st"..
        3) Return st.top()..
    
    I/p  :-     10  2  *  3  5  *  +  9  -      //  Infix is    [(10 * 2) + (3 * 5) - 9]

    Input Symbol (X)                     Stack (st)                             Operations :-
        10                                  10
        2                                   10,  2                                  
        *                                                                        10 * 2 = 20 and push to st..
        3                                   20,  3                      
        5                                   20,  3,  5                      
        *                                   20,  15                               3 * 5 = 15 and push to st..
        +                                   35                                    20 + 15 = 35 and push to st..
        9                                   35,  9                              
        -                                   26                                    35 - 9 = 26 and push to st...

    O/p  => 26..

    I/p :-      10  2  3 ^ ^        (^ is an Exponecial/Power)

    Input Symbol (X)                        Stack (st)                             Operations :-
        10                                     10           
        20                                     10,  2   
        30                                     10,  2,  3                                               
        ^                                      10,  8                               2 ^ 3 = 8 and push to st.. because 2 and 3 are prev top two operands..
        ^                                      100000000                            10 ^ 8 = 100000000 and push to st..

    ** It does only traversal and stack of operands..
    ** Here Postfix expressions doesn't required any Parenthesis, Associativity, any Precedence..

*/ 

