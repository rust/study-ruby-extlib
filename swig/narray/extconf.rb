require 'mkmf'

dir_config('narray',$sitearchdir,$sitearchdir)

if ( ! ( have_header('narray.h') && have_header('narray_config.h') ) ) then
   print <<-EOS
   ** configure error **  
   Header narray.h or narray_config.h is not found. If you have these files in 
   /narraydir/include, try the following:

   % ruby extconf.rb --with-narray-include=/narraydir/include

   EOS
   exit(-1)
end

if /cygwin|mingw/ =~ RUBY_PLATFORM
  unless have_library('narray')
   print <<-EOS
   ** configure error **  
   libnarray.a is not found.
   % ruby extconf.rb --with-narray-lib=/narraydir/lib

   EOS
   exit(-1)
  end    

end
 
create_makefile('test')
