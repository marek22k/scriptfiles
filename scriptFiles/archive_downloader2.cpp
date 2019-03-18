// Author: Marek K.

/*

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

    Dieses Programm ist Freie Software: Sie koennen es unter den Bedingungen
    der GNU General Public License, wie von der Free Software Foundation,
    Version 3 der Lizenz oder (nach Ihrer Wahl) jeder neueren
    veroeffentlichten Version, weiter verteilen und/oder modifizieren.

    Dieses Programm wird in der Hoffnung bereitgestellt, dass es nuetzlich sein wird, jedoch
    OHNE JEDE GEWAEHR,; sogar ohne die implizite
    Gewaehr der MARKTFAEHIGKEIT oder EIGNUNG FUER EINEN BESTIMMTEN ZWECK.
    Siehe die GNU General Public License fuer weitere Einzelheiten.

    Sie sollten eine Kopie der GNU General Public License zusammen mit diesem
    Programm erhalten haben. Wenn nicht, siehe <http://www.gnu.org/licenses/>.
	
*/

#define ARCHIVE_HOST "test.mk16.de"
#define ARCHIVE_PORT "80"
#define ARCHIVE_PATH "/scriptFiles/"

#include <iostream>
#include <string>
#include <exception>
#include <stdexcept>
#include <fstream>

#include <cstdlib>
#include <cstddef>
#include <cstring>

#include <boost/asio.hpp>
// for my windows pc: g++ main.cpp -IE:\boost_1_69_0 -std=c++17 -lws2_32
// -IE:\boost_1_69_0\ is my C++ Boost library path
// -std=c++17 mean that I use C++17
// and -lws2_32 link thw WinSocket (need for Boost Asio)

int main(int argc, char * argv[])
{
    using boost::asio::ip::tcp;
    
    try
    {
        if(argc < 2)
            throw std::invalid_argument("Invalid command line argument "
                            "PROG_NAME MODULE_NAME; PROG_NAME is archive_downloader.");
        
        if(strcmp(argv[1], "-v") == 0)
        {
            std::cout << "Archive downloader v1.0 rewrite version" << std::endl <<
                         "This program was written by Marek K.<m.k@mk16.de, mk16.de> in the C++ "
                            "programming language on 28/02/2019." << std::endl <<
                         "This program fulfills the same function and works the same as the "
                            "non-rewritten version."
                         "This program is available under the GNU GPL v3.0. (see option -l)"
                            << std::endl <<
                         "This program uses the C++ Boost Library. (see boost.org)" <<
                            std::endl << std::endl <<
                         "For help, see the option -h." << std::endl;
            exit(EXIT_SUCCESS);
        }
        else if(strcmp(argv[1], "-h") == 0)
        {
            std::cout << "This program calls as the first command line argument "
                            "the module name to be downloaded. (MODULE_NAME)" <<
                         "The program then accesses the web server: "
                            "test.mk16.de/[MODULE_NAME]" << std::endl <<
                         "The program then saves the file on the local computer." << std::endl <<
                         "If you want to download a module in a folder, the folder must be"
                            "available for a successful download. The file is then "
                            "stored in the folder." << std::endl << std::endl <<
                         "For version information, see the -v option for the license"
                            ", the -l option." << std::endl;
            exit(EXIT_SUCCESS);
        }
        else if(strcmp(argv[1], "-l") == 0)
        {
            std::cout << "This program is free software: you can redistribute it and/or modify" <<
                    std::endl <<
            "it under the terms of the GNU General Public License as published by" << std::endl <<
            "the Free Software Foundation, either version 3 of the License, or" << std::endl <<
            "(at your option) any later version." << std::endl <<
            std::endl <<
            "This program is distributed in the hope that it will be useful," << std::endl <<
            "but WITHOUT ANY WARRANTY; without even the implied warranty of" << std::endl <<
            "MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the" << std::endl <<
            "GNU General Public License for more details." << std::endl <<
            std::endl <<
            "You should have received a copy of the GNU General Public License" << std::endl <<
            "along with this program.  If not, see <http://www.gnu.org/licenses/>." << std::endl
                    << std::endl <<
            "Dieses Programm ist Freie Software: Sie koennen es unter den Bedingungen" <<
                    std::endl <<
            "der GNU General Public License, wie von der Free Software Foundation," << std::endl
                    <<
            "Version 3 der Lizenz oder (nach Ihrer Wahl) jeder neueren" << std::endl <<
            "veroeffentlichten Version, weiter verteilen und/oder modifizieren." << std::endl <<
            std::endl <<
            "Dieses Programm wird in der Hoffnung bereitgestellt, dass es nuetzlich sein wird, "
                    "jedoch" << std::endl <<
            "OHNE JEDE GEWAEHR,; sogar ohne die implizite" << std::endl << 
            "Gewaehr der MARKTFAEHIGKEIT oder EIGNUNG FUER EINEN BESTIMMTEN ZWECK." << std::endl
                    <<
            "Siehe die GNU General Public License fuer weitere Einzelheiten." << std::endl << 
            std::endl << 
            "Sie sollten eine Kopie der GNU General Public License zusammen mit diesem"
                    << std::endl <<
            "Programm erhalten haben. Wenn nicht, siehe <http://www.gnu.org/licenses/>." <<
                    std::endl << std::endl <<
            "For version information, see the -v option for help with the -h option." << std::endl;
            exit(EXIT_SUCCESS);
        }
        
        std::cout << "Start the program ..." << std::endl;
        boost::asio::io_service ioservice;
        
        std::string host = ARCHIVE_HOST;
        std::string port = ARCHIVE_PORT;
        std::string filename = std::string(argv[1]);
        std::string path = ARCHIVE_PATH + filename;
        
        // Get IP address
        std::cout << "Determine IP address ..." << std::endl;
        tcp::resolver tresolver(ioservice);
        tcp::resolver::query query(host, port);
        tcp::socket tsocket(ioservice);
        
        tresolver.async_resolve(query, [&ioservice, &tsocket, &path, &host, &filename] (const boost::system::error_code & berror,
                             boost::asio::ip::tcp::resolver::iterator endpoint_iterator)
        {
            using boost::asio::ip::tcp;
            std::cout << "IP from web server: " << endpoint_iterator->endpoint().address() <<
                    std::endl;
            
            if(berror)
                throw berror;
            
            // Make a connection
            std::cout << "Make a connection ..." << std::endl;
            
            tsocket.async_connect(endpoint_iterator->endpoint(), [&tsocket, &path, &host, &filename] (const boost::system::error_code & berror) {
                if(berror)
                    throw berror;
            
                boost::system::error_code berrorin;
                
                // Send the request
                std::cout << "Send the HTTP request ..." << std::endl;
                boost::asio::write(tsocket, boost::asio::buffer(std::string(
                                                      "GET " + path + " HTTP/1.0\r\n"
                                                      "Host: " + host + "\r\n"
                                                      "Accept: *\r\n"
                                                      "Connection: close\r\n\r\n")), berrorin);
                
                if(berrorin)
                    throw berrorin;
                
                // Get the result
                std::cout << "Evaluate the result ..." << std::endl;
                boost::asio::streambuf buf;
                boost::asio::read(tsocket, buf, boost::asio::transfer_all(), berrorin);
                
                if(berrorin && berrorin != boost::asio::error::eof)
                    throw berrorin;
                
                std::string str = std::string(boost::asio::buffer_cast<const char *>(buf.data()));
        
                size_t he = str.find("\r\n\r\n");
                if(he == std::string::npos)
                {
                    throw std::runtime_error("The web server does not return an evaluable"
                                        "HTTP header for this program.");
                }
                else
                {
                    std::string header = str.substr(0, he);
                    // 2, because 1 and 4, because \r\n\r\n ...
                    std::string body = str.substr(he + 4, str.length() - he + 1);
                    //cout << "Header: " << header << endl << "Body: " << body << endl;
            
                    // Get status from the http header at pos 9 with the length of 3
                    size_t status = static_cast<size_t>(stoul(header.substr(9, 3)));
            
                    if(status != 200)
                    {
                        std::cerr << "The web server did not return a successful message. "
                                     "HTTP header code: " << status << std::endl;
                        throw std::runtime_error("webserver answer");
                    }
            
                    // Save the file
                    std::cout << "Save the result in a file ..." << std::endl;
                    std::ofstream fil(filename, std::ios::out | std::ios::binary);
                    fil << body;
                    fil.close();
                }
            });
            
        });
        
        ioservice.run();
    }
    catch (std::exception & e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        exit(EXIT_FAILURE);
    }
    catch(boost::system::error_code & e)
    {
        std::cerr << "Error: " << e.message() << std::endl;
        exit(EXIT_FAILURE);
    }

    std::cout << "Finished!" << std::endl;
    return EXIT_SUCCESS;
}