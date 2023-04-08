struct na_lcg {
  int state;
};

struct na_lcg na_lcg_create(int);

double na_lcg_next(struct na_lcg *);
