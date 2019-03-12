#ifndef __DESCOMP__
#define __DESCOMP__
#include <iostream>
#include <string>
#include <deque>

using namespace std;

class Decompressor{
public:
    //Constructor
    Decompressor();
    int getCompSize();
    int DecompFile(string);

private:
    deque<char> window;
    int window_size;
    int max_substring_len;
    int lookahead_buff;
    int longest_str_len;

    int window_offset_bits;
	int match_len_bits;
	int str_len_bits;
    int comp_filesize;
	int decomp_filesize;

    //Default
    static const int def_window_offset_bits = 11;
    static const int def_match_len_bits = 4;
    static const int def_str_len_bits = 3;

    //Funciones
    void setOffsetBits(int n);
    void setMatchLengthBits(int l);
    void setStringLengthBits(int s);
};

#endif
