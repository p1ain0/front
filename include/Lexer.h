#ifndef __LEXER_H__
#define __LEXER_H__
#include "Word.h"
#include "Type.h"
#include "Num.h"
#include "Real.h"
#include <map>
#include <iostream>
#include <cctype>

#define digit(x, limit) (((x) - '0') < limit? ((x) - '0') : -1)

class Lexer {
public:
    void reserve(const Word& w) {
        m_mapWords.emplace(w.toString(), w);
    }
    Lexer() {

      reserve( Word("if",    IF)    );
      reserve( Word("else",  ELSE)  );
      reserve( Word("while", WHILE) );
      reserve( Word("do",    DO)    );
      reserve( Word("break", BREAK) );

      reserve( gwTrue );  reserve( gwFalse );

      reserve( gtypeInt  );  reserve( gtypeChar  );
      reserve( gtypeBool );  reserve( gtypeFloat );
   }

   void readch() { m_charPeek = std::cin.get(); }
   bool readch(char c){
      readch();
      if( m_charPeek != c ) return false;
      m_charPeek = ' ';
      return true;
   }
   Token* scan() {
      for( ; ; readch() ) {
         if( m_charPeek == ' ' || m_charPeek == '\t' ) continue;
         else if( m_charPeek == '\n' ) m_iLine = m_iLine + 1;
         else break;
      }
      switch( m_charPeek ) {
      case '&':
         if( readch('&') ) return new Token(gwAnd);  else return new Token(static_cast<Tag>('&'));
      case '|':
         if( readch('|') ) return new Token(gwOr);   else return new Token(static_cast<Tag>('|'));
      case '=':
         if( readch('=') ) return new Token(gwEq);   else return new Token(static_cast<Tag>('='));
      case '!':
         if( readch('=') ) return new Token(gwNe);   else return new Token(static_cast<Tag>('!'));
      case '<':
         if( readch('=') ) return new Token(gwLe);   else return new Token(static_cast<Tag>('<'));
      case '>':
         if( readch('=') ) return new Token(gwGe);   else return new Token(static_cast<Tag>('>'));
      }
      if( std::isdigit(m_charPeek) ) {
         int v = 0;
         do {
            v = 10*v + digit(m_charPeek, 10); readch();
         } while( std::isdigit(m_charPeek) );
         if( m_charPeek != '.' ) return new Num(v);
         float x = v; float d = 10;
         for(;;) {
            readch();
            if( ! isdigit(m_charPeek) ) break;
            x = x + digit(m_charPeek, 10) / d; d = d*10;
         }
         return new Real(x);
      }
      if( std::isalpha(m_charPeek) ) {
         String s ;
         do {
            s += m_charPeek; readch();
         } while( std::isalnum(m_charPeek) );
         //String s = b;
         auto tmp = m_mapWords.find(s);
         if( tmp != m_mapWords.end() ) return new Word(tmp->second);
         Word* w = new Word(s, ID);
         m_mapWords.emplace(s, *w);
         return w;
      } 
      Token* tok = new Token(static_cast<Tag>(m_charPeek)); m_charPeek = ' ';
      return tok;
   }
private:
    std::map<String, Word> m_mapWords;
    char m_charPeek = ' ';
    int m_iLine = 1;
};

#endif