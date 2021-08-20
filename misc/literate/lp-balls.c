/*2:*/
#line 31 "./lp-balls.w"

#include <float.h> 
#include <math.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 



double p;
double p_inv;
int d;
int max_points;
int num_points;
double**points;

/*12:*/
#line 236 "./lp-balls.w"

void plot_single_point(FILE*file,double red,double green,double blue,double x,double y){
fprintf(file,"%f %f %f setrgbcolor %f %f dot\n",red,green,blue,x,y);
}
void to_postscript(const char*filename,int radius){
if(d!=2){
printf("I cannot output PostScript unless d equals 2!\n");
return;
}
FILE*file= fopen(filename,"w");
/*13:*/
#line 255 "./lp-balls.w"

char*preamble= "%!PS\n\
/dot { 1.5 0 360 arc closepath fill } def\n\
/square { /r exch def /y exch def /x exch def\n\
newpath x r sub y r sub moveto 0 r 2 mul rlineto\n\
r 2 mul 0 rlineto 0 r 2 mul neg rlineto\n\
r 2 mul neg 0 rlineto closepath fill} def\n\
0.5 setlinewidth\n";
fprintf(file,"%s",preamble);
fprintf(file,"%d %d translate\n",radius,radius);
fprintf(file,"newpath 0 %d moveto 0 %d lineto ",-radius,radius);
fprintf(file,"%d 0 moveto %d 0 lineto stroke\n",-radius,radius);

/*:13*/
#line 246 "./lp-balls.w"
;
/*14:*/
#line 272 "./lp-balls.w"

double colour1[]= {1.0,0.0,0.0};
double colour2[]= {0.0,0.0,1.0};
for(int i= 0;i<num_points;++i){
double t= ((double)i)/((double)(num_points-1));
double r= (1.0-t)*colour1[0]+t*colour2[0];
double g= (1.0-t)*colour1[1]+t*colour2[1];
double b= (1.0-t)*colour1[2]+t*colour2[2];
plot_single_point(file,r,g,b,points[i][1]*radius,points[i][2]*radius);
}

/*:14*/
#line 247 "./lp-balls.w"
;
fprintf(file,"showpage\n");
fclose(file);
}

/*:12*/
#line 47 "./lp-balls.w"
;
/*3:*/
#line 68 "./lp-balls.w"

void add_point(double*point){
if(num_points>=max_points){
printf("I failed to add point because array is full.\n");
return;
}
for(int i= 1;i<=d;++i)points[num_points][i]= point[i];
++num_points;
}
void clear_points(){
num_points= 0;
}
void list_points(){
for(int i= 0;i<num_points;++i){
printf("(");
for(int j= 1;j<=d;++j){
printf("%.2f",points[i][j]);
if(j!=d)printf(", ");
}
printf(")\n");
}
}

/*:3*/
#line 48 "./lp-balls.w"
;
/*4:*/
#line 97 "./lp-balls.w"

/*6:*/
#line 116 "./lp-balls.w"

double uniform01(){
return((double)rand())/RAND_MAX;
}
double exponential1(){
int Z= 0;
double Y;
int k;
do{
Y= uniform01();
k= 1;
double W= Y;
int stop= 0;
do{
double U= uniform01();
if(U> W){
stop= 1;
}else{
W= U;
++k;
}
}while(!stop);
++Z;
}while(k%2==0);
return((double)(Z-1))+Y;
}

/*:6*/
#line 98 "./lp-balls.w"
;
/*11:*/
#line 224 "./lp-balls.w"

double normal01(){
double U1= uniform01();
double U2= uniform01();
double scale= sqrt(-2.0*log(U1));
return scale*cos(2*M_PI*U2);
}

/*:11*/
#line 99 "./lp-balls.w"
;
/*7:*/
#line 149 "./lp-balls.w"

double gamma_dist(double a){
double b= a-log(4);
double lambda= sqrt(2*a-1);
double c= a+lambda;
int accept= 0;
double U,V,Y,X,Z,R;
double S= 4.5*Z-(1+log(4.5));
do{
U= uniform01();
V= uniform01();
Y= (1.0/lambda)*log(V/(1-V));
X= a*exp(Y);
Z= U*V*V;
R= b+c*Y-X;
accept= (R>=S);
if(!accept)accept= (R>=log(Z));
}while(!accept);
return X;
}

/*:7*/
#line 100 "./lp-balls.w"
;
/*8:*/
#line 183 "./lp-balls.w"

void random_point(double*point){
double*X= malloc((d+1)*sizeof(double));
for(int i= 1;i<=d;++i)X[i]= 0.0;
if(p<0){
/*9:*/
#line 197 "./lp-balls.w"

for(int i= 1;i<=d;++i)point[i]= 2*uniform01()-1;

/*:9*/
#line 188 "./lp-balls.w"
;
}else{
/*10:*/
#line 202 "./lp-balls.w"

for(int i= 1;i<=d;++i){
double V= 2*uniform01()-1;
X[i]= V*pow(gamma_dist(1+p_inv),p_inv);
}
double Y= exponential1();
double pow_sum= Y;
for(int i= 1;i<=d;++i)pow_sum+= pow(fabs(X[i]),p);
double scale_factor= 1.0/(pow(pow_sum,p_inv));
for(int i= 1;i<=d;++i)point[i]= scale_factor*X[i];

/*:10*/
#line 190 "./lp-balls.w"
;
}
free(X);
}

/*:8*/
#line 101 "./lp-balls.w"
;

/*:4*/
#line 49 "./lp-balls.w"
;
/*15:*/
#line 290 "./lp-balls.w"

/*16:*/
#line 300 "./lp-balls.w"

double p_dist(double*x,double*y){
if(p<0){
double max= DBL_MIN;
for(int i= 1;i<=d;++i){
double diff= fabs(x[i]-y[i]);
if(diff> max)max= diff;
}
return max;
}else{
double sum= 0;
for(int i= 1;i<=d;++i)sum+= pow(fabs(x[i]-y[i]),p);
return pow(sum,1.0/p);
}
}

/*:16*/
#line 291 "./lp-balls.w"
;
/*17:*/
#line 324 "./lp-balls.w"

int consensus(int max_t,double(*dist)(double*,double*)){
clear_points();
double*cand1= malloc((d+1)*sizeof(double));
double*cand2= malloc((d+1)*sizeof(double));
random_point(cand1);
add_point(cand1);
for(int t= 0;t<max_t-1;++t){
random_point(cand1);
random_point(cand2);
int voted1= 0;
int voted2= 0;
for(int i= 0;i<num_points;++i){
double dist1= dist(points[i],cand1);
double dist2= dist(points[i],cand2);
if(dist1> dist2){
voted1= 1;
}else{
voted2= 1;
}
if(voted1&&voted2)break;
}
if(voted1&&!voted2)add_point(cand1);
if(voted2&&!voted1)add_point(cand2);
}
free(cand1);
free(cand2);
return num_points;
}

/*:17*/
#line 292 "./lp-balls.w"
;

/*:15*/
#line 50 "./lp-balls.w"
;
/*19:*/
#line 373 "./lp-balls.w"

double inner_product(double*x,double*y){
if(p!=2){
printf("I can only take inner products when p = 2!\n");
return 0.0;
}
double sum= 0.0;
for(int i= 1;i<=d;++i)sum+= x[i]*y[i];
return sum;
}
double abs_inner_product(double*x,double*y){
return fabs(inner_product(x,y));
}
double one_minus_inner_product(double*x,double*y){
return 1.0-inner_product(x,y);
}

/*:19*/
#line 51 "./lp-balls.w"
;
/*20:*/
#line 395 "./lp-balls.w"

/*21:*/
#line 402 "./lp-balls.w"

void draw_square(FILE*file,double red,double green,double blue,double x,double y,double r){
fprintf(file,"%f %f %f setrgbcolor %f %f %f square\n",red,green,blue,x,y,r);
}

/*:21*/
#line 396 "./lp-balls.w"
;
/*22:*/
#line 414 "./lp-balls.w"

void draw_locus(FILE*file,int committee_size,double**committee,double*candidate,int radius){
draw_square(file,1,0,0,0,0,radius);
for(int i= 0;i<committee_size;++i){
draw_square(file,0.2,0,1,committee[i][1]*radius,committee[i][2]*radius,
p_dist(committee[i],candidate)*radius);
}
for(int i= 0;i<committee_size;++i){

plot_single_point(file,0,0,0,committee[i][1]*radius,committee[i][2]*radius);
}
plot_single_point(file,0,1,0,candidate[1]*radius,candidate[2]*radius);
draw_square(file,1,1,1,2*radius,0,radius);
draw_square(file,1,1,1,0,2*radius,radius);
draw_square(file,1,1,1,2*radius,2*radius,radius);
}

/*:22*/
#line 397 "./lp-balls.w"
;
/*23:*/
#line 433 "./lp-balls.w"

void random_locus(int committee_size,const char*filename,int radius,int num_pages){
double*candidate= malloc((d+1)*sizeof(double));
double**committee= malloc(committee_size*sizeof(double*));
for(int i= 0;i<committee_size;++i)committee[i]= malloc((d+1)*sizeof(double));

if(d!=2){
printf("I cannot output PostScript unless d equals 2!\n");
return;
}
FILE*file= fopen(filename,"w");
/*13:*/
#line 255 "./lp-balls.w"

char*preamble= "%!PS\n\
/dot { 1.5 0 360 arc closepath fill } def\n\
/square { /r exch def /y exch def /x exch def\n\
newpath x r sub y r sub moveto 0 r 2 mul rlineto\n\
r 2 mul 0 rlineto 0 r 2 mul neg rlineto\n\
r 2 mul neg 0 rlineto closepath fill} def\n\
0.5 setlinewidth\n";
fprintf(file,"%s",preamble);
fprintf(file,"%d %d translate\n",radius,radius);
fprintf(file,"newpath 0 %d moveto 0 %d lineto ",-radius,radius);
fprintf(file,"%d 0 moveto %d 0 lineto stroke\n",-radius,radius);

/*:13*/
#line 444 "./lp-balls.w"
;
for(int page= 0;page<num_pages;++page){
for(int i= 0;i<committee_size;++i)random_point(committee[i]);
random_point(candidate);
if(page!=0)fprintf(file,"%d %d translate\n",radius,radius);
draw_locus(file,committee_size,committee,candidate,radius);
fprintf(file,"showpage\n");
}
fclose(file);

free(candidate);
for(int i= 0;i<committee_size;++i)free(committee[i]);
}

/*:23*/
#line 398 "./lp-balls.w"
;

/*:20*/
#line 52 "./lp-balls.w"
;
int main(int argc,char*argv[]){
/*24:*/
#line 464 "./lp-balls.w"

p= 2.0;
d= 2;
max_points= 300;
num_points= 0;
if(argc>=2){
p= atof(argv[1]);
p_inv= 1.0/p;
}
if(argc>=3){
d= atoi(argv[2]);
if(d<0){
printf("I expect d to be >= 0.\n");
return 1;
}
}
if(argc>=4){
max_points= atoi(argv[3]);
if(max_points<10){
printf("I expect max_points to be >= 0.\n");
return 1;
}
}
points= malloc(max_points*sizeof(double*));
for(int i= 0;i<max_points;++i)points[i]= malloc((d+1)*sizeof(double));
printf("Program started with p = %f, d = %d, and max_points = %d\n",p,d,max_points);

/*:24*/
#line 54 "./lp-balls.w"
;
/*5:*/
#line 106 "./lp-balls.w"

time_t t;
srand((unsigned)time(&t));
for(int i= 0;i<10;++i){
rand();
}

/*:5*/
#line 55 "./lp-balls.w"
;

if(d==2&&p<0)random_locus(5,"locus.ps",150,30);
}

/*:2*/
