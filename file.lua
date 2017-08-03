
-- loads a level, and puts it on the stack

function load_level (str)
   local file=io.open(str)
   local levelstr = file:read('a')
   return levelstr
end
