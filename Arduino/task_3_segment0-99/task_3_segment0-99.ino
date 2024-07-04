void setup() {
  
pinMode(13, OUTPUT);
pinMode(12, OUTPUT);
pinMode(11, OUTPUT);
pinMode(10, OUTPUT);
pinMode(9, OUTPUT);
pinMode(8, OUTPUT);
pinMode(7, OUTPUT);
pinMode(6, OUTPUT);
}

void loop() {

int a, b, c, d, e, f, g, h;
int x=0;
int y=0;

for(a=0;a<2&x<=9;a++)
{
  for(b=0;b<2&x<=9;b++)
  {
    for(c=0;c<2&x<=9;c++)
    {
      for(d=0;d<2&x<=9;d++)
      {
        for(e=0;e<2&y<=9;e++)
        {
          for(f=0;f<2&y<=9;f++)
          {
            for(g=0;g<2&y<=9;g++)
            {
              for(h=0;h<2&y<=9;h++)
              {
                digitalWrite(13, a);
                digitalWrite(12, b);
                digitalWrite(11, c);
                digitalWrite(10, d);
                digitalWrite(9, e);
                digitalWrite(8, f);
                digitalWrite(7, g);
                digitalWrite(6, h);
                delay(250);
                

                y=y+1;
              }
            }
          }
        }
      x=x+1;
      y=0;
      }
    }
  }
}

}