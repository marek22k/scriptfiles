require 'inline'

class CFunctions
  inline do |builder|
    builder.include "<stdio.h>"
    builder.include "<ruby.h>"
    builder.c <<-END
      static VALUE hello_world()
	  {
	      printf("Hello World!\\n");
		  return Qtrue;
	  }
    END
  end
end

cfuncs = CFunctions.new
p cfuncs.hello_world