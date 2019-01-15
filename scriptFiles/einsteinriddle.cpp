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

#include <iostream>
#include <array>
#include <string>

using namespace std;

// Haus, Person, Editor, Programmiersprache, Datenbanksystem

array<string, 6> house {"red", "gre", "yel", "blu", "ivo", ""};
array<string, 6> person {"hac", "mat", "ana", "dev", "eng", ""};
array<string, 6> editor {"bra", "ato", "not", "vim", "sub", ""};
array<string, 6> proglang {"cpp", "pyt", "jav", "scr", "csh", ""};
array<string, 6> dbsys {"red", "cas", "had", "cas", "mon", ""};

bool Check(array<array<string, 6>, 6> arr)
{
    for(short unsigned i = 0; i < 5; i++)
    {
        if(! (arr[i][0] == "red" && arr[i][1] == "mat")) return false;
        if(! (arr[i][1] == "hac" && arr[i][3] == "pyt")) return false;
        if(! (arr[i][2] == "bra" && arr[i][0] == "gre")) return false;
        if(! (arr[i][1] == "ana" && arr[i][2] == "ato")) return false;
        if((! (arr[i][0] == "gre" && arr[i+1][0] == "ivo")) && i != 4) return false;
        if(! (arr[i][4] == "red" && arr[i][3] == "jav")) return false;
        if(! (arr[i][4] == "cas" && arr[i][0] == "yel")) return false;
        if(! (arr[i][2] == "not" && i == 2)) return false;
        if(! (arr[i][1] == "dev" && i == 0)) return false;
        if(! ((arr[i][4] == "had" && arr[i+1][3] == "scr") || (arr[i][4] == "had" && arr[i-1][3] == "scr"))) return false;
        if(! ((arr[i][4] == "cas" && arr[i+1][3] == "csh") || (arr[i][4] == "cas" && arr[i-1][3] == "csh"))) return false;
        if(! (arr[i][4] == "ara" && arr[i][2] == "sub")) return false;
        if(! (arr[i][1] == "eng" && arr[i][4] == "mon")) return false;
        if(! ((arr[i][1] == "dev" && arr[i+1][0] == "blu") || (arr[i][1] == "dev" && arr[i-1][0] == "blu"))) return false;
    }
    return true;
}

int main()
{
    for(short unsigned i = 0; i < 5; i++)
    {
        for(short unsigned j = 0; j < 5; j++)
        {
            for(short unsigned k = 0; k < 5; k++)
            {
                for(short unsigned l = 0; l < 5; l++)
                {
                    for(short unsigned m = 0; m < 5; m++)
                    {  // 1

                        for(short unsigned n = 0; n < 5; n++)
                        {
                            for(short unsigned o = 0; o < 5; o++)
                            {
                                for(short unsigned p = 0; p < 5; p++)
                                {
                                    for(short unsigned q = 0; q < 5; q++)
                                    {
                                        for(short unsigned r = 0; r < 5; r++)
                                        {  // 2

                                            for(short unsigned s = 0; s < 5; s++)
                                            {
                                                for(short unsigned t = 0; t < 5; t++)
                                                {
                                                    for(short unsigned u = 0; u < 5; u++)
                                                    {
                                                        for(short unsigned v = 0; v < 5; v++)
                                                        {
                                                            for(short unsigned w = 0; w < 5; w++)
                                                            {  // 3

                                                                for(short unsigned x = 0; x < 5; x++)
                                                                {
                                                                    for(short unsigned y = 0; y < 5; y++)
                                                                    {
                                                                        for(short unsigned z = 0; z < 5; z++)
                                                                        {
                                                                            for(short unsigned a = 0; a < 5; a++)
                                                                            {
                                                                                for(short unsigned b = 0; b < 5; b++)
                                                                                {  // 4

                                                                                    for(short unsigned c = 0; c < 5; c++)
                                                                                    {
                                                                                        for(short unsigned d = 0; d < 5; d++)
                                                                                        {
                                                                                            for(short unsigned e = 0; e < 5; e++)
                                                                                            {
                                                                                                for(short unsigned f = 0; f < 5; f++)
                                                                                                {
                                                                                                    for(short unsigned g = 0; g < 5; g++)
                                                                                                    {  // 5

                                                                                                        array<array<string, 6>, 6> arr { {
                                                                                                            { house[i], person[j], editor[k], proglang[l], dbsys[m] },
                                                                                                            { house[n], person[o], editor[p], proglang[q], dbsys[r] },
                                                                                                            { house[s], person[t], editor[u], proglang[v], dbsys[w] },
                                                                                                            { house[x], person[y], editor[z], proglang[a], dbsys[b] },
                                                                                                            { house[c], person[d], editor[e], proglang[f], dbsys[g] },
                                                                                                            { "", "", "", "", "" }
                                                                                                        } };

                                                                                                        if(Check(arr))
                                                                                                        {
                                                                                                            for(short unsigned h = 0; h < 5; h++)
                                                                                                            {
                                                                                                                for(short unsigned ii = 0; ii < 5; ii++)
                                                                                                                {
                                                                                                                    cout << arr[h][ii] << ", ";
                                                                                                                }
                                                                                                                cout << endl;
                                                                                                            }
                                                                                                            cout << endl;
                                                                                                        }
                                                                                                    }
                                                                                                }
                                                                                            }
                                                                                        }
                                                                                    }

                                                                                }
                                                                            }
                                                                        }
                                                                    }
                                                                }

                                                            }
                                                        }
                                                    }
                                                }
                                            }

                                        }
                                    }
                                }
                            }
                        }

                    }
                }
            }
        }
    }
    return 0;
}
