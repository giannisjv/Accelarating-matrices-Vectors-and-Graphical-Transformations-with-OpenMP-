//randomness algorithm
#define randomness 5
#define randMinus 1

int randomGen(){

  int num = 0;
  num = rand() % (randomness - randMinus) + randMinus;
    return num;
}
