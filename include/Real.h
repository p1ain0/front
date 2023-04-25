#include "Token.h"

class Real : public Token {
public:
    Real(float v) : Token(REAL) { value = v; }
	String toString() { return std::to_string(value); }
private:
	float value;
};