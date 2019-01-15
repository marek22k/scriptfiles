puts "Hello World!"  # Die Zeichenkette wird im STDOUT-Stream ausgegeben
# Dabei steht STD fur Standert und Out fuer Output also Standert Ausgaben Stream
# Nebenbei gibt es noch den STDERR-Stream, den Standert Error Stream. Auf diesem
# werden Fehlermeldung ausgegeben.
# und es gibt auch noch den STDIN-Stream, also Standert Input Stream, die
# Eingaben von der Konsole.

# Man kann statt puts auch $stdout.puts oder STDOUT.puts schreiben,
# dabei sind $stdout und STDOUT gleich.
# Dies ist aber ueberfluessig da der Standert Stream STDOUT ist.
# Moechte man also dementsprechen.d etwas in den STDERR Stream schreiben wird
# $stderr.puts geschrieben
# Ein sehr groﬂer Unterschied ist das die Ausgaben beim STDERR Stream nicht
# gepuffert werden, sie werden aber beim STDOUT Stream gepuffert.

# Es gibt auch die Funktion print diese hat die gleiche Auswirkung wie
# puts ohne Zeilchenumbruch: Im allgemeinem gilt: print "\n" ist gleich wie
# puts "", dabei kann man bei puts die "" weglassen: puts

# In Ruby sind Klammern bei Funktionen optimal, das heizt Sie koennen da sein
# muessen aber nicht. Man kann also auch puts("test") schreiben. Es waere
# das gleiche wie puts "test".
# Klammern werden in Ruby hauptsaechlich zur uebersichtlichkeit und zur
# Rangsetzung von Funktionen verwendet.

# Autor: Marek K.