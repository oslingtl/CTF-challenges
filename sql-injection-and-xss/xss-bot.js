var page = require('webpage').create();
var host = "localhost";
var port = "5000";
var url = "http://"+host+":"+port+"/xss";
var timeout = 2000;
phantom.addCookie({
    'name': 'Flag',
    'value': 'SA_FLAG{mOnop0ly}',
    'domain': host,
    'path': '/',
    'httponly': false
});
page.onNavigationRequested = function(url, type, willNavigate, main) {
    console.log("[URL] URL="+url);  
};
page.settings.resourceTimeout = timeout;
page.onResourceTimeout = function(e) {
    setTimeout(function(){
        console.log("[INFO] Timeout")
        phantom.exit();
    }, 1);
};
page.open(url, function(status) {
    console.log("[INFO] rendered page");
    setTimeout(function(){
        phantom.exit();
    }, 1);
});