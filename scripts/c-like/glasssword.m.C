// Real-C
#include "ENGINE.hpp"

TRIGGER( ishitting )(obj victim, int damamt)
{
  sfx(getLocation(this), 0x3F, 0x3F);
  debugMessage("HIT");
  doDamageWithWeapon(containedBy(this), victim, this, 0x2710);
  deleteObject(this);
  return(0x01);
}

TRIGGER( equip )(obj equippedon)
{
  if(isPlayer(equippedon))
  {
    list args = list( 0x0A );
    multimessage(equippedon, "usedme", args);
  }
  return(0x01);
}

TRIGGER( creation )()
{
  setHue(this, 0x53);
  int Q527 = applyWeaponTemplate(this, 0x3D);
  setObjVar(this, "lookAtText", "a glass sword");
  return(0x01);
}