def sc obj
    x = obj.superclass
    if x != nil
        print " => #{x}"
        sc(x)
    end
    return x
end

def grc op, obj
    x = obj.class
    print "#{op} --- #{x}"
    sc(x)
    puts
end

grc("to_r", 0.to_r)
grc("to_c", 0.to_c)
grc("to_f", 0.to_f)
grc("to_i", 0.to_i)
grc("to_i", 16*100000000.to_i)

gets