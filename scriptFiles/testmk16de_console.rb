require "net/http"
require "fileutils"
#load "FileSystem.rb"

HelpMsg = "module install [MODULENAME]\nmodule init [MODULENAME]\nmodule updata [MODULENAME]\nmodule uninstall [MODULENAME]\nmodule get [MODULENAME]\nmodule copy [MODULENAME]\nhelp\ninit\nexit"

# English

Not_found_command = "__> Error: Command not found!"
Not_found_module = "__> Error: Module not found!"
Invalid_module_name = "__> Error: Invalid module name!"

Download_module = "Download module"
Install_module = "Install module"
Uninstall_module = "Uninstall module"
Initialize_module = "Initialize module"

# German

=begin
Not_found_command = "__> Fehler: Befehl nicht gefunden!"
Not_found_module = "__> Fehler: Modul nicht gefunden!"
Invalid_module_name = "__> Fehler: Ungueltiger Modulname!"

Download_module = "Lade Modul herunter"
Install_module = "Installiere Modul"
Uninstall_module = "Deinstalliere Modul"
Initialize_module = "Initialisiere Modul"
=end


class FileSystem

  def self.CreateFolder foldername, check=false
    FileUtils.mkdir_p foldername if check
    FileUtils.mkdir foldername if check == false
  end
  
  def self.DeleteFolder foldername
    FileUtils.remove_dir foldername
  end
  
  def self.DeleteFile filename
    FileUtils.remove_file filename
  end
  
  def self.FileCopy file1, file2
    FileUtils.copy file1, file2
  end
  
  def self.CreateFile filename, content
    file = open(filename, "w")
    file << content
    file.close
  end
  
  def self.ReadFile filename
    file = open(filename, "r")
    return file.read
  end
  
end

def nfc
  puts Not_found_command
end

def imn
  puts Invalid_module_name
end

def folderCheck
  FileSystem.CreateFolder "testmk16de_console", true
  FileSystem.CreateFolder "testmk16de_console/temp/", true  
  FileSystem.CreateFolder "mk16de_const", true 
end

def installModule x
  if x[2] == nil
    imn
  else
    puts "__> #{Download_module} #{x[2]}"
    
    http = Net::HTTP.get_response("test.mk16.de", "/scriptFiles/#{x[2]}")
    if http.code == "200"
      puts "__> #{Install_module} #{x[2]}"
      folderCheck
      FileSystem.CreateFile "testmk16de_console/#{x[2]}", http.body
    else
      puts Not_found_module
    end
  end
end

def uninstallModule x
  if x[2] == nil
    imn
  else
    puts "__> #{Uninstall_module} #{x[2]}"
    folderCheck
    FileSystem.DeleteFile "mk16de_const/#{x[2]}/#{x[2]}"
    FileSystem.DeleteFolder "mk16de_const/#{x[2]}"
  end
end

def main
  loop do
    print "_> "
    i = gets.chomp
    x = i.split
    case x[0]
    
      when "module"
        case x[1]
          when "install"
            installModule x
            
          when "init"
            if x[2] == nil
              imn
            else
              puts "__> #{Initialize_module} #{x[2]}"
              folderCheck
              FileSystem.FileCopy "testmk16de_console/" + x[2], "testmk16de_console/temp/" + x[2]
              content = FileSystem.ReadFile "testmk16de_console/temp/" + x[2]
              FileSystem.CreateFolder "mk16de_const/#{x[2]}/", true
              FileSystem.CreateFile "mk16de_const/#{x[2]}/#{x[2]}", content
            end
            
          when "uninstall"
            uninstallModule x
            
          when "updata"
            uninstallModule x
            installModule x
          
          when "get"
            puts FileSystem.ReadFile "mk16de_const/#{x[2]}/#{x[2]}"
          
          when "copy"
            puts "__> Copy to"
            print "_> "
            y = gets.chomp
            puts FileSystem.FileCopy "mk16de_const/#{x[2]}/#{x[2]}", y
          
          else
            nfc
         
        end
        
        when "init"
          folderCheck
        
        when "help"
          puts HelpMsg
          
        when "exit"
          puts "__> Goodbye!"
          break;
        
        else
          nfc
          
    end
    #puts x
  end
end

main