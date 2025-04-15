#include <string>
#include <iostream>
#include <fstream>

int main( int argc, char **argv ) {
    if ( argc != 4 ) {
        std::cout << "Please provide three arguments:\n"
                  << "- filename: the file to read text from.\n"
                  << "- s1: the text that is to be replaced by s2.\n"
                  << "- s2: the text to replace s1 with.\n";
        return 0;
    }

    std::string   infileName( argv[1] );
    std::ifstream infileStream( infileName.c_str() );
    if ( !infileStream ) {
        std::cerr << argv[1] << " could not be opened for reading.\n";
        return 1;
    }

    std::string infileContent( "" );
    std::string buffer( "" );
    while ( std::getline( infileStream, buffer ) ) {
        infileContent.append( buffer );
        if ( !infileStream.eof() )
            infileContent.append( "\n" );
    }

    infileStream.close();

    std::string s1( argv[2] );
    std::string s2( argv[3] );

    size_t s1MatchPos( infileContent.find( s1 ) );
    while ( s1MatchPos != std::string::npos ) {
        infileContent.erase( s1MatchPos, s1.length() );
        infileContent.insert( s1MatchPos, s2 );
        s1MatchPos = infileContent.find( s1 );
    }

    std::ofstream outfileStream( infileName.append( ".replace" ).c_str() );
    if ( !outfileStream ) {
        std::cerr << infileName.append( ".replace" ).c_str()
                  << " could not be opened for writing.\n";
        return 1;
    }

    outfileStream << infileContent;

    outfileStream.close();

    return 0;
}
