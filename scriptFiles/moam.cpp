// Author: Marek K.
// moam = M Objects and Missiles

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
#include <ostream>
#include <utility>
#include <string>
#include <vector>

#include <cstdlib>
#include <cstddef>
#include <ctime>

class Field
{
    public:
        Field(std::pair<unsigned, unsigned>);
        ~Field();

        void SetObject(std::pair<unsigned, unsigned>, std::string);
        void SetMissile(unsigned, std::string);
        void Round();
        int life();

        friend void Step(std::pair<unsigned, unsigned>, std::pair<unsigned, unsigned>, Field *);
        friend std::ostream& operator<<(std::ostream&, const Field&);

    protected:
        std::vector<std::vector<int>> field;
        std::vector<std::vector<int>> ok;
        std::vector<std::vector<std::string>> muster;
        std::pair<unsigned, unsigned> size;

};

Field RandomField(std::pair<unsigned, unsigned>, unsigned, unsigned);
void Play(Field &, unsigned limit);
void Step(std::pair<unsigned, unsigned>, std::pair<unsigned, unsigned>, Field *);
std::ostream& operator<<(std::ostream&, const Field&);

Field::Field(std::pair<unsigned, unsigned> xy)
{
    size = xy;
    for(size_t i = 0; i < std::get<0>(xy); i++)
    {
        field.push_back(std::vector<int>());
        for(size_t j = 0; j < std::get<1>(xy); j++)
            field[i].push_back(0);
    }

    for(size_t i = 0; i < std::get<0>(xy); i++)
    {
        ok.push_back(std::vector<int>());
        for(size_t j = 0; j < std::get<1>(xy); j++)
            ok[i].push_back(0);
    }

    for(size_t i = 0; i < std::get<0>(xy); i++)
    {
        muster.push_back(std::vector<std::string>());
        for(size_t j = 0; j < std::get<1>(xy); j++)
            muster[i].push_back("");
    }
}

Field::~Field()
{

}

void Field::SetObject(std::pair<unsigned, unsigned> xy, std::string muster)
{
    field[std::get<0>(xy)][std::get<1>(xy)] = 1;
    this->muster[std::get<0>(xy)][std::get<1>(xy)] = muster;
}

void Field::SetMissile(unsigned x, std::string muster)
{
    field[x][std::get<1>(size)-1] = -1;
    this->muster[x][std::get<1>(size)-1] = muster;
}

void Field::Round()
{
    int val;
    std::string mus;
    long ki, kj;
    for(size_t i = 0; i < std::get<0>(size); i++)
        for(size_t j = 0; j < std::get<1>(size); j++)
            ok[i][j] = 0;

    for(size_t i = 0; i < std::get<0>(size); i++)
        for(size_t j = 0; j < std::get<1>(size); j++)
        {
            if(ok[i][j]) continue;

            val = field[i][j];
            mus = this->muster[i][j];

            if(mus == "") continue;
            ki = i, kj = j;

            if(val < 0)
            {
                switch(mus[-val-1])
                {
                    case 'R': Step(std::make_pair(i, j), std::make_pair(i+1, j), this); ki++; break;
                    case 'L': Step(std::make_pair(i, j), std::make_pair(i-1, j), this); ki--; break;
                    case 'U': Step(std::make_pair(i, j), std::make_pair(i, j-1), this); kj--; break;
                    case 'D': Step(std::make_pair(i, j), std::make_pair(i, j+1), this); kj++; break;
                }

                if(ki == -1) ki++;
                if(static_cast<unsigned>(ki) == std::get<0>(size)) ki--;
                if(kj == -1) kj++;
                if(static_cast<unsigned>(kj) == std::get<1>(size)) kj--;

                if(static_cast<unsigned>(-val) == mus.length())
                    field[ki][kj] = -1;
                else
                    field[ki][kj]--;
            }
            else if(val > 0)
            {
                switch(mus[val-1])
                {
                    case 'R': Step(std::make_pair(i, j), std::make_pair(i+1, j), this); ki++; break;
                    case 'L': Step(std::make_pair(i, j), std::make_pair(i-1, j), this); ki--; break;
                    case 'U': Step(std::make_pair(i, j), std::make_pair(i, j-1), this); kj--; break;
                    case 'D': Step(std::make_pair(i, j), std::make_pair(i, j+1), this); kj++; break;
                }

                if(ki == -1) ki++;
                if(static_cast<unsigned>(ki) == std::get<0>(size)) ki--;
                if(kj == -1) kj++;
                if(static_cast<unsigned>(kj) == std::get<1>(size)) kj--;

                if(static_cast<unsigned>(val) == mus.length())
                    field[ki][kj] = 1;
                else
                    field[ki][kj]++;
            }
        }
}

int Field::life()
{
    unsigned n = 0;

    for(size_t i = 0; i < std::get<0>(size); i++)
        for(size_t j = 0; j < std::get<1>(size); j++)
            if(field[i][j] > 0) n++;

    return n;
}

void Step(std::pair<unsigned, unsigned> xy1, std::pair<unsigned, unsigned> xy2, Field * f)
{
    if(
        std::get<0>(xy2) < std::get<0>(f->size) &&
        std::get<1>(xy2) < std::get<1>(f->size) &&
       f->field[std::get<0>(xy2)][std::get<1>(xy2)] >=0
    )
    {
        f->field[std::get<0>(xy2)][std::get<1>(xy2)] = f->field[std::get<0>(xy1)][std::get<1>(xy1)];
        f->muster[std::get<0>(xy2)][std::get<1>(xy2)] = f->muster[std::get<0>(xy1)][std::get<1>(xy1)];
        f->field[std::get<0>(xy1)][std::get<1>(xy1)] = 0;
        f->muster[std::get<0>(xy1)][std::get<1>(xy1)] = "";
        f->ok[std::get<0>(xy2)][std::get<1>(xy2)] = 1;
    }
}

std::ostream& operator<<(std::ostream& os, const Field& f)
{
    os << "  ";
    for(size_t i = 0; i < std::get<0>(f.size); i++) os << i << " ";
    os << "\n";
    for(size_t i = 0; i < std::get<0>(f.size); i++)
    {
        os << i << " ";
        for(size_t j = 0; j < std::get<1>(f.size); j++)
        {
            os << (f.field[j][i]==0?" ":(f.field[j][i]>0?"x":"#")) << " ";
        }
        os << "\n";
    }

    return os;
}

Field RandomField(std::pair<unsigned, unsigned> xy, unsigned NoO, unsigned LoM)
{
    Field f(xy);

    srand( time(0) );

    std::string muster;
    for(unsigned i = 0; i < NoO; i++)
    {
        muster = "";
        for(unsigned j = 0; j < LoM; j++)
            switch(rand()%4)
            {
                case 0: muster += "R"; break;
                case 1: muster += "L"; break;
                case 2: muster += "U"; break;
                case 3: muster += "D"; break;
            }

        unsigned x = rand()%(std::get<0>(xy)), y = rand()%(std::get<1>(xy));

        f.SetObject( std::make_pair(x, y), muster );
        f.SetMissile(x, muster);
    }

    return f;
}

void Play(Field & f, unsigned limit)
{
    for(unsigned i = 0; i < limit && f.life(); i++)
    {
        std::cout << f << std::endl;
        f.Round();
    }
    std::cout << f << std::endl;
    std::cout << "Life: " << f.life() << std::endl;
}

int main()
{
    using namespace std;

    int ans;
    cout << "1 - Random field" << endl <<
    "2 - User input" << endl;
    cin >> ans;

    if(ans == 1)
    {
        int x, y, NoO, LoM, lim;
        cout << "X Size: ";
        cin >> x;
        cout << "Y Size: ";
        cin >> y;
        cout << "Number of Objects: ";
        cin >> NoO;
        cout << "Length of Muster: ";
        cin >> LoM;
        cout << "Round limit: ";
        cin >> lim;
        Field f = RandomField(make_pair(x, y), NoO, LoM);
        Play(f, lim);
    }
    else if(ans == 2)
    {
        int x, y, NoO, NoM, lim;
        cout << "X Size: ";
        cin >> x;
        cout << "Y Size: ";
        cin >> y;
        cout << "Number of Objects: ";
        cin >> NoO;
        cout << "Number of Missiles: ";
        cin >> NoM;
        cout << "Round limit: ";
        cin >> lim;

        Field f(make_pair(x, y));

        string a;

        cout << "Objects: " << endl;
        for(int i = 0; i < NoO; i++)
        {
            cout << "Muster(R = Right, L = Left, D = Down, U = Up): ";
            cin >> a;
            cout << "X: ";
            cin >> x;
            cout << "Y: ";
            cin >> y;
            f.SetObject(make_pair(x, y), a);
        }

        cout << "Missiles: " << endl;
        for(int i = 0; i < NoM; i++)
        {
            cout << "Muster(R = Right, L = Left, D = Down, U = Up): ";
            cin >> a;
            cout << "X: ";
            cin >> x;
            f.SetMissile(x, a);
        }

        Play(f, lim);
    }
    else
    {
        cerr << "Error: Invalid input!" << endl;
        abort();
    }
    return EXIT_SUCCESS;
}
