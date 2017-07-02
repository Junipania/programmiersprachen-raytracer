#ifndef SDFLOADER_HPP
#define SDFLOADER_HPP

#include <iosfwd>
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
 
struct SDFloader
{
    //friend ostream& operator<<(ostream& out, const Mannschaft &m);
    friend std::istream& operator>>( std::istream& is, Material& mat){
	 Mannschaft t;
    	if( getline( is, mat.name, ' ' )
        && is >> mat.ka >> space >> mat.kd >> space >> mat.ks >> space >> mat.m;
        && is.ignore( 9999, std::istream::traits_type::to_int_type( '\n' ) ) )
    return is;
    }

 
std::istream& space( std::istream& in )
{
    char k;
    if( in >> k && k != ' ' )
        in.setstate( std::ios_base::failbit );
    return in;
}


std::vector<Material> readMaterial()
{
    using namespace std;
    vector<Material>holdMaterial;
    ifstream datei( "material_scene.txt" );
    copy( istream_iterator< Mannschaft >( datei ), istream_iterator< Material >(), back_inserter( holdMaterial ) );
    return holdMaterial;
}
};

#endif
