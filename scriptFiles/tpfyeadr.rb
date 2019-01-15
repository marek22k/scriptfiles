require "fiber"

(TracePoint.new(:raise) { |tp| p [tp.lineno, tp.event, tp.raised_exception, tp.path] }).enable
(TracePoint.new(:call) { |tp| p [tp.lineno, tp.event, tp.defined_class, tp.method_id, tp.path] }).enable
(TracePoint.new(:thread_begin) { |tp| p [tp.lineno, tp.event, tp.path] }).enable
(TracePoint.new(:thread_end) { |tp| p [tp.lineno, tp.event, tp.path] }).enable
(TracePoint.new(:class) { |tp| p [tp.lineno, tp.event, tp.path] }).enable
(TracePoint.new(:end) { |tp| p [tp.lineno, tp.event, tp.path] }).enable


trace = TracePoint.new(:return) do |tp|
  p [tp.lineno, tp.event, tp.return_value, tp.path]
end

p trace.enabled? # => false
trace.enable # => false
p trace.enabled? # => true
trace.enable # => true

t = Thread.new {}
t.join

class XY
end
def met
1
end

f = Fiber.new do |x|
  Fiber.yield nil
  x.times { |y|
    Fiber.yield y if y.even?
  }
end
met # => 1
trace.disable # => true
trace.disable # => false
f.resume 10 # => nil
while f.alive?
  puts f.resume # => 0, 2, 4, 6, 8, 10
end

f.resume # FiberError: dead fiber called