#include <iostream>
#include "flrigClient.h"

FlrigClient::FlrigClient(const std::string hostStr, const std::string portStr)
  : host{hostStr}, port{portStr} { setAllAttr(); }

void FlrigClient::setAllAttr() {
  std::string serverUrl = "http://" + host + ":" + port;
  xmlrpc_c::clientSimple myClient;

  {
    xmlrpc_c::value result;
    myClient.call(serverUrl, "rig.get_AB", "", &result);
    vfoCurrentInUse = xmlrpc_c::value_string(result);
  }
  {
    xmlrpc_c::value result;
    myClient.call(serverUrl, "rig.get_info", "", &result);
    rigInfo = xmlrpc_c::value_string(result);
  }
  {
    xmlrpc_c::value result;
    myClient.call(serverUrl, "rig.get_mode", "", &result);
    modeOfVfoCurrentInUse = xmlrpc_c::value_string(result);
  }
  {
    xmlrpc_c::value result;
    myClient.call(serverUrl, "rig.get_modeA", "", &result);
    modeOfVfoA = xmlrpc_c::value_string(result);
  }
  {
    xmlrpc_c::value result;
    myClient.call(serverUrl, "rig.get_modeB", "", &result);
    modeOfVfoB = xmlrpc_c::value_string(result);
  }
  {
    xmlrpc_c::value result;
    myClient.call(serverUrl, "rig.get_ptt", "", &result);
    pttState = xmlrpc_c::value_int(result);
  }
  {
    xmlrpc_c::value result;
    myClient.call(serverUrl, "rig.get_split", "", &result);
    splitState = xmlrpc_c::value_int(result);
  }
  {
    xmlrpc_c::value result;
    myClient.call(serverUrl, "rig.get_vfo", "", &result);
    freqCurrentVfo = xmlrpc_c::value_string(result);
  }
  {
    xmlrpc_c::value result;
    myClient.call(serverUrl, "rig.get_vfoA", "", &result);
    freqVfoA = xmlrpc_c::value_string(result);
  }
  {
    xmlrpc_c::value result;
    myClient.call(serverUrl, "rig.get_vfoB", "", &result);
    freqVfoB = xmlrpc_c::value_string(result);
  }
}

void FlrigClient::printAttr() {
  std::cout << "aktueller VFO: " << vfoCurrentInUse << std::endl;
  std::cout << "Rig Info Text: " << rigInfo << std::endl;
  std::cout << "Betriebsart aktueller VFO: " << modeOfVfoCurrentInUse << std::endl;
  std::cout << "Betriebsart VFO A: " << modeOfVfoA << std::endl;
  std::cout << "Betriebsart VFO B: " << modeOfVfoB << std::endl;
  std::cout << "Status PTT: ";
  if(pttState == 0) std::cout << "OFF";
  else std::cout << "ON";
  std::cout << std::endl;
  std::cout << "Status Splitbetrieb: ";
  if(splitState == 0) std::cout << "OFF";
  else std::cout << "ON";
  std::cout << std::endl;
  std::cout << "Frequenz aktueller VFO: " << freqCurrentVfo << std::endl;
  std::cout << "Frequenz VFO A: " << freqVfoA << std::endl;
  std::cout << "Frequenz VFO B: " << freqVfoB << std::endl;
  std::cout << std::endl;
}
