#ifndef __TOKEN_H__
#define __TOKEN_H__
#include <string>
using String = std::string;

enum Tag
{
    AND = 256,
    BASIC = 257,
    BREAK = 258,
    DO = 259,
    ELSE = 260,
    EQ = 261,
    FALSE = 262,
    GE = 263,
    ID = 264,
    IF = 265,
    INDEX = 266,
    LE = 267,
    MINUS = 268,
    NE = 269,
    NUM = 270,
    OR = 271,
    REAL = 272,
    TEMP = 273,
    TRUE = 274,
    WHILE = 275,
};

class Token {
private:
    Tag m_tag;
public:
	Token(Tag t) { m_tag = t; }
    Token(const Token& t) {m_tag = t.m_tag;}
	virtual String toString() {return String("") + static_cast<char>(m_tag);}
    bool operator==(const Token& other)
    {
        return this->m_tag == other.m_tag;
    }
};
#endif