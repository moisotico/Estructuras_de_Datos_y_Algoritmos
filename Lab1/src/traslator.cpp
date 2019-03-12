#include <iostream>
#include <string>
#include <iostream>


#include "../include/traslator.h"
#include "../include/TablaVectores.h"

using namespace std;

Traslator::Traslator(){

	result = "";
	sub = "";
	cut = 0;
}

Traslator::~Traslator(){

}

string Traslator::traslate( string s ){

    cut = 0;
    for ( int i=0; i < ( s.size()/3 ); i++ )
    {
		sub = s.substr ( cut, 3 );
		/*una cadena debe siempre empezar con lgún codon de parada, si no empieza
		 * con algno de ellos se añade al resultado
		 * */
		if( ( cut == 0 ) && ( (sub != "UAA") || (sub != "UGA") || (sub != "UAG") ) ){
			result += "|";
		}
		cout << "checking for: " << sub << endl;

		for( int i=0; i < token.size(); i++ ){
			if( sub.compare( token[i].first ) == 0 ){
				result += token[i].second;
				cout << sub << " is a token - parsing" << endl;
				break;
			}
		}
		cut = cut + 3;
	}

	/*ultimo caracter de la cadena debe ser "|", en caso contrario
	 * se añade
	 * */
	if(result.substr(result.size()-1) != "|" ) result += "|" ;

	return result;
}

string* Traslator::traslate( string *s ){
	
    cut = 0;
    for ( int i=0; i < ( s->size()/3 ); i++ )
    {
		sub = s->substr ( cut, 3 );
		/*una cadena debe siempre empezar con lgún codon de parada, si no empieza
		 * con algno de ellos se añade al resultado
		 * */
		if( ( cut == 0 ) && ( (sub != "UAA") || (sub != "UGA") || (sub != "UAG") ) ){
			result += "|";
		}

		cout << "checking for: " << sub << endl;
		for( int i=0; i < token.size(); i++ ){
			if( sub.compare( token[i].first ) == 0 ){
				result += token[i].second;
				cout << sub << " is a token - parsing" << endl;
				break;
			}
		}
		cut = cut + 3;
	}
	/*último caracter de la cadena debe ser "|", en caso contrario
	 * se añade
	 * */
	if(result.substr(result.size()-1) != "|" ) result += "|" ;

	return new string(result);
}
