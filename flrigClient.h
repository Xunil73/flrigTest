#ifndef FLRIGCLIENT_H
#define FLRIGCLIENT_H

/*
dies ist eine Klasse um den flrig-Server anzusprechen und alle aktuellen Werte des Transceivers
in privaten Attributen zu speichern

definierte Kommandos von W1HKJ:
main.set_frequency        d:d  set current VFO in Hz
main.get_version          s:n  returns version std::string
rig.get_AB                s:n  returns vfo in use A or B
rig.get_bw                A:n  return BW of current VFO
rig.get_bws               A:n  return table of BW values
rig.get_bwA               A:n  return BW of vfo A
rig.get_bwB               A:n  return BW of vfo B
rig.get_pbt               A:n  return passband tuning
rig.get_pbt_inner         i:i  return passband inner
rig.get_pbt_outer         i:i  return passband outer
rig.get_info              s:n  return an info std::string
rig.get_mode              s:n  return MODE of current VFO
rig.get_modeA             s:n  return MODE of current VFO A
rig.get_modeB             s:n  return MODE of current VFO B
rig.get_modes             A:n  return table of MODE values
rig.get_sideband          s:n  return sideband (U/L)
rig.get_notch             i:n  return notch value
rig.get_ptt               i:n  return PTT state
rig.get_power             i:n  return power level control value
rig.get_pwrmeter          s:n  return PWR out
rig.get_pwrmeter_scale    s:n  return scale for power meter
rig.get_pwrmax            s:n  return maximum power available
rig.get_swrmeter          s:n  return SWR meter reading
rig.get_SWR               s:n  return SWR value
rig.get_smeter            s:n  return Smeter
rig.get_DBM               s:n  return Smeter in dBm
rig.get_Sunits            s:n  return Smeter in S units
rig.get_split             i:n  return split state
rig.get_update            s:n  return update to info
rig.get_vfo               s:n  return current VFO in Hz
rig.get_vfoA              s:n  return vfo A in Hz
rig.get_vfoB              s:n  return vfo B in Hz
rig.get_xcvr              s:n  returns name of transceiver
rig.get_volume            i:n  returns volume control value
rig.get_rfgain            i:n  returns rf gain control value
rig.get_micgain           i:n  returns mic gain control value
rig.set_AB                n:s  set VFO A/B
rig.set_bw                i:i  set BW iaw BW table
rig.set_bandwidth         i:i  set bandwidth to nearest requested value
rig.set_BW                i:i  set L/U pair
rig.set_pbt               i:A  set pbt inner/outer
rig.set_pbt_inner         i:i  set pbt inner
rig.set_pbt_outer         i:i  set pbt outer
rig.set_frequency         d:d  set current VFO in Hz
rig.set_mode              i:s  set MODE iaw MODE table
rig.set_modeA             i:s  set MODE A iaw MODE table
rig.set_modeB             i:s  set MODE B iaw MODE table
rig.set_notch             n:i  set NOTCH value in Hz
rig.set_power             n:i  set power control level, watts
rig.set_ptt               n:i  set PTT 1/0 (on/off)
rig.set_vfo               d:d  set current VFO in Hz
rig.set_vfoA              d:d  set vfo A in Hz
rig.set_vfoB              d:d  set vfo B in Hz
rig.set_split             n:i  set split 1/0 (on/off)
rig.set_volume            n:i  set volume control
rig.set_rfgain            n:i  set rf gain control
rig.set_micgain           n:i  set mic gain control
rig.set_ptt_fast          n:i  deprecated; use set_ptt
rig.set_vfoA_fast         d:d  deprecated; use set_vfoA
rig.set_vfoB_fast         d:d  deprecated; use set_vfoB
rig.set_verify_AB         n:s  set & verify VFO A/B
rig.set_verify_bw         i:i  set & verify BW iaw BW table
rig.set_verify_bandwidth  i:i  set & verify bandwidth to nearest requested value
rig.set_verify_BW         i:i  set & verify L/U pair
rig.set_verify_frequency  d:d  set & verify current VFO in Hz
rig.set_verify_mode       i:s  set & verify MODE iaw MODE table
rig.set_verify_modeA      i:s  set & verify MODE A iaw MODE table
rig.set_verify_modeB      i:s  set & verify MODE B iaw MODE table
rig.set_verify_notch      n:i  set & verify NOTCH value in Hz
rig.set_verify_power      n:i  set & verify power control level, watts
rig.set_verify_ptt        n:i  set & verify PTT 1/0 (on/off)
rig.set_verify_vfoA       d:d  set & verify vfo A in Hz
rig.set_verify_vfoB       d:d  set & verify vfo B in Hz
rig.set_verify_split      n:i  set & verify split 1/0 (on/off)
rig.set_verify_volume     n:i  set & verify volume control
rig.set_verify_rfgain     n:i  set & verify rf gain control
rig.set_verify_micgain    n:i  set & verify mic gain control
rig.swap                  n:n  execute vfo swap
rig.tune                  n:n  enable transceiver tune function
rig.cat_string            s:s  execute CAT std::string
rig.cat_priority          s:s  priority CAT std::string
rig.shutdown              i:n  shutdown xcvr & flrig
rig.cwio_set_wpm          n:i  set cwio WPM
rig.cwio_text             i:s  send text via cwio interface
rig.cwio_send             n:i  cwio transmit 1/0 (on/off)
rig.fskio_text            i:s  send text via fskio interface
rig.mod_vfoA              d:d  modify vfo A +/- NNN Hz
rig.mod_vfoB              d:d  modify vfo B +/- NNN Hz
rig.mod_vol               n:i  modify volume control +/- NNN %
rig.mod_pwr               n:i  modify power control level +/- NNN watts
rig.mod_rfg               n:i  modify rf gain by +/- NNN units
rig.mod_cwio_wpm          n:i  modify cwio WPM by +/- NNN wpm
rig.mod_bw                i:i  modify bandwidth +- to nearest new value
rig.vfoA2B                n:n  set vfo B to vfo A freq/mode
rig.freqA2B               n:n  set freq B to freq A
rig.modeA2B               n:n  set mode B to mode A
rig.cmd                   n:i  execute command button 1..24; 25..48(shift)

*/


#include <cstdlib>
#include <string>
#include <iostream>

#include <xmlrpc-c/girerr.hpp>
#include <xmlrpc-c/base.hpp>
#include <xmlrpc-c/client_simple.hpp>

class FlrigClient {

  public:
    FlrigClient(const std::string, const std::string);
    
    void printAttr();    

    void setCurrentVfo(const double);

  private:

    void setAllAttr(); /* priv Methode zum fuellen aller 
    Werte bei der Instanzierung eines FlrigClient Objekts */
    
    const std::string host;
    const std::string port;

    /* hier speichern wir alle aktuellen Einstellungen des Transceivers ab
       um sie spaeter kreativ zu verwenden */
    std::string vfoCurrentInUse;
    std::string rigInfo;
    std::string modeOfVfoCurrentInUse;
    std::string modeOfVfoA;
    std::string modeOfVfoB;
    int pttState;
    int splitState;
    std::string freqCurrentVfo;
    std::string freqVfoA;
    std::string freqVfoB;

};
#endif // FLRIGCLIENT_H
