void setupWebControl () {
  httpServer.on( "/set", animationHandler );
  httpServer.on( "/control", controlHandler );
}

void animationHandler() {
  if(httpServer.arg(0).toInt() != animationMode) {
    animationMode = httpServer.arg(0).toInt();
    httpServer.send ( 200, "text/plain", "Setting!" );
    enableLooping = false;
    delay(200);
    setupAnimation();
    enableLooping = true;
  }else 
    httpServer.send ( 200, "text/plain", "Already set...");
}

void controlHandler() {
  String response = 
"<!DOCTYPE html>"
"<html>"
"<body>"

"  <h1>Control the Boles' Christmas Tree!</h1>"
"  You must be connected to it's WiFi network. Also, switching off of Rainbow can take a little while :)"

"  <br>"
  
"  <button id=\"rainbow\" onclick=\"setRainbow()\"><h2>Rainbow</h2></button><br>"
"  <button id=\"cm_streams\" onclick=\"setStreams()\"><h2>Christmas Streams</h2></button><br>"
"  <button id=\"blueish\" onclick=\"setBlueish()\"><h2>Solid Blueish</h2></button><br>"
"  <button id=\"twinkle\" onclick=\"setTwinkle()\"><h2>Twinkle</h2></button>"

"  <br><br><br>"
  
"  <a href=\"http://192.168.4.1/update\">Update firmware.</a>"
  
"  <script>"
"    function setRainbow() {setMode(0);}"
"    function setStreams() {setMode(1);}"
"    function setBlueish() {setMode(2);}"
"    function setTwinkle() {setMode(3);}"
    
"    var xhr;"
"    function setMode(mode) {"
"      xhr = new XMLHttpRequest();"
"      xhr.open('GET', \"http://192.168.4.1/set?=\" + mode, true);"
"      xhr.send();"
      
"      xhr.addEventListener(\"readystatechange\", processRequest, false);"
"    }"
    
"    function processRequest(e) {"
"        if (xhr.readyState == 4) {"
"        }"
"    }"
"  </script>"

"</body>"
"</html>";

  httpServer.send ( 200, "text/html", response);
}
