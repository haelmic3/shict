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
as well as added the concept of an `ac` and a `pc`.

Shict has added 2 additional operators along with these operators.
 - Operator '`:`' Executes as `pc+=*ptr`
 - Operator '`;`' Executes as `ptr=stack.pop();*ptr=ac;`
 - Operator '`a` - `f`' `stack.push(ptr);ac=@;ptr=&@;` where @ is the register

The register operators allow the code to affect their context before evaluating

