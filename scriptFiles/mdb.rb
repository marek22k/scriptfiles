require "yaml"
require "json"

def SaveDatabase db, fil, op, clo = false
  YAML.dump(db, fil) if op == 1
  JSON.dump(db, fil) if op == 2
  fil.close if clo
end

def ShowMsg
  puts "1 - New/Edit item"
  puts "2 - Get item"
  puts "3 - Show all items"
  puts "4 - Save"
  puts "5 - to YAML"
  puts "6 - to JSON"
  puts "7 - Info message"
  puts "8 - Delete item"
  puts "9 - Exit and Save"
  puts
end

puts "mdb"
puts "==="
puts
puts "1 - New MDB"
puts "2 - Open MDB"
puts "3 - Version"
puts

print "Option: "
sel = gets.to_i
if sel == 3
  puts
  puts
  puts "mdb - mdatabase"
  puts "==============="
  puts
  puts "mdb was written on 17/05/2018 by Marek K. in the programming language Ruby."
  puts
  puts "The databases can be saved via YAML or JSON."
  puts "If an error occurs while reading a database, please pepper the file that should be gelled and the file is not empty."
  puts "If the file is empty, or if the file does not exist, you can use option 1(New MDB) to create a new database, a new file."
  puts "Option 1(New MDB) also allows you to overwrite an existing database."
  puts "If at runtime an error occurs that does not occur when saving or reading the database, please check your input(s)."
  puts
  puts "Note: Please always end the program with option 9(Exit and Save), so that the data can be saved."
  exit!
end
db = Hash.new
puts

puts "Database formats: "
puts "1 - YAML(*.yaml)"
puts "2 - JSON(*.json)"
puts
print "Option: "
op = gets.to_i

print "Filename: "
fn = gets.chomp
case sel
  when 1
    db = Hash.new
    
  when 2
    db = YAML.load_file(fn) if op == 1
    db = JSON.parse(File.read(fn)) if op == 2
end

puts
ShowMsg()

until sel == 9
  print "Option: " 
  sel = gets.to_i
  case sel
    when 1
      print "Item name: "
      name = gets.chomp
      print "Item value: "
      value = gets.chomp
      db[name] = value
    when 2
      print "Item name: "
      name = gets.chomp
      puts "Item value: #{db[name]}"
     when 3
      db.select { |k, v| puts "#{k}: #{v}" }
     when 4
      SaveDatabase db, File.new(fn, "w"), op, true
     when 5
      print "Filename: "
      SaveDatabase db, File.new(gets.chomp, "w"), 1, true
     when 6
      print "Filename: "
      SaveDatabase db, File.new(gets.chomp ,"w"), 2, true
     when 7
      ShowMsg()
     when 8
      print "Item name: "
      db.delete gets.chomp
    end
  puts
end

SaveDatabase db, File.new(fn, "w"), op, true