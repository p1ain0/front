#include <iostream>
#include "Lexer.h"

int main(int argc, char* argv[])
{
    Lexer lexer;
    Token* x = lexer.scan();
    std::cout << x->toString() << std::endl;
    return 0;
}