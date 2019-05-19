# Author: Marek K.

#=
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
=#

#=
    The program creates a plot and a histogram showing the distribution of random numbers.
    The first command line argument specifies the "precision", ie the number of random numbers from which the programs are created.
=#    

acc = 100

if length(ARGS) != 0
    acc = parse(Int, ARGS[1])
end

println("Using Plots ...")
using Plots

println("Create random numbers (1/2) ...")
rndNums1 = rand(0:9, acc)
println("Create random numbers (2/2) ...")
rndNums2 = rand(0:9, acc)

println("Create histogram (1/2) ...")
pl1 = histogram(rndNums1,
                nbins   = 10,
                title   = "Random numbers",
                label   = "Count of random numbers 1",
                xlabel  = "Random number",
                ylabel  = "Count of random numbers",
                xticks  = 0:9)
            
println("Create histogram (2/2) ...")
histogram!(pl1, rndNums2,
          nbins   = 20,
          label   = "Count of random numbers 2")

println("Create plots (1/2) ...")
pl2 = plot(rndNums1,
           title   = "Random numbers",
           label   = "Random numbers 1",
           xlabel  = "Number of the random number",
           ylabel  = "Random number")

println("Create plots (2/2) ...")    
plot!(pl2, rndNums2,
      label   = "Random numbers 2")

println("Save files (1/2) ...")
savefig(pl1, "random_numbers1.svg")
println("Save files (2/2) ...")
savefig(pl2, "random_numbers2.svg")