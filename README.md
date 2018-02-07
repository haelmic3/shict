Shict
=====
This is a laughable program language based on a idea that every character
has executable power.
It's a supper set on a language called... brain....
The language is based on a single register ptr that holds all the memory.
That language uses only 8 operators
 - Operator '`+`' Executes as `++*ptr;`
 - Operator '`-`' Executes as `--*ptr;`
 - Operator '`>`' Executes as `++ptr;`
 - Operator '`<`' Executes as `--ptr;`
 - Operator '`[`' Executes as `while(*ptr){`
 - Operator '`]`' Executes as `}`
 - Operator '`.`' Executes as `putc(stdout, *ptr);`
 - Operator '`,`' Executes as `*ptr = getc(stdin);`

Shict has added 6 additional register operators
`a` `b` `c` `d` `e` `f`
Shict has added 4 additional operators along with these operators.
 - Operator '`:`' Executes as `pc+=*ptr`
 - Operator '`;`' Executes as `ptr=stack.pop();*ptr=ac;`
 - Operator '`a` - `f`' Executes as `stack.push(ptr);ptr=&@;` where @ is the register
 - Operator '`=`' Executes as `*ptr=*(ptr+*ptr);`
 - Operator '`0`' Executes as `*ptr=0;`
The register operators allow the code to affect their context before evaluating

