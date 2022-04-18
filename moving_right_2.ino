void send_Din(char,unsigned char);
void cs_high_low();
void enable();
void init();
void out_din(char);
void out_clk(char);
void out_cs(char);
unsigned char reverseBits(unsigned char);
unsigned char pixels (char);

#define shut_down    0x0C
#define brightness  0x0A
#define scan_limit  0x0B
#define decode_mode 0x09

char led_data1[8] = {0xFE,0x80,0x80,0xFE,0x80,0x80,0x80,0xFE};//'E' 
char led_data2[8] = {0xFE,0x80,0x80,0x80,0x80,0x80,0x80,0xFE};//'C'
char led_data3[8] = {0xFE,0x80,0x80,0xFE,0x80,0x80,0x80,0xFE};//'E' 
char led_data4[8] = {0x81,0xC1,0xA1,0x91,0x89,0x85,0x83,0x81};//'N'
char led_data5[8]  = {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};
char led_data6[8]  =  {0x18,0x24,0x42,0x42,0x7E,0x42,0x42,0x42};//'A'
char led_data7[8]  =  {0xFE,0x80,0x80,0x80,0x80,0x80,0x80,0xFE};//'C'
char led_data8[8]  =  {0x18,0x24,0x42,0x42,0x7E,0x42,0x42,0x42};//'A'
char led_data9[8]  =  {0xF8,0x84,0x84,0x84,0x84,0x84,0x84,0xF8};//'D'
char led_data10[8] =  {0xFE,0x80,0x80,0xFE,0x80,0x80,0x80,0xFE};//'E' 
char led_data11[8] =  {0x82,0xC6,0xAA,0x92,0x82,0x82,0x82,0x82};//'M' 
char led_data12[8] =  {0x82,0x44,0x28,0x10,0x10,0x10,0x10,0x10};//'Y' 
char led_data0[8]  = {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};

void setup() {
  Serial.begin(9600);
  init();
  out_cs(0x00);

  send_Din(scan_limit,0x07);
  send_Din(scan_limit,0x07);
  send_Din(scan_limit,0x07);
  send_Din(scan_limit,0x07);
  cs_high_low();

  send_Din(decode_mode,0x00);
  send_Din(decode_mode,0x00);
  send_Din(decode_mode,0x00);
  send_Din(decode_mode,0x00);
  cs_high_low();

  send_Din(brightness,0x01);
  send_Din(brightness,0x01);
  send_Din(brightness,0x01);
  send_Din(brightness,0x01);
  cs_high_low();

  send_Din(shut_down,0x01);
  send_Din(shut_down,0x01);
  send_Din(shut_down,0x01);
  send_Din(shut_down,0x01);
  cs_high_low();

  int val=0,n=0,x;
  while(1){

 for(n=0;n<16;n++){   
  for(int shift=0;shift<9;shift++){
    
    for(int k=0;k<3;k++){
      for(char i=1;i<9;i++){
        if(n<=0){
        send_Din(i,led_data0[i-1]<<shift  | reverseBits((reverseBits(led_data0[i-1])<<(8-shift))&val));
        }
        if(n<=1){
        send_Din(i,led_data0[i-1]<<shift | reverseBits((reverseBits(led_data0[i-1])<<(8-shift))&val));
        }
        if(n<=2){
        send_Din(i,led_data0[i-1]<<shift | reverseBits((reverseBits(led_data0[i-1])<<(8-shift))&val));
        }
        if(n<=3){
        send_Din(i,led_data0[i-1]<<shift | reverseBits((reverseBits(led_data1[i-1])<<(8-shift))&val));
        }
        if(n<=4 && n>0){
        send_Din(i,led_data1[i-1]<<shift  | reverseBits((reverseBits(led_data2[i-1])<<(8-shift))&val));
        }
        if(n<=5 && n>1){
        send_Din(i,led_data2[i-1]<<shift | reverseBits((reverseBits(led_data3[i-1])<<(8-shift))&val));
        }
        if(n<=6 && n>2){
        send_Din(i,led_data3[i-1]<<shift | reverseBits((reverseBits(led_data4[i-1])<<(8-shift))&val));
        }
        if(n<=7 && n>3){
        send_Din(i,led_data4[i-1]<<shift | reverseBits((reverseBits(led_data5[i-1])<<(8-shift))&val));
        }
        if(n<=8 && n>4){
        send_Din(i,led_data5[i-1]<<shift | reverseBits((reverseBits(led_data6[i-1])<<(8-shift))&val));
        }
        if(n<=9 && n>5){
        send_Din(i,led_data6[i-1]<<shift | reverseBits((reverseBits(led_data7[i-1])<<(8-shift))&val));
        }
        if(n<=10 && n>6){
        send_Din(i,led_data7[i-1]<<shift | reverseBits((reverseBits(led_data8[i-1])<<(8-shift))&val));
        }
        
        if(n<=11 && n>7){
        send_Din(i,led_data8[i-1]<<shift | reverseBits((reverseBits(led_data9[i-1])<<(8-shift))&val));
        }

         if(n<=12 && n>8){
        send_Din(i,led_data9[i-1]<<shift | reverseBits((reverseBits(led_data10[i-1])<<(8-shift))&val));
        }

        if(n<=13 && n>9){
        send_Din(i,led_data10[i-1]<<shift | reverseBits((reverseBits(led_data11[i-1])<<(8-shift))&val));
        }

        if(n<=14 && n>10){
        send_Din(i,led_data11[i-1]<<shift | reverseBits((reverseBits(led_data12[i-1])<<(8-shift))&val));
        }

         if(n<=15 && n>11){
        send_Din(i,led_data12[i-1]<<shift);
        }

        if(n>11){
            for(int l=0;l<(n-12);l++){
                send_Din(i,0x00);
            }
          }
        cs_high_low();
      }
    }
    val = val+pixels(7-shift);
    Serial.println(val,DEC);
   }
    val = 0;
  }
  }

}

void send_Din(char addr,unsigned char data){
    for(char i=7;i>=0;i--){
      out_din((addr>>i)&0x01);
      enable();
    }

    for(char i=7;i>=0;i--){
      out_din((data>>i)&0x01);
      enable();
    }  
}


unsigned char reverseBits(unsigned char n) {
   long s=0,i=0;   
    while(i<8){
        s = s*2+n%2;
        n = n/2;
        i++;
    }
    return s;
}

unsigned char pixels(char n){
    char p=1;
    if(n==0){
        return 1;
    }else{
        for(int i=1;i<=n;i++){
            p = 2*p;
        }
        return p;
    }
}

void cs_high_low(){
  out_cs(0x01);
  delay1();
  out_cs(0x00);
}

void enable(){
  out_clk(0x01);
  delay1();
  out_clk(0x00);
  delay1();
}

void init(){
   char *ddr_din = (char*)0x30;
   *ddr_din = 0x01;

   char *ddr_clk = (char*)0x107;
   *ddr_clk = 0x01;

   char *ddr_cs = (char*)0x10A;
   *ddr_cs = 0x01;
}

void out_din(char data){
  char *out = (char*)0x31;
  *out = data;
}

void out_clk(char data){
  char *out = (char*)0x108;
  *out = data;
}

void out_cs(char data){
  char *out = (char*)0x10B;
  *out = data;
}

void delay1(){
  volatile long i;
  for(i=0;i<20;i++);
}
