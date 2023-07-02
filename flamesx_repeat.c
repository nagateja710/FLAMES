#include<stdio.h>
#include<string.h>

void repeat();
int test(char a[],char b[]);
void flames(char a[],int m,int *g);
void flames2(char a[],int m,int *g);
void result(char a[],char b[],int r);
void result2(char a[],char b[],int r);


int main ()
{   int z=0;
    repeat();
    return 0;
}

void repeat() {
    int q;
    int m=0,n,g=6;
    char a[30];
    char b[30];
    char e[30],f[30],x,y;
    char c[6]="FLAMES";
    char d[6]="FLAMES";
    //char d[6]="FLAMES";
    printf("enter Your name : ");
    scanf("%s",a);
    printf("enter your friends name : ");
    scanf("%s",b);

    strcpy(e,a);
    strcpy(f,b);
    n=test(&a,&b);
//printf("n=%d\n",n); // >>check1
    for(int I=0; I<5; I++) {
        flames(&c,n,&g);
        g++;
        flames2(&d,n,&g);
    }
    x=c[0];
    y=d[0];
    //printf("x=%c,y=%c\n\n",x,y);//check4
    if((x=='E' && y=='F') ||(x=='F' && y=='E')||(x=='L' && y=='S')||(x=='M' && y=='S') ||(y=='M' && x=='S'))
    {   y='0';
        x='z';
    }
    else if(x==y)
        y='0';
    printf("\n\n");
    result(&e,&f,x);
    result2(&e,&f,y);
    
    printf("\npress 1 to test again ");
    scanf("%d",&q);
   if(q==1)repeat();
   else return;
}

int test(char a[],char b[]) {
    int I,j,n=0;
    for(I=0; a[I]!='\0'; I++) {
        for(j=0; b[j]!='\0'; j++) {
            if(a[I]==b[j]) {
                a[I]='#';
                b[j]='#';
            }
        }
    }
    strcat(a,b);
    for(I=0; a[I]!='\0'; I++) {
        if(a[I]=='#')
            n++;
    }
    //printf("a=%s\n",a); // check3
    return strlen(a)-n;
}

void flames(char a[],int m,int *g) {
    int I,z=m%*g,u=0,temp;

    if(z==0) {
        *g=*g-1;
        a[*g]='\0';
        //printf("%s\n",a); // check21
        return;
        
    }
    for(I=0; I<*g; I++) {
        if(I>=z-1)
            a[I]=a[I+1];
        
    }
    *g=*g-1;
    while(u<z-1) {
        temp=a[0];
        for(I=0; I<*g; I++) {
            a[I]=a[I+1];
        }
        a[*g-1]=temp;
        u++;
    }
//printf("%s\n",a); //check22
}
void flames2(char a[],int m,int *g) {
    int I,z=m%*g,u=0,temp;

    if(z==0) {
        *g=*g-1;
        a[*g]='\0';
        //printf("%s\n",a); // check21
        return;
        
    }
    for(I=0; I<*g; I++) {
        if(I>=z-1)
            a[I]=a[I+1];
        
    }
    *g=*g-1;
    //printf("%s\n",a); //check22
    
}
void result(char a[],char b[],int r) {
printf("*****\n");
    switch (r) {
    case 'F':
        printf("%s and %s are FRIENDS",a,b);
        break;
    case 'L':
        printf("%s and %s are LOVERS",a,b);
        break;
    case 'A':
        printf("%s and %s have AFFECTION",a,b);
        break;
    case 'M':
        printf("%s and %s will MARRY",a,b);
        break;
    case 'E':
        printf("%s and %s are ENIMIES",a,b);
        break;
    case 'S':
        printf("%s and %s are SIBLINGS",a,b);
        break;
    case 'z':
        printf("%s and %s are STRANGERS",a,b);
        break;
    }

}

void result2(char a[],char b[],int r) {

    switch (r) {
    case 'F':
        printf(" and \nalso have FRIENDSHIP");
        break;
    case 'L':
        printf(" and \nalso have LOVE");
        break;
    case 'A':
        printf(" and \nhave AFFECTION");
        break;
    case 'M':
        printf(" and \nwill also MARRY");
        break;
    case 'E':
        printf(" and \nENIMIES");
        break;
    case 'S':
        printf(" and \nare SIBLINGS");
        break;
    }
    printf("\n*****");

}
