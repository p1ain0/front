#ifndef __WORD_H__
#define __WORD_H__

#include "Token.h"

class Word : public Token {
private:
    String m_strLexeme;
public:
    Word(const char *s, Tag tag):Token(tag) {m_strLexeme = s;}
    Word(String s, Tag tag):Token(tag) { m_strLexeme = s; }
    Word(const Word& w):Token(static_cast<Token>(w)) {m_strLexeme = w.m_strLexeme;};
    String toString() const { return m_strLexeme; }

    bool operator==(const Word& other)
    {
        return Token::operator==(static_cast<Token>(other)) && this->m_strLexeme == other.m_strLexeme;
    }

};

static Word gwAnd = Word("&&", AND),
            gwOr = Word("||", OR),
            gwEq = Word("==", EQ),
            gwNe = Word("!=", NE),
            gwLe = Word("<=", LE),
            gwGe = Word(">=", GE),
            gwMinus = Word("minus", MINUS),
            gwTrue = Word("true", TRUE),
            gwFalse = Word("false", FALSE),
            gwTemp = Word("t", TEMP);
#endif