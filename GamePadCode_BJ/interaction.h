
int interaction[numLevels][tileW] {

  {


  },

  {




  },

  {




  },

  {



  },

  {



  },

  {




  }
};

int neighbors[192][8];

boolean canMove; // allows the proposed space the player wants to move to be valid.
int curTile;
int curTileX;
int curTileY;

void initNeighbors() {
  for (int i = 0; i < tileW * tileH; i++) {
    // General Rule of neighbors

    
    int N = i - tileW; int NE = (i - tileW) + 1;  int E = i + 1;  int SE = (i + tileW) + 1;
    int S = i + tileW; int SW = (i + tileW) - 1;  int W = i - 1;  int NW = (i - tileW) - 1;



    neighbors[i][0] = N;  neighbors[i][1] = NE;  neighbors[i][2] = E;  neighbors[i][3] = SE;
    neighbors[i][4] = S;  neighbors[i][5] = SW;  neighbors[i][6] = W;  neighbors[i][7] = NW;
  }
}

boolean checkMove(int level, int curX, int curY, int curW, int curH) {

  curTileX = curX / tileSize;
  curTileY = curY / tileSize;

  curTile = curTileX + (curTileY * tileW);

  canMove = true;

  for (int i = 0; i < 8; i++) {
    int whichTile = neighbors[curTile][i];


    int neighborX = (whichTile % tileW) * tileSize;      // Get X Value of Neighbor
    int neighborY = (whichTile / tileW) * tileSize;      // Get Y Value of Neighbor





    boolean isOut = false; if (interaction[level][whichTile] == 0xFF) {
      isOut = true;
    }
    boolean xMin = false; if (curX < neighborX + tileSize) {
      xMin = true;
    }
    boolean xMax = false; if (curW + curX > neighborX) {
      xMax = true;
    }
    boolean yMin = false; if (curY < neighborY + tileSize) {
      yMin = true;
    }
    boolean yMax = false; if (curY + curH > neighborY) {
      yMax = true;
    }

    if (isOut == true && xMin == true && xMax == true && yMin == true && yMax == true) {
      canMove = false;
    }

  }


  return canMove;
}
