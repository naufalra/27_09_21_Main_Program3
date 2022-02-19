void IK(uint8_t kaki, float x, float y, float z, int w)
{
  uint8_t i;
  float r;
  float teta;
  float tan_teta1, teta1;
  float cos_teta2, teta2;
  float tan_beta, tan_alfa;
  float temp[7];

  //Serial.print("IK");
  for (i = 0; i < 5; i++) temp[i] = 0;
  temp[0] = (float)setpoint_kaki[kaki][0] + x;
  temp[1] = (float)setpoint_kaki[kaki][1] + y;
  temp[2] = (float)setpoint_kaki[kaki][2] + z;
  if (temp[0] == 0) temp[0] = 0.00001;
  r = sqrt(temp[0] * temp[0] + temp[1] * temp[1]);
  if (temp[0] < 0)r = -r;
  temp[3] = r * r + temp[2] * temp[2] - l1 * l1 - l2 * l2;
  temp[4] = 2 * l1 * l2;
  while (temp[3] > temp[4]);
  teta = temp[1] / temp[0];
  teta = atan(teta) * deg_per_rad;
  r = r - 20;

  cos_teta2 = r * r + temp[2] * temp[2] - l1 * l1 - l2 * l2;
  cos_teta2 = cos_teta2 / (2.0f * l1 * l2);
  teta2 = acos(cos_teta2) * deg_per_rad;

  tan_beta = l2 * sin(teta2 * rad_per_deg);
  tan_alfa = temp[2] / r;
  tan_beta = tan_beta / (l1 + l2 * cos(teta2 * rad_per_deg));
  tan_teta1 = tan_beta + tan_alfa;
  temp[6] = 1 - tan_beta * tan_alfa;
  tan_teta1 = tan_teta1 / temp[6];
  teta1 = atan(tan_teta1) * deg_per_rad;

  if (w == 0) //forward/backward
  {

    if (kaki == 0 ) // kanan depan
    {
      pulsa_kaki[kaki][0] = -floor(teta);        //coxa
      pulsa_kaki[kaki][1] = floor(teta1);        //femur
      pulsa_kaki[kaki][2] = 155 - floor(teta2);  //tibia
    }


    else if (kaki == 2) //kiri belakang
    {
      pulsa_kaki[kaki][0] = floor(teta);
      pulsa_kaki[kaki][1] = floor(teta1);
      pulsa_kaki[kaki][2] = 155 - floor(teta2);
    }

    else if (kaki == 1) //kiri depan
    {
      pulsa_kaki[kaki][0] = floor(teta);
      pulsa_kaki[kaki][1] = floor(teta1);
      pulsa_kaki[kaki][2] = 155 - floor(teta2);
    }

    else if (kaki == 3) // kanan belakang
    {
      pulsa_kaki[kaki][0] = -floor(teta);
      pulsa_kaki[kaki][1] = floor(teta1);
      pulsa_kaki[kaki][2] = 155 - floor(teta2);
    }
  }
  else if (w == 1) //turning
  {
    if (kaki == 0 ) // kanan depan
    {
      pulsa_kaki[kaki][0] = floor(teta);        //coxa
      pulsa_kaki[kaki][1] = floor(teta1);        //femur
      pulsa_kaki[kaki][2] = 150 - floor(teta2);  //tibia
    }


    else if (kaki == 2) //kiri belakang
    {
      pulsa_kaki[kaki][0] = floor(teta);
      pulsa_kaki[kaki][1] = floor(teta1);
      pulsa_kaki[kaki][2] = 150 - floor(teta2);
    }

    else if (kaki == 1) //kiri depan
    {
      pulsa_kaki[kaki][0] = floor(teta);
      pulsa_kaki[kaki][1] = floor(teta1);
      pulsa_kaki[kaki][2] = 150 - floor(teta2);
    }

    else if (kaki == 3) // kanan belakang
    {
      pulsa_kaki[kaki][0] = -floor(teta);
      pulsa_kaki[kaki][1] = floor(teta1);
      pulsa_kaki[kaki][2] = 150 - floor(teta2);
    }
  }
}
