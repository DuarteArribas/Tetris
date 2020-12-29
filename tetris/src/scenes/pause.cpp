void pause(){
  engine->drop();
  scene=Scene::PAUSE;
  canPlayMusic=true;
  canPlayMusic2=true;
  engine=createIrrKlangDevice();
  engine->setSoundVolume(currentPlayer.getVolume());
}