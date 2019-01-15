trace = TracePoint.new(:call, :return) { |tp|
  puts "Line #{tp.lineno} in #{tp.path}: Call #{tp.method_id} --- #{tp.defined_class}" if tp.event == :call
  puts "Line #{tp.lineno} in #{tp.path}: Return #{tp.return_value}" if tp.event == :return
}

trace.enable

BEGIN {
  Signal.trap("INT") { |signo|
    puts "End"
    exit!
  }
}

print "Ruby Version: "
puts RUBY_VERSION

print "Warnings: "
warn("test1")
warn("test2")

print "Arguments value: "
p ARGV

print "signal list: "
p Marshal.load(Marshal.dump(Signal.list))

print "Marshal \"test\": "
p Marshal.dump("test")

print "Marshal 2: "
p Marshal.dump(2)

print "Marshal [2, 5, 8, 33, 999]: "
p Marshal.dump([2, 5, 8, 33, 999])

print "99.chr.ord"
puts 99.chr.ord
# 1000.chr.ord => RangeError: 1000 out of char range

puts "Enter STRG+C"
puts STDIN.gets