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

/*

    WARNING
    =======
    
    When the program is run, all files in the folder where the program is run and
    any subdirectory files are deleted without asking for permission.

*/

/*
    This program needs the dirent.h header file.
    The program only supports file names that are not longer than 254 characters.

    The program does not delete itself and its source code file itself.
    Therefore, the PROGRAM_NAME macro should be changed in a non-Windows environment.
*/

#define PROGRAM_NAME "filesremover.exe"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <dirent.h>


int remover(char *);

int main()
{
    if(remover("./"))
        printf("Success!\n");
    else
        printf("Failure!\n");
    return 0;
}

int remover(char * folder)
{
    DIR * d;
    struct dirent * e;
    char * file;
    char * tmp;

    file = malloc(sizeof(char) * (strlen(folder) + 255));
    
    if( (d = opendir(folder)) )
    {
        printf("In Folder %s\n", folder);
        while( (e = readdir(d)) )
        {
            strcpy(file, folder);
            strncat(file, e->d_name, 255-strlen(folder));
            if( ! access(file, F_OK) &&
                strcmp(e->d_name, "filesremover.exe") != 0 &&
                strcmp(e->d_name, "filesremover.c") != 0 &&
                strcmp(e->d_name, "") != 0 &&
                strcmp(e->d_name, ".") != 0 &&
                strcmp(e->d_name, "..") != 0 )
            {
                if( remove(file) )
                {
                    tmp = malloc(sizeof(char) * strlen(file) + sizeof(char) * 2);
                    strcpy(tmp, file);
                    strcat(tmp, "/");
                    if( ! remover(tmp) )
                        fprintf(stderr, "Error can not delete: %s\n", file);
                    free(tmp);
                }
                else
                {
                    printf("Removed: %s\n", file);
                }
            }
        }
        printf("Delete folder: %s\n", folder);
        rmdir(folder);
    }
    else
    {
        fprintf(stderr, "Can not open dir %s\n", folder);
        free(file);
        return 0;
    }
    free(file);
    return 1;
}
