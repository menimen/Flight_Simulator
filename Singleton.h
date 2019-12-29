//
// Created by meni on 22/12/2019.
//

#ifndef FLIGHTSIMULATOR__SINGLETON_H_
#define FLIGHTSIMULATOR__SINGLETON_H_
#include "Command.h"
#include "Var_Data.h"
#include "ValueAndNameObject.h"
#include <fstream>
#include <map>
#include <iterator>
#include <string>
#include <iostream>
#include <list>
#include <utility>
#include <fstream>
#include <regex>
#include <sstream>
using namespace std;
class Singleton {
 private:
  vector<string> str_array;
  map<string,Command*> strToCommandMap;//this is the map of string-command relation
  map<string,Var_Data> symbolTableToServer;//this the map to store data that we want to send to server
  map<string,Var_Data> symbolTableFromServer; //this is the map to store data we got from server
  map<string,float> generic_smallMap = {}; //this is the temporary map to store string and float from ‫‪generic_small.xml‬‬
  map<string,ValueAndNameObject> AllVarsFromXML = { {"/instrumentation/airspeed-indicator/indicated-speed-kt",{0,"/instrumentation/airspeed-indicator/indicated-speed-kt"}},
      {"/sim/time/warp",{0,"/sim/time/warp"}},
      {"/controls/switches/magnetos",{0,"/controls/switches/magnetos"}},
      {"/instrumentation/heading-indicator/offset-deg",{0,"/instrumentation/heading-indicator/offset-deg"}},
      {"/instrumentation/altimeter/indicated-altitude-ft",{0,"/instrumentation/altimeter/indicated-altitude-ft"}},
      {"/instrumentation/altimeter/pressure-alt-ft",{0,"/instrumentation/altimeter/pressure-alt-ft"}},
      {"instrumentation/attitude-indicator/indicated-pitch-deg",{0,"instrumentation/attitude-indicator/indicated-pitch-deg"}},
      {"instrumentation/attitude-indicator/indicated-roll-deg",{0,"instrumentation/attitude-indicator/indicated-roll-deg"}},
      {"/instrumentation/attitude-indicator/internal-pitch-deg",{0,"/instrumentation/attitude-indicator/internal-pitch-deg"}},
      {"/instrumentation/attitude-indicator/internal-roll-deg",{0,"/instrumentation/attitude-indicator/internal-roll-deg"}},
      {"/instrumentation/encoder/indicated-altitude-ft",{0,"/instrumentation/encoder/indicated-altitude-ft"}},
      {"/instrumentation/encoder/pressure-alt-ft",{0,"/instrumentation/encoder/pressure-alt-ft"}},
      {"/instrumentation/gps/indicated-altitude-ft",{0,"/instrumentation/gps/indicated-altitude-ft"}},
      {"/instrumentation/gps/indicated-ground-speed-kt",{0,"/instrumentation/gps/indicated-ground-speed-kt"}},
      {"/instrumentation/gps/indicated-vertical-speed",{0,"/instrumentation/gps/indicated-vertical-speed"}},
      {"/instrumentation/heading-indicator/indicated-heading-deg",{0,"/instrumentation/heading-indicator/indicated-heading-deg"}},
      {"/instrumentation/magnetic-compass/indicated-heading-deg",{0,"/instrumentation/magnetic-compass/indicated-heading-deg"}},
      {"/instrumentation/slip-skid-ball/indicated-slip-skid",{0,"/instrumentation/slip-skid-ball/indicated-slip-skid"}},
      {"/instrumentation/turn-indicator/indicated-turn-rate",{0,"/instrumentation/turn-indicator/indicated-turn-rate"}},
      {"/instrumentation/vertical-speed-indicator/indicated-speed-fpm",{0,"/instrumentation/vertical-speed-indicator/indicated-speed-fpm"}},
      {"/controls/flight/aileron",{0,"/controls/flight/aileron"}},
      {"/controls/flight/elevator",{0,"/controls/flight/elevator"}},
      {"/controls/flight/rudder",{0,"/controls/flight/rudder"}},
      {"/controls/flight/flaps",{0,"/controls/flight/flaps"}},
      {"/controls/engines/engine/throttle",{0,"/controls/engines/engine/throttle"}},
      {"/controls/engines/current-engine/throttle",{0,"/controls/engines/current-engine/throttle"}},
      {"/controls/switches/master-avionics",{0,"/controls/switches/master-avionics"}},
      {"/controls/switches/starter",{0,"/controls/switches/starter"}},
      {"/engines/active-engine/auto-start",{0,"/engines/active-engine/auto-start"}},
      {"/controls/flight/speedbrake",{0,"/controls/flight/speedbrake"}},
      {"/sim/model/c172p/brake-parking",{0,"/sim/model/c172p/brake-parking"}},
      {"/controls/engines/engine/primer",{0,"/controls/engines/engine/primer"}},
      {"/controls/engines/current-engine/mixture",{0,"/controls/engines/current-engine/mixture"}},
      {"/controls/switches/master-bat",{0,"/controls/switches/master-bat"}},
      {"/controls/switches/master-alt",{0,"/controls/switches/master-alt"}},
      {"/engines/engine/rpm",{0,"/engines/engine/rpm"}}
  }; //this is the map to store data from ‫‪generic_small.xml‬‬
  vector<string> orderToSendToSimulator;//this is the string vector which will store all new set commands to send to the simulator. you send a single set and then delete it
  static Singleton* instance;
  Singleton(); // will be called only when calling getInstance
 public:
  static Singleton *getInstance();
  vector<string>& getVector();
  map<string,Var_Data>& getsymbolTableToServerMap();
  map<string,Var_Data>& getsymbolTableFromServerMap();
  map<string,Command*>& getCommandMap();
  map<string,float>& getgeneric_smallMap();
  Var_Data& getVar_Data(string& str);
  void InitializationofAllVarsFromXML();
  map<string,ValueAndNameObject>& getAllVarsFromXMLMMap();
  void set_generic_smallMap(string buf_to_value, int sim_index);
  vector<string>& getArrayOfOrdersToServer();
  ~Singleton(){
    map<string,Command*>:: iterator it=strToCommandMap.begin();
    for(;it!=strToCommandMap.end(); ++it) {
      delete it->second;
      it->second= nullptr;
    }
  }
};

#endif //FLIGHTSIMULATOR__SINGLETON_H_
