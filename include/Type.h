#ifndef __TYPE_H__
#define __TYPE_H__
#include "Word.h"

class Type : public Word {
public:

   Type(String s, Tag tag, int w) : Word(s, tag) {width = w; }

    static bool numeric(Type &p);

    static Type max(Type &p1, Type &p2);

    bool operator==(const Type &other)
    {
        return Word::operator==(static_cast<Word>(other)) && this->width == other.width;
    }

private:
   int width = 0;          // width is used for storage allocation
};

static Type
    gtypeNone = Type("", BASIC, 0),
    gtypeInt = Type("int", BASIC, 4),
    gtypeFloat = Type("float", BASIC, 8),
    gtypeChar = Type("char", BASIC, 1),
    gtypeBool = Type("bool", BASIC, 1);

#endif