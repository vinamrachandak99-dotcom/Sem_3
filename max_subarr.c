#include<stdio.h>
#include<stdlib.h>

typedef struct 
{
    int sum,start,end;
} re;


re max_crossing(int a[],int l,int h,int m,int lim ){
    int sum=0,left_S=-1,right_S=-1;
    int m_l=m,m_r=m+1;


    /*left side of array*/
    for (int i = 0; i < m; i++)
    {
        sum+=a[i];
        if(sum<=lim && sum>left_S){
            left_S=sum;
            m_l=i;
        }
    }
    sum=0;
    /*Right side of array*/
    for (int i = m+1; i<=h; i++)
    {
        sum+=a[i];
        if(sum<=lim && sum>right_S){
            right_S=sum;
            m_r=i;
        }
    }

    re s={left_S+right_S,m_l,m_r};
    if(s.sum>lim) s.sum=-1;
    return s;
}

re max_subarr(int a[],int l,int h,int lim){
    if(l==h){
        if(a[l]<=lim) return (re){a[1],1,1};
        else return(re){-1,-1,-1};
    }
    int m=(l+m/2);
    
}
