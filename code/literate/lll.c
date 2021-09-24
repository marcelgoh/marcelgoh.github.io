#define DIM 3
#define INPUT_BASIS { \
{15.0,23.0,11.0}, \
{46.0,15.0,3.0}, \
{32.0,1.0,1.0} \
}
#define INPUT_QUAD { \
{1.0,0.0,0.0}, \
{0.0,1.0,0.0}, \
{0.0,0.0,1.0} \
} \

/*2:*/
#line 52 "./lll.w"

#include <float.h> 
#include <math.h> 
#include <stdio.h> 
#include <stdlib.h> 

int n;
double bb[DIM+1][DIM+1],Q[DIM+1][DIM+1];

/*3:*/
#line 86 "./lll.w"

void set(double z[n],double x[n]){
for(int i= 1;i<=n;++i){
z[i]= x[i];
}
}
void add(double z[n],double x[n],double y[n]){
for(int i= 1;i<=n;++i){
z[i]= x[i]+y[i];
}
}
void sub(double z[n],double x[n],double y[n]){
for(int i= 1;i<=n;++i){
z[i]= x[i]-y[i];
}
}
void scale(double z[n],double lambda,double x[n]){
for(int i= 1;i<=n;++i){
z[i]= lambda*x[i];
}
}

void set_i(int z[n],int x[n])
{
for(int i= 1;i<=n;++i){
z[i]= x[i];
}
}
void add_i(int z[n],int x[n],int y[n]){
for(int i= 1;i<=n;++i){
z[i]= x[i]+y[i];
}
}
void sub_i(int z[n],int x[n],int y[n]){
for(int i= 1;i<=n;++i){
z[i]= x[i]-y[i];
}
}
void scale_i(int z[n],int lambda,int x[n]){
for(int i= 1;i<=n;++i){
z[i]= lambda*x[i];
}
}

double dot(double x[n],double y[n]){
double sum= 0;
for(int i= 1;i<=n;++i){
sum+= x[i]*y[i];
}
return sum;
}
double b(double x[n],double y[n]){
double sum= 0;
for(int i= 1;i<=n;++i){
sum+= dot(Q[i],x)*y[i];
}
return sum;
}
double q(double x[n]){
return b(x,x);
}

/*:3*/
#line 61 "./lll.w"
;
/*4:*/
#line 168 "./lll.w"

int**lll(double bb[n+1][n+1]){
int k,k_max,l;
int**H= malloc((n+1)*sizeof(int*));
double mu[n+1][n+1];
double bb_star[n+1][n+1];
double B[n+1];
double temp[n+1],tempb[n+1];
int temp_i[n+1];
/*5:*/
#line 203 "./lll.w"

for(int i= 1;i<=n;++i){
H[i]= malloc((n+1)*sizeof(int));
B[i]= 0;
for(int j= 1;j<=n;++j){
H[i][j]= (i==j)?1:0;
mu[i][j]= bb_star[i][j]= 0.0;
}
}
k= 2;
k_max= 1;
set(bb_star[1],bb[1]);
B[1]= q(bb_star[1]);

/*:5*/
#line 177 "./lll.w"
;
int num_loops= 0;
do{
if(k> k_max){
/*6:*/
#line 223 "./lll.w"

k_max= k;
set(bb_star[k],bb[k]);
for(int j= 1;j<k;++j){
mu[k][j]= b(bb[k],bb_star[j])/B[j];
scale(temp,mu[k][j],bb_star[j]);
sub(bb_star[k],bb_star[k],temp);
}
B[k]= b(bb_star[k],bb_star[k]);
if(B[k]<DBL_EPSILON){
printf("ERROR: The input vectors do not form a basis.\n");
return NULL;
}

/*:6*/
#line 181 "./lll.w"
;
}
l= k-1;
/*7:*/
#line 242 "./lll.w"

if(fabs(mu[k][l])> 0.5){
int rounded= (int)floor((0.5+mu[k][l]));
scale(temp,rounded,bb[l]);
sub(bb[k],bb[k],temp);
scale_i(temp_i,rounded,H[l]);
sub_i(H[k],H[k],temp_i);
mu[k][l]= mu[k][l]-rounded;
for(int i= 1;i<l;++i){
mu[k][i]= mu[k][i]-rounded*mu[l][i];
}
}

/*:7*/
#line 184 "./lll.w"
;
if(/*8:*/
#line 264 "./lll.w"

B[k]>=(0.75-mu[k][k-1]*mu[k][k-1])*B[k-1]

/*:8*/
#line 185 "./lll.w"
){
for(l= k-2;l> 0;--l){
/*7:*/
#line 242 "./lll.w"

if(fabs(mu[k][l])> 0.5){
int rounded= (int)floor((0.5+mu[k][l]));
scale(temp,rounded,bb[l]);
sub(bb[k],bb[k],temp);
scale_i(temp_i,rounded,H[l]);
sub_i(H[k],H[k],temp_i);
mu[k][l]= mu[k][l]-rounded;
for(int i= 1;i<l;++i){
mu[k][i]= mu[k][i]-rounded*mu[l][i];
}
}

/*:7*/
#line 187 "./lll.w"
;
}
++k;
}else{
/*9:*/
#line 270 "./lll.w"

set(temp,bb[k]);
set(bb[k],bb[k-1]);
set(bb[k-1],temp);
set_i(temp_i,H[k]);
set_i(H[k],H[k-1]);
set_i(H[k-1],temp_i);
double t,m;
if(k> 2){
for(int j= 1;j<=k-2;++j){
t= mu[k][j];
mu[k][j]= mu[k-1][j];
mu[k-1][j]= t;
}
}
m= mu[k][k-1];
t= B[k]+m*m*B[k-1];
mu[k][k-1]= m*B[k-1]/t;
set(tempb,bb_star[k-1]);
scale(temp,m,tempb);
add(bb_star[k-1],bb_star[k],temp);
scale(tempb,B[k]/t,tempb);
scale(temp,-1.0*mu[k][k-1],bb_star[k]);
add(bb_star[k],temp,tempb);
B[k]= B[k-1]*B[k]/t;
B[k-1]= t;
for(int i= k+1;i<=k_max;++i){
t= mu[i][k];
mu[i][k]= mu[i][k-1]-m*t;
mu[i][k-1]= t+mu[k][k-1]*mu[i][k];
}

/*:9*/
#line 191 "./lll.w"
;
k= (2> k-1)?2:k-1;
continue;
}
}while(k<=n);
return H;
}

/*:4*/
#line 62 "./lll.w"
;

int main(){
n= DIM;
/*11:*/
#line 305 "./lll.w"

double input_lattice[DIM][DIM]= INPUT_BASIS;
double input_quad[DIM][DIM]= INPUT_QUAD;
for(int i= 0;i<n;++i){
for(int j= 0;j<n;++j){
bb[i+1][j+1]= input_lattice[i][j];
Q[i+1][j+1]= input_quad[i][j];
}
}
printf("Input lattice basis:\n");
/*13:*/
#line 328 "./lll.w"

for(int i= 1;i<=n;++i){
printf("(");
for(int j= 1;j<=n;++j){
printf("%f",(bb[i][j]));
if(j!=n)printf(", ");
}
printf(")\n");
}

/*:13*/
#line 315 "./lll.w"
;
printf("Input Q matrix:\n");
for(int j= 1;j<=n;++j){
for(int i= 1;i<=n;++i){
printf("%f ",(Q[i][j]));
}
printf("\n");
}

/*:11*/
#line 66 "./lll.w"
;
int**H;
H= lll(bb);
if(H!=NULL){
/*12:*/
#line 324 "./lll.w"

printf("Reduced basis:\n");
/*13:*/
#line 328 "./lll.w"

for(int i= 1;i<=n;++i){
printf("(");
for(int j= 1;j<=n;++j){
printf("%f",(bb[i][j]));
if(j!=n)printf(", ");
}
printf(")\n");
}

/*:13*/
#line 326 "./lll.w"
;

/*:12*/
#line 70 "./lll.w"
;
/*14:*/
#line 340 "./lll.w"

printf("H matrix:\n");
for(int j= 1;j<=n;++j){
for(int i= 1;i<=n;++i){
printf("%d ",(H[i][j]));
}
printf("\n");
}

/*:14*/
#line 71 "./lll.w"
;

return 0;
}else{
return 1;
}
}

/*:2*/
