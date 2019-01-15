#!/usr/bin/ruby

class Handler
  @@hcount = 0

  def initialize(args = nil, &block)
    @block = block
    @args = args
    @@hcount += 1
    @hid = @@hcount
  end
  
  def call *cargs
    @block.call @hid, @args, cargs
  end
  
  def id
    @hid
  end
  
  def inspect
    "ID: #{@hid}; Args: #{@args}; Func: #{@block}; This: #{super}"
  end
  
end

class Fixnum
  def length
    x = self
    n = 1
    while x > 9
      x /= 10
      n += 1
    end
    n
  end
  
  alias len length
end

BEGIN {
  def method_missing(id, *args)
    puts <<-END 
The method #{id} was not found.
The following arguments have been transferred: #{args}
    END
  end
}

def func(arg1: 0, arg2: 0, arg3: 0)
  arg1 - arg2 + arg3
end

x = func arg2: 5, arg1: 4, arg3: 9
puts (eval "'Result: ' + x.to_s")
undef func
x = func arg2: 5, arg1: 4, arg3: 9


h1 = Handler.new do |handlerid, x, y|
  puts "Handler #{handlerid} was called with the value #{if x then x.join(", ") else "'No Argument'" end} and #{y}"
end
h1.call 5, 6, 7
p h1

h2 = Handler.new {|x|p x}
h2.call
p h2

puts "Length of Number 1234 is #{1234.len}"

__END__
End of the program