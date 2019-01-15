Gem::Specification.new do |s|
  s.name = "hexdata"
  s.version = "1.0.3"
  s.date = "2018-12-12"
  
  s.summary = "Reads and writes (Intel) Hex files."
  s.description = "With hexdata you can create and read (Intel) hex data." +
                  "hexdata also calculates the checksum and calls an exception if it gets wrong." +
                  "hexdata is available under the GNU GPL v3.0."
  
  s.authors = ["Marek K."]
  s.email = "m.k@mk16.de"
  
  s.files = ["lib/hexdata.rb", "test/hexdata_test.rb"]
  s.homepage = "http://test.mk16.de/projects/hexdata-gem"
  s.license = "GPL-3.0"
  s.metadata = {
    "documentation_uri" => "http://test.mk16.de/projects/hexdata-gem",
    "source_code_uri" => "http://test.mk16.de/scriptFiles/hexdata.rb"
  }
end