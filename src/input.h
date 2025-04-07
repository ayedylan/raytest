#include <raylib.h>

const char * InputDirection() {
  if (IsKeyDown(KEY_W)) {
    return "u";
  };
  if (IsKeyDown(KEY_D)) {
    return "f";
  };
  if (IsKeyDown(KEY_S)) {
    return "d";
  }
};


/* There will be a dynamic array that contains each input for each player, and motion inputs will be deduced by the array */
   
