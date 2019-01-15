Gem::Specification.new do |s|
  s.name        = "allocate"
  s.version     = "2.0.2"
  s.date        = "2018-12-21"
  s.summary     = "Interface between Ruby and the C functions malloc and free."
  s.description = "Allocate requests memory by means of the C function malloc and can release this memory with the C function free again. It is also possible to set values in the memory area."
  s.authors     = ["Marek K."]
  s.email       = "m.k@mk16.de"
  s.homepage    = "http://test.mk16.de/projects/allocate_doc"
  s.license     = "GPL-3.0"
  s.metadata    = {
    "documentation_uri" => "http://test.mk16.de/projects/allocate_doc",
    "source_code_uri"   => "http://test.mk16.de/scriptFiles/allocate/",
  }  
  s.extensions = ["ext/allocate/extconf.rb"]
  s.files      = ["lib/allocate.rb", "ext/allocate/allocate.c", "test/test_allocate.rb"]
end