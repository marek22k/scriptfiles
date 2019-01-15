class ToDoList
  include Comparable # <=>
  include Enumerable # each

  attr_reader :list

  def initialize *args
    @list = args
    @clist = Hash.new
  end

  def initialize p, *args
    @list = args
    @clist = Hash.new
    @clist.default = 0
    i = -1
    @list.each { |x|
      @clist[x] = p[i+=1]
    }
  end
  
  def <=> other
    return plist <=> other.plist
  end
  
  def each
    pl = Hash.new
    i = -1
    @list.each { |x|
      pl[@clist[x]] = x
    }
    min = 0
    max = 0
    pl.each { |x|
      if x[0] < min then min = x[0] end
      if x[0] > max then max = x[0] end
    }
    for i in min..max
      pl.each { |x|
        yield x[1] if x[0] == max-i-1
      }
    end
  end
  
  protected
    def plist
      li = Array.new
      @clist.each { |key, val|
        li << val
      }
      if li == [] || li[0].class == String
        li.clear
        li << 0
      end
      return li
    end
end

d1 = ToDoList.new [0, 1, -1], "Apfel", "Birnen", "Obst"
d2 = ToDoList.new [2, 3], "Gemuese", "Kattoffel"
d3 = ToDoList.new "Kleber", "Bleistift", "Nehzeug"

d1.map { |x|
  p x
}
p d1 < d2
p d3 < d2
p d2.list
p d3.list