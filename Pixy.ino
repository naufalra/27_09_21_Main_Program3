int cont = 0;
int signature, x, y, width, height;
float cx, cy, area;


float pixyCheck() {
  static int i = 0;
  int j;
  uint16_t blocks;
  char buf[32];
  // grab blocks!
  blocks = pixy.ccc.getBlocks();
  //  Serial.print(blocks);

  // If there are detect blocks, print them!
  if (blocks)
  {
    signature = pixy.ccc.blocks[i].m_signature;
    height = pixy.ccc.blocks[i].m_height;
    width = pixy.ccc.blocks[i].m_width;
    x = pixy.ccc.blocks[i].m_x ;
    y = pixy.ccc.blocks[i].m_y ;
    cx = (x + (width / 2));
    cy = (y + (height / 2));
    cx = mapfloat(cx, 0, 320, -1, 1);
    cy = mapfloat(cy, 0, 200, 1, -1);
    area = width * height;

    //<Debug>
    //    Serial.print("sig: ");
    //    Serial.print(signature);
    //    Serial.print(" x:");
    //    Serial.print(x);
    //    Serial.print(" y:");
    //    Serial.print(y);
    //    Serial.print(" width: ");
    //    Serial.print(width);
    //    Serial.print(" height: ");
    //    Serial.print(height);
    //    Serial.print(" cx: ");
    //    Serial.print(cx);
    //    Serial.print(" cy: ");
    //    Serial.println(cy);
    //</Debug>

  }
  else {
    cont += 1;
    if (cont == 100) {
      cont = 0;
      cx = 0;
    }
  }
  return cx;
}

float mapfloat(long x, long in_min, long in_max, long out_min, long out_max)
{
  return (float)(x - in_min) * (out_max - out_min) / (float)(in_max - in_min) + out_min;
}
