require "yaml"
require "json"
require "csv"

def ErrLog e
  puts "#{e.message} --- #{e.backtrace}"
  exit!
end

def save op=$op, filename=$filename
  begin
    fil = File.new filename, "w"
    YAML.dump($data, fil) if op == 1
    JSON.dump($data, fil) if op == 2
    fil.write($data.to_csv) if op == 3
    fil.close
  rescue Exception => e
    ErrLog e
  end
end

def InfoMsg
  puts "\n1 - New item"
  puts "2 - Insert item"
  puts "3 - Pop item"
  puts "4 - Delete item"
  puts "5 - Show all items"
  puts "6 - Show this message"
  puts "7 - Save"
  puts "8 - Save as YAML"
  puts "9 - Save as JSON"
  puts "10 - Save as CSV"
  puts "11 - Exit and Save"
end

puts "marydb"
puts "======"
puts
puts "1 - New marydb"
puts "2 - Open marydb"

print "Option: "
sel = gets.to_i

puts "\n1 - YAML(*.yaml; *.yml)"
puts "2 - JSON(*.json)"
puts "3 - CSV(*.csv)"

print "Option: "
$op = gets.to_i

puts "\n1 - Integer"
puts "2 - String"

print "Option: "
$type = gets.to_i


$data = Array.new

print "\nFilename: "
$filename = gets.chomp

if sel == 2
  begin
  $data = YAML.load_file($filename) if $op == 1
  $data = JSON.parse(File.read($filename)) if $op == 2
  $data = File.read($filename).parse_csv if $op == 3
  rescue Exception => e
    ErrLog e
  end
end

InfoMsg()
until sel == 11
   print "Option: "
   sel = gets.to_i
   
   case sel
    when 1
      puts "Value: "
      $data << gets.to_i if $type == 1
      $data << gets.chomp if $type == 2
     when 2
      puts "Index: "
      ind = gets.to_i
      puts "Value: "
      $data.insert(ind, if $type == 1 then gets.to_i end)
      $data.insert(ind, if $type == 2 then gets.chomp end)
     when 3
      $data.pop
     when 4
      puts "Index: "
      $data.delete_at gets.to_i
     when 5
      puts $data.join " -#- "
     when 6
      InfoMsg()
     when 7
      save()
     when 8
      print "Filename: "
      save 1, gets.chomp
     when 9
      print "Filename: "
      save 2, gets.chomp
     when 10
      print "Filename: "
      save 3, gets.chomp
   end
end

save()