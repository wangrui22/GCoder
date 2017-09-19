#ifndef GOODCODER_PARSER_H
#define GOODCODER_PARSER_H

#include <memory>
#include <vector>

#include <boost/log/trivial.hpp>

#include "build_in_parser.h"
#include "custom_parser.h"

namespace good_coder {
class Parser {
public:
    static const int MAX_COLUMN = 4096;    
public:
    Parser();
    ~Parser();
    int read_line(const char* buffer);

    template <class T> int get_item(const int column, T* res) {
        if (_row == 0) {
            BOOST_LOG_TRIVIAL(fatal) << "no buffer input yet.";
            return -1;
        }

        if (column > _column - 1) {
            BOOST_LOG_TRIVIAL(fatal) << "input column overflow.";
            return -1;
        }

        return parse(_str_cache[column], res);
    }

    template <class T> int get_item(const int column, T* res, int space) {
        if (_row == 0) {
            BOOST_LOG_TRIVIAL(fatal) << "no buffer input yet.";
            return -1;
        }

        if (column > _column - 1) {
            BOOST_LOG_TRIVIAL(fatal) << "input column overflow.";
            return -1;
        }

        return parse(_str_cache[column], res, space);
    }

protected:
private:
    int _row;
    int _column;
    const char* _str_cache[MAX_COLUMN] ;

};
}

#endif
