# fvtvu = for vs times vs upto
# http://ruby-doc.org/stdlib-2.5.3/libdoc/benchmark/rdoc/Benchmark.html

require "benchmark"

x = 100_000_000
Benchmark.bmbm(7) { |bm|
  bm.report("for") { for i in 0..x; nil; end }
  bm.report("times") { x.times { nil } }
  bm.report("upto") { 0.upto(x) { nil } }
}