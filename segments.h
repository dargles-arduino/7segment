/**
 * Defines the segments which need to be on for each display numeral.
 * The segments are defined in order for each numeral, i.e.:
 * first line defines segments a,b,c,d,e,f,g for digit '0',
 * second line defines segments a,b,c,d,e,f,g for digit '1', etc.
 */

/* These defines are to allow for reverse logic (common anode).
   Switch them around if using common cathode */
#define ON          0
#define OFF         1

int seg_display[][7] = {
  {ON,ON,ON,ON,ON,ON,OFF},
  {OFF,ON,ON,OFF,OFF,OFF,OFF},
  {ON,ON,OFF,ON,ON,OFF,ON},
  {ON,ON,ON,ON,OFF,OFF,ON},
  {OFF,ON,ON,OFF,OFF,ON,ON},
  {ON,OFF,ON,ON,OFF,ON,ON},
  {ON,OFF,ON,ON,ON,ON,ON},
  {ON,ON,ON,OFF,OFF,OFF,OFF},
  {ON,ON,ON,ON,ON,ON,ON},
  {ON,ON,ON,OFF,OFF,ON,ON},
  {OFF,OFF,OFF,OFF,OFF,OFF,OFF}
};
