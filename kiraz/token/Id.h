#ifndef KIRAZ_TOKEN_ID_H
#define KIRAZ_TOKEN_ID_H

#include <kiraz/Token.h>

namespace token {

class Id : public Token {
public:
    Id(std::string_view value) : Token(ID), m_value(value){}
    virtual ~Id();

    std::string as_string() const override {return fmt::format("Id",m_value);}
    void print(){fmt::print("{}\n",as_string());}

    static int colno;

    auto get_value() const {return m_value;}

    private:

        int m_id;
        std::string m_value;


};

}

#endif // KIRAZ_TOKEN_ID_H
