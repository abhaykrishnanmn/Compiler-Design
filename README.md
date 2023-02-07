# Compiler-Design
Lex and Yacc installation 
sudo apt install flex
sudo apt install bison yacc
Compiling the lexical analyzer
lex filename.l
gcc lex.yy.c -ll
./a.out
ctrl+d // for output
Compiling the yacc and lex
lex filename.l
yacc -d filename.y
gcc lex.yy.c y.tab.c -ll
./a.out
ctrl+d // for output
