def GetClasses obj
  # GetClasses written by Marek K.
  newobj = obj.class
  print newobj
  newobj = newobj.superclass
  while newobj != nil
    print " -> #{newobj}"
    newobj = newobj.superclass
  end
end

x = lambda { |arg| arg }
y = -> (arg) { x.(arg) }
z = -> { y[2] }

print z[], z.(), z.yield, "\n"
GetClasses -> {}

p = Proc.new { |x| x }
print "\n", p[4], " ",  p[].inspect, " ", p[3, 4], "\n"
GetClasses p

printf "\n%d", y.yield(p[3])
x = nil

require "scanf"
x = "122".scanf("%d")[0]
printf "%d", x

=begin

Output:

222
Proc -> Object -> BasicObject
4 nil 3
Proc -> Object -> BasicObject
3122
  
=end