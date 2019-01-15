require "fileutils"

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