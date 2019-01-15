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

#pragma once

#ifndef MBIGNUM_HPP
#define MBIGNUM_HPP

#include <string>  /* string */


/** \brief MBN_LEN (aka unsigned short) contains the length of a mbignum.
 */
typedef unsigned short MBN_LEN;

/** \brief mbignum is a class that stores large numbers.
 */
class mbignum
{
    protected:
        char * str;
        MBN_LEN nlen;

    public:

        /** \brief Initializes a new mbignum
         *
         * \param 255 MBN_LEN Length of the number
         *
         */
        mbignum(MBN_LEN = 255);

        /** \brief Checks if mbignum is operational.
         *
         * \return bool If so, then it returns true otherwise false.
         *
         */
        bool good() const noexcept;

        /** \brief Checks if mbignum is operational.
         *
         * \return bool If so, then it returns false otherwise true.
         *
         */
        bool bad() const noexcept;

        /** \brief Free the memory requested during initialization. After this function has been cited, the mbignum is no longer operational.
         *
         * \return void
         *
         */
        void destroy() noexcept;

        /** \brief Check if the number is zero(0).
         *
         * \return bool If so, then it returns true otherwise false.
         *
         */
        bool zero() const noexcept;

        /** \brief Returns the maximum length of an mbignum.
         *
         * \return MBN_LEN The maximum length of the mbignum
         *
         */
        MBN_LEN maxlength() const noexcept;

        /** \brief Returns the maximum length of an mbignum.
         *
         * \return MBN_LEN The maximum length of the mbignum
         *
         */
        MBN_LEN length() const noexcept;

        /** \brief Returns a pointer to the C string containing the number.
         *
         * \return char* The pointer containing the number.
         *
         */
        char * ptr() const noexcept;

        /** \brief Assign a new number to the mbignum.
         *
         * \param [] char The number, as char [], to which the mbignum should be assigned.
         * \return void
         *
         */
        void operator=(char []);

        /** \brief Add this with another mbignum.
         *
         * \param  mbignum& The other mbignum to be added to this mbignum.
         * \return mbignum The result of the addition.
         *
         */
        mbignum operator+(mbignum &) const;

        /** \brief Subtracts this with another mbignum.
         *
         * \param  mbignum& The other mbignum to be subtracted to this mbignum.
         * \return mbignum The result of the subtraction.
         *
         */
        mbignum operator-(mbignum &) const;

        /** \brief Add a mbignum to this one.
         *
         * \param  mbignum& The number to be added.
         * \return mbignum The result of the addition.
         *
         */
        mbignum operator+=(mbignum &);

        /** \brief Subtracts a mbignum to this one.
         *
         * \param  mbignum& The number to be subtracted.
         * \return mbignum The result of the subtraction.
         *
         */
        mbignum operator-=(mbignum &);

        /** \brief Check if two mbignum numbers are equal.
         *
         * \param  mbignum& The mbignum number to compare with.
         * \return bool If so, it returns true, otherwise false.
         *
         */
        bool operator==(mbignum &) const noexcept;

        /** \brief Check if two mbignum numbers are unequal.
         *
         * \param  mbignum& The mbignum number to compare with.
         * \return bool If so, it returns true, otherwise false.
         *
         */
        bool operator!=(mbignum &) const noexcept;

        friend std::string to_string(mbignum);
};

/** \brief Converts a mbignum to a string.
 *
 * \param mbignum The mbignum that should be converted.
 * \return std::string The converted mbignum.
 *
 */
std::string to_string(mbignum);

#endif  // MBIGNUM_HPP
