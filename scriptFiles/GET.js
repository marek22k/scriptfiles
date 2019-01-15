<!--
/******************************\
|   function   |   variables   |
|------------------------------|
|     GET      |   (getVar)    |
\******************************/
function GET(getVar){var x = location.href.split("?");
if(x[1] == null){return false;}else{var y = x[1].split("&");
for(i = 0; i < y.length; i++) {var z = y[i].split("=");
if(z[0] == getVar){return z[1];};};};};
// -->