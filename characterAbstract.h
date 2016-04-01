/**
 * Base of any creature in the game.
 *
 * @author ElDanteDelAnte
 *
 * Versions:
 *
 * 3/7/16
 * Replaces character.h
 * Skills are now their own class,
 * replaces all skill-related functions.
 *
 * 3/29/16
 * Curious if racial traits can be stored as
 * enum struct racialTraits : race
 * (Likely depends on number of hierarchy levels.)
 *
 * 3/31/16
 * Races are structs, templates stored in global array.
 * Abstract_Character is constructed with a raceIndex.
 * init() is common between constructors (if multiple).
 *
 */

/* WARNING: DO NOT USE #INCLUDE GUARDS
 * DO NOT DIRECTLY #INCLUDE IN ANY FILE
 * OTHER THAN DECLARATIONS.H
 */

#define NUMSKILLS 20
#define NUMRACES 5
#define NUMDAMTYPES 10

using namespace std;


typedef enum
  {
  ARCHERY,
  FIREARM,
  SMELEE,
  LMELEE,
  UNARMED,
  LARMOR,
  HARMOR,
  BLOCK,
  STEALTH,
  TECH,
  MECH,
  SPEECH,
  MEDICINE,
  ATHLETICS,
  PERCEPTION,
  MINING,
  FARMING,
  PSI,
  HOLY,
  DARK
  } skillIndex;




enum raceIndex
  {
  HUMAN,
  ZORTHOG,
  SHOAN,
  SAELI,
  RAKK
  };

typedef struct
  {
    raceIndex raceSpec;
    string raceName;

    int lvBonus[NUMSKILLS];
    double expRate[NUMSKILLS];
    double defTypeRate[NUMDAMTYPES];
    double statfact_hp;
    double statfact_stam;
    double statfact_focus;

    Abstract_Weapon natWeap;
  } Race;

Race raceTempl[NUMRACES];

class Abstract_Character
  {
  private:
    //initializes skills, possibly used while loading
    //void init();

    /* Character Skills */
  protected:
    class Skill
      {
      private:
        int lv;
        int bonusRacial;
        int exp;
        double rateRacial;

      public:
        int getLv();
        int getExp();
        void gainExp(int exp);
        void setLv(int lv);
        void setExp(int exp);

        //constructor, assigns racial bonuses
        Skill(int racialBonus, double racialRate, int startExp)
          {
            exp = 0;
            lv = 0;
            rateRacial = racialRate;
            bonusRacial = racialBonus;
            this->gainExp(startExp);
          }
      };

    Skill skills[NUMSKILLS];


    Race race;


  public:
    //default race
    //Abstract_Character();

    //select race
    Abstract_Character(raceIndex raceSpecifier);
  };
