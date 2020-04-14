#include "KMP.h"

void KMP::prefixBuild(){
    _buffer.resize(_pattern.size());

    _buffer[0] = 0;
    for(int i = 1; i < _buffer.size(); ++i){
        int pos = _buffer[i - 1];
        while(pos > 0 && _pattern[pos] != _pattern[i]){
            pos = _buffer[pos - 1];
        }
        if(_pattern[pos] == _pattern[i]){
            ++pos;
        }
        _buffer[i] = pos;
    }
}

std::vector< int >  KMP::find(){
    std::vector< int > result;

    for(int i = 0; i < _text.size(); ++i){
        int pos = _last;

        while(pos > 0 && _pattern[pos] != _text[i]){
            pos = _buffer[pos - 1];
        }

        if(_pattern[pos] == _text[i]){
            ++pos;
        }

        if(pos == _pattern.size()){
            result.push_back(i + 1 - _pattern.size());
        }

        _last = pos;
    }

    return result;
}