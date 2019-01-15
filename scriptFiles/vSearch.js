/*
Copyright© by Marek Küthe

vSearch

*/
function vSearch(ec, search, Bstart, Bend) {
var ep = ec.split(Bend);
for(var i = 0; i <= ep.length; i++){
ep[i] = ep[i].split(Bstart);
for(var r = 0; r <= ep[i].length; r++){
var a = ep[i][r];
if(a == search){
var t = r + 1;
return ep[i][t];
}else{return null;}}}}