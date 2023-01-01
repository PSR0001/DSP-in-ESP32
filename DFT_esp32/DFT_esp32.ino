float a[8]= {0,0,10,10,0,0,10,10};

void setup(){
  Serial.begin(250000);
}
void loop(){
  dft(a,8,10,3,20,1,4,0);

  delay(200);
}






float dft(float a[],int arraysize,float interval,float f0,float fn,float stepsize,int detail,int window_status)
{
  float sum,sumi,sumr,sumti,sumtr,sumt=0;
  int j,k=0;
if(window_status==1)  //flat-top window
{
  for(int i=0;i<1+arraysize;i++)
  {
    float b=3.1415*i/(arraysize-1);
   a[i] = a[i]*( 1 - (1.93*cos(2*b)) + (1.29*cos(4*b)) - (0.388*cos(6*b)) + (0.028*cos(8*b)));
// Serial.println(a[i]);
  }
}

if(window_status==2) //hann window
{ 
  for(int i=0;i<1+arraysize;i++)
  {
   float b=2*3.1415*i/(arraysize-1);
   a[i] = a[i]*0.5*(1-cos(b));
  //Serial.println(a[i]);
  }
}

if(window_status==3)//hamming window
{ 
  for(int i=0;i<1+arraysize;i++)
  {
   float b=2*3.1415*i/(arraysize-1);
   a[i] = a[i]*(0.54-0.46*cos(b));
  //Serial.println(a[i]);
  }
}
  
for(float f=f0; f<=fn; f=f+stepsize)
     {
        
              for(int i=0;i<1+(arraysize*detail);i++)
              {
                j=i-k;
                if(j>=arraysize){k=k+arraysize;}
                sumti=a[j]*(sin(6.28*f*i*interval*0.001));
                sumtr=a[j]*(cos(6.28*f*i*interval*0.001));              
                sumi=sumi+sumti;
                sumr=sumr+sumtr; 
              }
     sum=sqrt(sumi*sumi+sumr*sumr)/(arraysize*detail);
     Serial.print(f);
     Serial.print("\t");
     Serial.println(sum);
     sumi=0;sumr=0;
     j=0;   k=0; 
     }
}     
