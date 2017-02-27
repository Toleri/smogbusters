#define CONFIG_START  100
#define CONFIG_VERSION  "qw1"

struct {
  char ver[4];
  char deviceID[50];
} ctx = {CONFIG_VERSION, "newID"};


void readContext() {
  // To make sure there are settings, and they are YOURS!
  // If nothing is found it will use the default settings.
  if (EEPROM.read(CONFIG_START + 0) == CONFIG_VERSION[0] &&
      EEPROM.read(CONFIG_START + 1) == CONFIG_VERSION[1] &&
      EEPROM.read(CONFIG_START + 2) == CONFIG_VERSION[2]) {
    for (unsigned int t = 0; t < sizeof(ctx); t++)
      *((char*)&ctx + t) = EEPROM.read(CONFIG_START + t);
  }
}

void saveContext() {
  for (unsigned int t = 0; t < sizeof(ctx); t++) {
    EEPROM.write(CONFIG_START + t, *((char*)&ctx + t));
  }
  EEPROM.commit();
}
