#ifndef __COMPRE__
#define __COMPRE__
#include <iostream>
#include <string>
#include <deque>
#include "../include/Dictionary.h"

using namespace std;

class Compressor{

public:
    //Constructor
    Compressor();
    //Valores n, l ,s definidos
    void setOffsetBits(int n);
    void setMatchLenBits(int l);
    void setStringLenBits(int s);
    int CompressFile(string);


private:
    pair<int, int> longest_match();
    void make_space(int bits);

    //deque para acceder al preview_buff
    deque<char> preview_buff;
    //puntero diccionario del LZ
    Dictionary* offset_buff;

    //parametros se guardan en tres bits
    char params[3];

    int window_size;
    int max_substring_len;
    int lookahead_buff;
    int longest_str_len;

    unsigned int bit_buff;
    int used_bits;
    int comp_filesize;


    int window_offset_bits;
    int match_len_bits;
    int str_len_bits;

    //Constantes
    static const int def_window_offset_bits = 11;
    static const int def_match_len_bits = 4;
    static const int def_str_len_bits = 3;
};

#endif
