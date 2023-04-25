#include "Token.h"
#include <string>
#include <cstring>
using String = std::string;

class Num : public Token {

public:

	Num(int v) : Token(NUM){ value = v; }
	virtual String toString() override { return std::to_string(value); }
private:
    int value;
};