/*
    Infix, Prefix and Postfix Introduction :-

    Infix, prefix and Postfix are three different ways to write mathematical expressions. 
        These three about their advantages/distadvantages :-

    1) Infix are we general use in mathematical expressions and in programming,
        Infix represented as operand__operator__operand..
        Ex :-   X + Y

    2) Postfix are represented as operand__operand__operator..  {operator comes at the end..}
        Ex :-  X Y + 

    3) Prefix are represented as operator_operand_operand..     {operator comes at the first..}
        Ex :-  + X Y
    
    Advantages of Prefix and Postfix :-
        1) Do not require Parenthesis, Precedence rules and Associativity rules..
        2) Can be evaluated by writing a program that traverses the given expression exactly ones..

    Precedence and Associativity    :-

    Operators        Associativity  
        ^               R to L          {High Precedence..}
        *, /            L to R
        +, -            L to R

        Precedence                : 10 + 20 * 2 => 10 + (20 * 2) => 10 + 40 = 50..
    Associativity (Left to Right) : 10 + 2 - 3  => (10 + 2) - 3  => 12 - 3 = 9..
    Associativity (Right to Left) :  2 ^ 1 ^ 2   => 2 ^ (1 ^ 2)  => 2 ^ 1 = 2..         (^ -> Exponent..)

    1) In Precedence it follows based on the Prioty Operators..
    2) In Associativity in this the operators are equal and follows 
            the ways of operators like left to right side viseversa..
    
            Infix                      Prefix                         Postfix
     X + Y * Z                     + X * Y Z                      X Y Z + *
     (X + Y) * Z                   * + X Y Z                      X Y + Z *

Steps for Postfix Conversion :-
    X + Y * Z   => (X + (Y * Z))  => (X + (Y Z *)) => X Y Z * +

    (X + Y) * Z  => (X Y +) * Z  =>  (X Y +) Z * => X Y + Z *

    ** If Precedence is same then, we follow Associativity rules..
        If Precedence is differ then, we follow Precedence rule..

    Ref :- https://www.geeksforgeeks.org/prefix-postfix-conversion/
*/ 

