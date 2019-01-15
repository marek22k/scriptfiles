/*

Copyright© by Marek Küthe

PACK-SYSTEM
PACK-IN-SYSTEM
PACK-OUT-SYSTEM

Import HTML-Code: <script src="http://memory.mk16.de/js/pack.js" type="text/javascript" language="Javascript"></script>

Example:

p = packIn("hu8c8mam88","8","tx5ihbig55","5");
alert(packOut("hu8c8mam88","8",p,"5"));

Output: tx5ihbig55
p[0]: hu,c,mam,,
p[1]: tx,ihbig,,

*/
function packIn(password,p,text,a){
var c = password.split(p);
text = text.split(a);
var pack = [];
pack[0] = c;
pack[1] = text;
return pack;
}
function packOut(password,p,pack,a){
var up = password;
password = password.split(p);
var passwd = "";
for(var i = 0; i <= (password.length-2); i++){
passwd += password[i]+p;	
}
if(up != passwd){}else{
var text = '';
for(var i = 0; i <= (pack[1].length-2); i++){
text += pack[1][i]+a;	
}
return text;
}
return false;
}