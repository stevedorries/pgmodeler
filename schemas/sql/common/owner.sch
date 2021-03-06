# SQL definition for owner assignment on objects
# PostgreSQL Version: 8.x, 9.0
# CAUTION: Do not modify this file unless that you know what
#          you are doing.
[ALTER ] @{sql-object} $sp

%if @{dif-sql} %then
 %if @{aggregate} %then @{name} [ (] @{types} [)] %end
 %if @{operator} %then @{signature} %end
 %if @{opclass} %then @{name} [ USING ] @{index-type} %end
 %if @{opfamily} %then @{name} [ USING ] @{index-type} %end
 %if @{function} %then @{signature} %end

%else
 @{name}
%end
[ OWNER TO ] @{owner}; $br