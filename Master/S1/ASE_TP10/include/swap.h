#ifndef SWAP

#define SWAP

struct pm_s {
  /*
  Champ permettant de déterminer si la structure a été mappé ou non
  */
  unsigned mappee : 1;
  /*
  Champ permettant d'obtenir la page virtuelle contenue dans la structure
  */
  unsigned vpage : 12;
};

struct vm_s {
  /*
  Champ permettant de déterminer si la structure a été mappé ou non
  */
  unsigned mappee : 1;
  /*
  Champ permettant d'obtenir la page physique contenue dans la structure
  */
  unsigned ppage : 8;
};

#endif
