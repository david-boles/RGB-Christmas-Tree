void setupWebControl () {
  httpServer.on( "/set", animationHandler );
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
    httpServer.send ( 200, "text/plain", "Already set..." );
}

