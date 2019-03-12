#include <iostream>
#include <string>
#include <iostream>

#include "../include/fileutil.h"

using namespace std;

//Constructor
FileUtil::FileUtil( string iname, string oname ){

	iFileName = iname;
	oFileName = oname;

}


FileUtil::~FileUtil(){

}

string FileUtil::read(){

	infile.open ( iFileName.c_str() );

}

string* FileUtil::readLines(){

    while( getline( infile, input_data ) ) ///< leemos todo el archivo
    {
		out_data += input_data;
    }
	infile.close();
	return new string(out_data);

}

int FileUtil::write( string s ){

	outfile.open (oFileName);
	cout << "escribiendo " << s << endl;
    outfile << s << endl;
    outfile << "\n";
    outfile.close();
    return 0;
}

int FileUtil::write( string *s ){

	outfile.open (oFileName);
    outfile << *s << endl;
    cout << "escribiendo " << *s << endl;
    outfile.close();
    delete s;
    return 0;
    
}
