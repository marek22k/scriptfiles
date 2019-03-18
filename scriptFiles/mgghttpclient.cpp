/*
    Author: Marek K.

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

    Dieses Programm ist Freie Software: Sie können es unter den Bedingungen
    der GNU General Public License, wie von der Free Software Foundation,
    Version 3 der Lizenz oder (nach Ihrer Wahl) jeder neueren
    veröffentlichten Version, weiter verteilen und/oder modifizieren.

    Dieses Programm wird in der Hoffnung bereitgestellt, dass es nützlich sein wird, jedoch
    OHNE JEDE GEWÄHR,; sogar ohne die implizite
    Gewähr der MARKTFÄHIGKEIT oder EIGNUNG FÜR EINEN BESTIMMTEN ZWECK.
    Siehe die GNU General Public License für weitere Einzelheiten.

    Sie sollten eine Kopie der GNU General Public License zusammen mit diesem
    Programm erhalten haben. Wenn nicht, siehe <https://www.gnu.org/licenses/>. 
*/

#include "mgghttpclient.hpp"

HTTPClient::HTTPClient(boost::asio::io_service * ios) : ios(ios)
{}

void HTTPClient::get(boost::asio::ip::tcp::endpoint & ep, std::string host, std::string path)
{
    boost::asio::ip::tcp::socket sock(*this->ios);
    sock.async_connect(ep, [this, &sock, &host, &path] (const boost::system::error_code & be) {
        
        if(be)
            throw be;
        
        boost::system::error_code berror;
        boost::asio::write(sock, boost::asio::buffer(std::string(
                                                      "GET " + path + " HTTP/1.0\r\n"
                                                      "Host: " + host + "\r\n"
                                                      "Accept: *\r\n"
                                                      "Connection: close\r\n\r\n")), berror);
        
        if(berror)
            throw berror;
        
        boost::asio::streambuf sbuf;
        boost::asio::read(sock, sbuf, boost::asio::transfer_all(), berror);
        
        if(berror && berror != boost::asio::error::eof)
            throw berror;
        
        this->iresult = std::string(boost::asio::buffer_cast<const char *>(sbuf.data()));
        
        size_t he = this->iresult.find("\r\n\r\n");
        if(he == std::string::npos)
        {
            throw std::runtime_error("The server has sent an invalid response.");
        }
        else
        {
            this->iheader = this->iresult.substr(0, he);
            this->ibody = this->iresult.substr(he + 4, this->iresult.length() - he + 1);
            this->istatus = static_cast<size_t>(stoul(this->iheader.substr(9, 3)));
        }
    });
    (*this->ios).run();
}

size_t HTTPClient::status()
{
    return this->istatus;
}

std::string HTTPClient::result()
{
    return this->iresult;
}

std::string HTTPClient::header()
{
    return this->iheader;
}

std::string HTTPClient::body()
{
    return this->ibody;
}
