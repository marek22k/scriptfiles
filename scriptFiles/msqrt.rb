def sqrt n, x
  num = Array.new
  nstr = n.to_s
  if nstr.length%2 == 0
    num[0] = nstr[0,2]
  else
    num[0] = nstr[0,1]
  end
  j = 1
  for i in (2-nstr.length%2...nstr.length).step 2
    num[j] = nstr[i,2]
    j += 1
  end
  
  res = ""
  
  z = 1
  s = 0
  num[0] = num[0].to_i
  while num[0]-z >= 0
    num[0] = num[0]-z
    z += 2
    s += 1
  end
  res += s.to_s

  k = -1
  i = 1
  while (i <= x || x == -1) && num[i-1] != 0
    s = 0
    z = ((res.to_i*2).to_s + "1").to_i
    if num[i] == nil
      num[i] = "00"
      k = i if k == -1
    end
    num[i] = (num[i-1].to_s + num[i].to_s).to_i 
    while num[i]-z >= 0
      num[i] = num[i]-z
      z += 2
      s += 1
    end
    res += s.to_s
    i += 1
  end
  res.insert(k, ".") unless k == -1
  return res
  
end

print sqrt(ARGV[0].to_i, ARGV[1].to_i)