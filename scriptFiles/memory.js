/*
Copyright© by Marek Küthe

MEMORY-COOKIE-SYSTEM

*/
function memory_GetMemoryCookie(memory_name){
var n = 'memory_'+memory_name+'=';
var ca = document.cookie.split(';');
for(var i = 0; i < ca.length; i++){
var c = ca[i];
while(c.charAt(0)==' ')
c = c.substring(1,c.length);
if (c.indexOf(n) == 0){
return c.substring(n.length,c.length);
}
}
return null;
}
function delete_memory(memory_name,domain){
document.cookie = "memory_"+memory_name+"=alt_null; path=/; domain="+domain+"; expires=Thu, 01 Jan 1970 00:00:01 GMT";
}
function new_memory(memory_name,memory_code,domain){
var expires = "";
var date = new Date();
date.setTime(date.getTime()+(365*24*60*60*1000));
expires = date.toGMTString();
document.cookie = "memory_"+memory_name+"="+memory_code+"; path=/; domain="+domain+"; expires="+expires;
}
function get_memory(memory_name,name){
var cg = memory_GetMemoryCookie(memory_name);
var e = '';
if(cg != null){
var g = cg.split('?');
var ei = 5;
for (var i = 0; i <= ei; i++){
if(g[i] == name){
i++;
e = g[i];
break;
}
if(g[i] == null){
e = null;
break;
}
ei++;
}
}else{
e = null;	
}
var value = e;
return value;	
}