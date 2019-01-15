function setId(e, id){e.id=id;};
function editStyleById(id){return document.getElementById(id).style;};
function getElementById(id){return document.getElementById(id);};
function editContentById(id, newContent){document.getElementById(id).innerHTML=newContent;return true;};
function clearContentById(id){document.getElementById(id).innerHTML=null;return true;};
function getContentById(id){return document.getElementById(id).innerHTML;};