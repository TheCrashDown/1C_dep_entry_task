#pragma once
#include <vector>

class KMP
{
public:
    KMP(std::vector< int >& pattern, std::vector< int >& text) : _pattern(pattern), _text(text) {
    prefixBuild();
}

    void prefixBuild();

    std::vector< int > find();

private:
    std::vector< int > _buffer;
    int _last = 0;

    std::vector< int >& _pattern;
    std::vector< int >& _text;
};